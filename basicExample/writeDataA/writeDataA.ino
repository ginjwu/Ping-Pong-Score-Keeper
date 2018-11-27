#include <Wire.h>

void setup() {
  Wire.begin(7);                
  Wire.onRequest(requestEvent); 
}

void loop() {
  delay(100);
}

void requestEvent() {
   Wire.write("Hello ");
}
