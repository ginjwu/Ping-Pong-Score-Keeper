
// Code for reading
#include <Wire.h>
#include "I2C_Anything.h"
#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
double volumeA;
double volumeB;

/*
void setup() {
    lcd.begin(16, 2);
}

void loop() {
    char buffer[12];

    Serial.print("Why is this not working?");

    if (Serial.available()) {
        Serial.readBytes(buffer, 13);
      
        Serial.print(buffer);
        lcd.print(buffer);
    }
}
*/
// char str[4];

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  // lcd.print("Hello world!");
}

void loop() {
  lcd.print("Hello0");
  Wire.requestFrom(8, 8);
  int i=0;
  // lcd.print("world");
  // lcd.setCursor(0, 0);
  lcd.print("Hello ");
  while (Wire.available()) {
    I2C_readAnything(volumeA);
    lcd.print(volumeA);
    // lcd.print("Working?");
    Serial.print(volumeA);
  }
  lcd.print("World");

  delay(500);

  Wire.requestFrom(7, 8);
  // lcd.setCursor(0, 12);
  while (Wire.available()) {
    I2C_readAnything(volumeB);
    lcd.print(volumeB);
    Serial.print(volumeB);
  }

  delay(500);

  
  /*
  if (Serial.available()) {
    delay(100); //allows all serial sent to be received together
    while(Serial.available() && i<4) {
      str[i++] = Serial.read();
    }
    str[i++]='\0';
  }

  if(i>0) {
    lcd.print(str);
    Serial.println(str);
  }
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 1);
  // Serial.println("Something's not right");
  */
}
