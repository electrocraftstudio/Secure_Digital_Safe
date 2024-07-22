# Secure_Digital_Safe

## Overview
The Secure Digital Safe project is an Arduino-based digital safe that uses a keypad to enter a password. It has a red LED to indicate incorrect passwords and a green LED to indicate correct passwords. A buzzer is used for sound notifications, and an LCD screen displays messages to the user.

## Required Components
- Arduino Uno
- 4x4 Keypad
- LiquidCrystal_I2C LCD (16x2)
- Red LED
- Green LED
- Buzzer
- 220Ω Resistors (x2)
- Breadboard and Jumper Wires

## Libraries to Install
To run this project, you need to install three libraries in the Arduino IDE:

1. **Wire.h**: This library is used for I2C communication. It usually comes pre-installed with the Arduino IDE.
2. **LiquidCrystal_I2C.h**: This library allows you to control an LCD screen with the I2C interface.
3. **Keypad.h**: This library is used to interface with a keypad.

### Steps to Install Libraries
1. Open the Arduino IDE.
2. Go to `Sketch` > `Include Library` > `Manage Libraries...`.
3. In the Library Manager, type the name of the library you need (e.g., `LiquidCrystal_I2C` or `Keypad`) in the search bar.
4. Find the library in the list and click `Install`.

Repeat these steps for each library.

## Wiring Connections
### Keypad:
- **Row Pins**:
  - R1 -> Pin 9
  - R2 -> Pin 8
  - R3 -> Pin 7
  - R4 -> Pin 6
- **Column Pins**:
  - C1 -> Pin 5
  - C2 -> Pin 4
  - C3 -> Pin 3
  - C4 -> Pin 2

### LEDs:
- **Red LED**: Anode -> 220Ω resistor -> Pin 10, Cathode -> GND
- **Green LED**: Anode -> 220Ω resistor -> Pin 11, Cathode -> GND

### Buzzer:
- **Positive Leg** -> Pin 12
- **Negative Leg** -> GND

### LCD I2C:
- **SDA** -> A4
- **SCL** -> A5
- **GND** -> GND
- **VCC** -> 5V

## Steps to Upload the Code
1. Install the required libraries in the Arduino IDE (`Wire.h`, `LiquidCrystal_I2C.h`, `Keypad.h`).
2. Connect the components as per the wiring connections.
3. Open the Arduino IDE and paste the provided code.
4. Connect the Arduino Uno to your computer via USB.
5. Select the correct board and port in the Arduino IDE.
6. Upload the code to the Arduino Uno.

## Project Setup
1. Connect all the components to the Arduino Uno as per the wiring connections.
2. Ensure all connections are secure and correct.
3. Power up the Arduino Uno by connecting it to the computer or a power source.

## Testing the Project
1. After uploading the code, the LCD should display "Enter the code:".
2. Enter the correct password (`1212` by default) using the keypad.
3. If the password is correct, the green LED will light up, and the LCD will display "Access Granted".
4. If the password is incorrect, the red LED will light up, the buzzer will sound, and the LCD will display "Access Denied".

## Troubleshooting
- **No display on LCD**: Check the I2C connections and ensure the LCD address is correct.
- **Keypad not working**: Verify the keypad connections and ensure the pins are correctly mapped in the code.
- **LEDs not lighting up**: Check the connections and resistors for the LEDs.
- **Buzzer not sounding**: Ensure the buzzer is connected correctly and the pin is defined properly in the code.
