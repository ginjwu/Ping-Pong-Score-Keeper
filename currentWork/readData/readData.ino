#include "measureCommunicate.h"
#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
double volumeA;
double volumeB;
char c;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  // Wire.onReceive(receiveEvent)
  // lcd.print("Hello world!");
}

void loop() {
  // lcd.print("Hello0");
  Wire.requestFrom(8, 12);
  // lcd.print("world");
  // lcd.setCursor(0, 0);
  while (Wire.available()) {
    // c = Wire.read();
    // Serial.print(c);
    // lcd.print(c);
    I2C_readAnything(volumeA);
    lcd.print(volumeA);
    // lcd.print("Working?");
    Serial.print(volumeA);
    
  }
  lcd.print("World");

  delay(200);

  Wire.requestFrom(7, 12);
  while (Wire.available()) {
    c = Wire.read();
    Serial.print(c);
    lcd.print(c);
    I2C_readAnything(volumeB);
    lcd.print(volumeB);
    Serial.print(volumeB);
    
  }

  delay(200);
 
}
