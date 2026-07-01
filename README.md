# SmartHome - fizyczna makieta inteligentnego domu

Repozytorium zawiera projekt inżynierski **"System inteligentnego domu na przykładzie fizycznej makiety w środowisku Arduino IDE"**. System łączy mikrokontroler Arduino Mega 2560, Raspberry Pi 3, aplikację webową Flask, serwomechanizmy, oświetlenie LED, czujniki gazu MQ-9 oraz wentylatory.

Projekt pokazuje działanie wybranych funkcji smart home na fizycznej makiecie: zdalne sterowanie bramami i drzwiami, sterowanie oświetleniem oraz automatyczne uruchamianie wentylacji po wykryciu gazu.

## Funkcje

- Zdalne sterowanie makietą przez panel WWW.
- Otwieranie i zamykanie 6 elementów za pomocą serwomechanizmów.
- Włączanie i wyłączanie 10 punktów oświetlenia LED.
- Detekcja gazu z 4 czujników MQ-9.
- Automatyczne sterowanie 4 wentylatorami po przekroczeniu progu odczytu z czujnika.
- Komunikacja Raspberry Pi z Arduino przez port szeregowy USB.

## Architektura

```text
Telefon / laptop
      |
      | HTTP
      v
Panel WWW Flask na Raspberry Pi
      |
      | USB serial: SERVO / LED
      v
Arduino Mega 2560
      |
      +-- serwomechanizmy
      +-- diody LED
      +-- czujniki MQ-9
      +-- wentylatory
```

## Struktura repozytorium

```text
.
├── app.py                         # Backend Flask i komunikacja po porcie szeregowym
├── templates/index.html           # Panel sterowania
├── firmware/smarthome/            # Program dla Arduino Mega 2560
├── hardware/kicad/SmartHome/      # Schematy KiCad
├── hardware/models/               # Model STL makiety
└── media/                         # Nagrania demonstracyjne
```

## Uruchomienie aplikacji

1. Wgraj program `firmware/smarthome/smarthome.ino` na Arduino Mega 2560 w Arduino IDE.
2. Podłącz Arduino do Raspberry Pi lub komputera przez USB.
3. Utwórz środowisko Python i zainstaluj zależności:

```powershell
python -m venv .venv
.\.venv\Scripts\Activate.ps1
pip install -r requirements.txt
```

4. Ustaw port szeregowy, jeśli różni się od domyślnego `/dev/ttyACM0`:

```powershell
$env:SERIAL_PORT = "COM3"
```

5. Uruchom aplikację:

```powershell
python app.py
```

Panel będzie dostępny pod adresem `http://localhost:5000`. Na Raspberry Pi w tej samej sieci można użyć adresu IP urządzenia, np. `http://192.168.1.20:5000`.

## Protokół komunikacji

Aplikacja Flask wysyła do Arduino proste komendy tekstowe zakończone znakiem nowej linii:

```text
SERVO <id> <pozycja>
LED <id> <stan>
```

Przykłady:

```text
SERVO 1 110
LED 3 1
LED 3 0
```

## Materiały projektowe

- Schematy KiCad znajdują się w `hardware/kicad/SmartHome`.
- Model STL makiety znajduje się w `hardware/models/STL_Smarthome.stl`.
- Nagranie `media/czujniki-gazu.mp4` pokazuje działanie czujników gazu.
- Nagranie `media/zdalne-sterowanie.mp4` pokazuje zdalne sterowanie makietą i jest przechowywane przez Git LFS.
