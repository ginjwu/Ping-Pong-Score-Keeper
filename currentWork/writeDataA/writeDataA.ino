
#include <Wire.h>

// Testing github
void setup() {
  Wire.begin(7);                
  Wire.onRequest(requestEvent); 
}

void loop() {
  delay(100);
}

void requestEvent() {
   double valueToSend = measureSoundLevel();
   // Serial.println(volts);
   // bytesSent = I2C_writeAnything(volts);
   //dtostrf(volts, 5, 3, str);
   // Serial.print("From slave A");
   Serial.print(str);
   int i = 0;
   Wire.write("Glycine");
   Serial.println("Glycine");
   
   // valueToBeSent = (int) (100.0 * volts);
}

void setup() {
    Serial.begin(9600);
    Wire.begin(8);
    Wire.onRequest(requestEvent);
}

void loop() {
    delay(500);
}
