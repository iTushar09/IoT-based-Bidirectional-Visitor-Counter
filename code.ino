#include <LiquidCrystal.h>  // Library for LCD control

// Pin definitions
const int ledPin = 13;      // LED for system status
const int entrySensor = 7;  // Entry sensor pin
const int exitSensor = 8;   // Exit sensor pin

int peopleCount = 0;        // Tracks number of people inside

// Set up LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  //Pin mode
  pinMode(ledPin, OUTPUT);          // Set LED pin as OUTPUT
  pinMode(entrySensor, INPUT);      // Set entry sensor as INPUT
  pinMode(exitSensor, INPUT);       // Set exit sensor as INPUT

 // LCD initialization
  lcd.begin(16, 2);                 // Initialize LCD (16x2)

// Welcome message
  lcd.print("WELCOME TO MY");       // Welcome message (line 1)
  lcd.setCursor(0, 1);              // Move to second row [Row index starts at 0, so second row is (0,1)]
  lcd.print("PEOPLE COUNTER");      // Welcome message (line 2)
  delay(3000);                      // Show message (3 seconds)
  lcd.clear();                      // Clear LCD
}

void loop() {
  // ========================================================//
  // If a person enters (entrySensor triggered)
  // ========================================================//
  if (digitalRead(entrySensor) == HIGH) {
    peopleCount++;                    // Increase count
    showCount("Entered");             // Show on LCD
    digitalWrite(ledPin, LOW);        // LED OFF during change
    delay(1000);                      // Wait to avoid repeat counting
    lcd.clear();                      // Clear LCD for next event
  }
  
  // ========================================================//
  // If a person exits (exitSensor triggered)
  // ========================================================//
  
  if (digitalRead(exitSensor) == HIGH) {
    if (peopleCount > 0) {            // Prevent negative count
      peopleCount--;
    }
    showCount("Exited");              // Show on LCD
    digitalWrite(ledPin, LOW);        // LED OFF during change
    delay(1000);
    lcd.clear();
  }
  
  // ========================================================//
  // If sensors are idle, show current count (no one detected)
  // ========================================================//
  
  if (digitalRead(entrySensor) == LOW && digitalRead(exitSensor) == LOW) {
    lcd.setCursor(0, 0);
    lcd.print("Current People:");
    lcd.setCursor(0, 1);
    lcd.print(peopleCount);
    lcd.print("   ");                 // Clear old digits if needed
    digitalWrite(ledPin, HIGH);       // LED ON when idle
  }

  delay(100);                         // Loop pause or Small delay for stability
}

// ========================================================//
// Helper function to show entry/exit events on LCD
// ========================================================//

void showCount(const char* action) {
  lcd.setCursor(0, 0);
  lcd.print(action);
  lcd.print(" Person");
  
  lcd.setCursor(0, 1);
  lcd.print("Count: ");
  lcd.print(peopleCount);

  digitalWrite(ledPin, LOW);         // LED OFF during events
}
