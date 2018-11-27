// Credit goes to Nick Gammon for writing these functions. 
#include <Arduino.h>
#include <Wire.h>

template <typename T> unsigned int I2C_writeAnything (const T& value) {
    Wire.write((byte *) &value, sizeof (value));
    return sizeof (value);
}  

template <typename T> unsigned int I2C_readAnything(T& value) {
    byte * p = (byte*) &value;
    unsigned int i;
    for (i = 0; i < sizeof value; i++)
          *p++ = Wire.read();
    return i;
} 

// Function to measure sound levels
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
   peakToPeak = signalMax - signalMin;
   return peakToPeak * 5.0 / 1024;
   
}
