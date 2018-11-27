#include <Wire.h>

unsigned int measureSoundLevel() {
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
   unsigned sampleWindow = 50;
   unsigned int sample;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   
   return  5 * (signalMax - signalMin) / 8;
}
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
   // char valueToSend = (char) measureSoundLevel();
   Wire.write("world!"); // respond with message of 6 bytes
  // as expected by master
}



/*
/*
 void setup() {
    Serial.begin(9600);

}

void loop() {

    int bytesSent = Serial.write("hello world!");
    Serial.print(bytesSent);



#define SLAVE_ADDRESS 7

#include <Wire.h>
#include "I2C_Anything.h"

char str[4];
const int sampleWindow = 50;
int sample;
int valueToBeSent;
int bytesSent;

void requestEvent() {
  unsigned long startMillis= millis();  // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level
 
   
  // dtostrf(volts, 5, 3, str);
   Wire.write("Lycine");
   
}

void setup() {
  Serial.begin(9600);
  Wire.begin(7);
  Wire.onRequest(requestEvent);
}

void loop() {
  //delay(500);
  // int value=1234; //this would be much more exciting if it was a sensor value
  
  //itoa(value, str, 10); //Turn value into a character array
  // int bytesSent = Serial.write(str, 4);
  Serial.print("bytesSent: ");
 
  
  itoa(valueToBeSent, str, 10);
  bytesSent = Serial.write(str);
  Serial.print(bytesSent);
  

  
  

  
  
}
*/
