// Project 3: IoT Soil Moisture Monitor
// Simulated on Wokwi | ESP32 + Potentiometer + LCD I2C

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- Pin definitions ---
#define MOISTURE_PIN 34

// --- LCD setup (address 0x27, 16 cols, 2 rows) ---
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- Thresholds ---
#define DRY_THRESHOLD  30    // below 30% = dry
#define WET_THRESHOLD  70    // above 70% = wet

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Soil Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Starting up...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read analog value (0-4095 on ESP32)
  int raw = analogRead(MOISTURE_PIN);

  // Convert to percentage (0-100%)
  int moisture = map(raw, 0, 4095, 0, 100);

  // Determine status
  String status;
  if (moisture < DRY_THRESHOLD) {
    status = "DRY";
  } else if (moisture > WET_THRESHOLD) {
    status = "WET";
  } else {
    status = "NORMAL";
  }

  // Print to Serial Monitor (Node-RED reads this)
  Serial.print("MOISTURE:");
  Serial.println(moisture);

  // Update LCD
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisture);
  lcd.print("%  ");

  lcd.setCursor(0, 1);
  lcd.print("Status: ");
  lcd.print(status);
  lcd.print("        ");

  delay(2000);
}
