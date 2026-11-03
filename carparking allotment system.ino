#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo gate;

#define ENTRY_IR 2
#define EXIT_IR 3
#define SERVO_PIN 9

int slots = 4;

bool entryDetected = false;
bool exitDetected = false;

void setup() {
  pinMode(ENTRY_IR, INPUT);
  pinMode(EXIT_IR, INPUT);

  gate.attach(SERVO_PIN);

  gate.write(0); // Gate Closed

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Parking");
  delay(2000);

  updateDisplay();
}

void loop() {

  // ENTRY
  if (digitalRead(ENTRY_IR) == LOW && !entryDetected) {

    entryDetected = true;

    if (slots > 0) {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Car Entering");

      gate.write(90);      // Open Gate
      delay(3000);

      gate.write(0);       // Close Gate
      slots--;

      updateDisplay();

    } else {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Parking Full");
      lcd.setCursor(0, 1);
      lcd.print("No Entry");

      delay(2000);
      updateDisplay();
    }
  }

  if (digitalRead(ENTRY_IR) == HIGH) {
    entryDetected = false;
  }

  // EXIT
  if (digitalRead(EXIT_IR) == LOW && !exitDetected) {

    exitDetected = true;

    if (slots < 4) {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Car Exiting");

      gate.write(90);      // Open Gate
      delay(3000);

      gate.write(0);       // Close Gate
      slots++;

      updateDisplay();
    }
  }

  if (digitalRead(EXIT_IR) == HIGH) {
    exitDetected = false;
  }
}

void updateDisplay() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Available:");

  lcd.setCursor(11, 0);
  lcd.print(slots);

  lcd.setCursor(0, 1);

  if (slots == 0)
    lcd.print("Parking Full");
  else
    lcd.print("Welcome");
}