import os

import serial
from flask import Flask, Response, abort, render_template
from serial import SerialException


SERIAL_PORT = os.getenv("SERIAL_PORT", "/dev/ttyACM0")
BAUD_RATE = int(os.getenv("BAUD_RATE", "9600"))
SERIAL_TIMEOUT = float(os.getenv("SERIAL_TIMEOUT", "1"))

app = Flask(__name__)


def open_serial_connection():
    try:
        return serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=SERIAL_TIMEOUT)
    except SerialException:
        return None


arduino = open_serial_connection()


def send_command(command):
    if arduino is None or not arduino.is_open:
        raise SerialException(f"Serial port {SERIAL_PORT} is unavailable")

    arduino.write(f"{command}\n".encode("utf-8"))


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/servo/<int:servo_id>/<int:position>", methods=["GET"])
def control_servo_route(servo_id, position):
    if not 1 <= servo_id <= 6:
        abort(400, "Servo ID must be in range 1-6")

    if not 0 <= position <= 180:
        abort(400, "Servo position must be in range 0-180")

    try:
        send_command(f"SERVO {servo_id} {position}")
    except SerialException as error:
        return Response(str(error), status=503)

    return Response(status=204)


@app.route("/led/<int:led_id>/<int:state>", methods=["GET"])
def control_led_route(led_id, state):
    if not 1 <= led_id <= 10:
        abort(400, "LED ID must be in range 1-10")

    if state not in (0, 1):
        abort(400, "LED state must be 0 or 1")

    try:
        send_command(f"LED {led_id} {state}")
    except SerialException as error:
        return Response(str(error), status=503)

    return Response(status=204)


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
