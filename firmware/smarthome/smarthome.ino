#include <Servo.h>

const byte SERVO_COUNT = 6;
const byte LED_COUNT = 10;
const byte COOLER_COUNT = 4;
const int GAS_THRESHOLD = 330;

Servo servos[SERVO_COUNT];

const byte servoPins[SERVO_COUNT] = {8, 9, 10, 11, 12, 13};
const byte ledPins[LED_COUNT] = {22, 24, 26, 28, 30, 32, 34, 36, 38, 40};
const byte coolerPins[COOLER_COUNT] = {23, 25, 27, 29};
const byte gasSensorPins[COOLER_COUNT] = {A0, A1, A2, A3};

void setup() {
  Serial.begin(9600);

  for (byte index = 0; index < SERVO_COUNT; index++) {
    servos[index].attach(servoPins[index]);
    servos[index].write(0);
  }

  for (byte index = 0; index < LED_COUNT; index++) {
    pinMode(ledPins[index], OUTPUT);
    digitalWrite(ledPins[index], LOW);
  }

  for (byte index = 0; index < COOLER_COUNT; index++) {
    pinMode(coolerPins[index], OUTPUT);
    digitalWrite(coolerPins[index], LOW);
  }
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    handleCommand(command);
  }

  updateGasVentilation();
  delay(100);
}

void handleCommand(String command) {
  if (command.startsWith("SERVO")) {
    handleServoCommand(command);
    return;
  }

  if (command.startsWith("LED")) {
    handleLedCommand(command);
  }
}

void handleServoCommand(String command) {
  int firstSpace = command.indexOf(' ');
  int secondSpace = command.indexOf(' ', firstSpace + 1);

  if (firstSpace == -1 || secondSpace == -1) {
    return;
  }

  int servoId = command.substring(firstSpace + 1, secondSpace).toInt();
  int position = command.substring(secondSpace + 1).toInt();

  if (servoId >= 1 && servoId <= SERVO_COUNT && position >= 0 && position <= 180) {
    servos[servoId - 1].write(position);
  }
}

void handleLedCommand(String command) {
  int firstSpace = command.indexOf(' ');
  int secondSpace = command.indexOf(' ', firstSpace + 1);

  if (firstSpace == -1 || secondSpace == -1) {
    return;
  }

  int ledId = command.substring(firstSpace + 1, secondSpace).toInt();
  int state = command.substring(secondSpace + 1).toInt();

  if (ledId >= 1 && ledId <= LED_COUNT) {
    digitalWrite(ledPins[ledId - 1], state == 1 ? HIGH : LOW);
  }
}

void updateGasVentilation() {
  for (byte index = 0; index < COOLER_COUNT; index++) {
    int gasValue = analogRead(gasSensorPins[index]);
    digitalWrite(coolerPins[index], gasValue > GAS_THRESHOLD ? HIGH : LOW);
  }
}
