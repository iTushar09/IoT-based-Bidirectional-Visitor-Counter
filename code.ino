#include <LiquidCrystal.h>

const int led = 13;
const int inr = 7;  // Input sensor for people entering
const int outr = 8; // Output sensor for people exiting
int ppl = 0;        // Current number of people

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(led, OUTPUT);
  pinMode(inr, INPUT);
  pinMode(outr, INPUT);
  lcd.begin(16, 2);
  lcd.print("People Counter"); // Initial display
  delay(1000);
  lcd.clear();
}

void loop() {
  // Check if someone is entering
  if (digitalRead(inr) == HIGH) { // Assuming HIGH when detected
    ppl++;
    lcd.setCursor(0, 0);
    lcd.print("ENTER PEOPLE  "); // Spaces to clear previous text
    lcd.setCursor(0, 1);
    lcd.print("Count: ");
    lcd.print(ppl);
    digitalWrite(led, LOW); // Turn LED off when someone enters
    delay(1000); // Small delay to avoid multiple counts
    lcd.clear();
  }

  // Check if someone is exiting
  if (digitalRead(outr) == HIGH) { // Assuming HIGH when detected
    if (ppl > 0) { // Ensure people count doesn't go negative
      ppl--;
    }
    lcd.setCursor(0, 0);
    lcd.print("EXIT PEOPLE   "); // Spaces to clear previous text
    lcd.setCursor(0, 1);
    lcd.print("Count: ");
    lcd.print(ppl);
    digitalWrite(led, LOW); // Turn LED off when someone exits
    delay(1000); // Small delay to avoid multiple counts
    lcd.clear();
  }

  // Default display when no one is entering or exiting
  if (digitalRead(inr) == LOW && digitalRead(outr) == LOW) {
    lcd.setCursor(0, 0);
    lcd.print("Current People:");
    lcd.setCursor(0, 1);
    lcd.print(ppl);
    lcd.print("          "); // Clear remaining characters
    digitalWrite(led, HIGH); // Turn LED on when idle
  }

  delay(100); // A small delay to keep the loop from running too fast
}