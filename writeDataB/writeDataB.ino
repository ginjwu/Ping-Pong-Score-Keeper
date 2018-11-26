
/*
 void setup() {
    Serial.begin(9600);

}

void loop() {

    int bytesSent = Serial.write("hello world!");
    Serial.print(bytesSent);

*/

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
 
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;
 
  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow) {
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
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0 / 1024);  // convert to volts
   I2C_writeAnything(volts);
   
}

void setup() {
  Serial.begin(9600);
  Wire.begin(7);
  Wire.onRequest(requestEvent);
}

void loop() {
  delay(100);
  /*
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
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
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
   // valueToBeSent = (int) (100.0 * volts);
   
  /*
  int value=1234; //this would be much more exciting if it was a sensor value
  
  itoa(value, str, 10); //Turn value into a character array
  int bytesSent = Serial.write(str, 4);
  Serial.print("bytesSent: ");
  */
 
  /*
  itoa(valueToBeSent, str, 10);
  bytesSent = Serial.write(str);
  Serial.print(bytesSent);
  */

  
  

  
  
}
