#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// LCD I2C settings
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 columns and 2 rows

// Keypad settings
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Keypad row pins
byte colPins[COLS] = {5, 4, 3, 2}; // Keypad column pins

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Password settings
String correctPassword = "Your Password";
String inputPassword = "";

// Pin settings
const int redLedPin = 10;
const int greenLedPin = 11;
const int buzzerPin = 12; // Buzzer pin

void setup() {
  lcd.init(); // Initialize the LCD
  lcd.backlight();
  
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600); // Initialize serial communication
  
  lcd.setCursor(0, 0);
  lcd.print("Enter the code:");
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    // Key press sound
    tone(buzzerPin, 1000, 100); // 1000 Hz sound for 100 ms
    
    if (key == '#') {
      lcd.clear();
      lcd.setCursor(0, 0);
      if (inputPassword == correctPassword) {
        lcd.print("Access Granted");
        digitalWrite(greenLedPin, HIGH);
        digitalWrite(redLedPin, LOW);
      } else {
        lcd.print("Access Denied");
        digitalWrite(greenLedPin, LOW);
        digitalWrite(redLedPin, HIGH);
        tone(buzzerPin, 1000, 1000); // Long sound for wrong password
        Serial.println("WRONG_PASSWORD"); // Send wrong password message
      }
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter the code:");
      inputPassword = "";
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, LOW);
    } else {
      inputPassword += key;
      lcd.setCursor(inputPassword.length() - 1, 1);
      lcd.print('*');
    }
  }
}
