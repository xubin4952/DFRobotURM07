#include "Arduino.h"
#include "DFRobotURM07.h"
#include "SoftwareSerial.h"

DFRobotURM07 urm07;
SoftwareSerial mySoftwareSerial(10,11);

#define URM07_DEFAULT_ADDRESS 0x11

// Add setup code
void setup()
{
  Serial.begin(19200);
  mySoftwareSerial.begin(19200);
  urm07.begin(mySoftwareSerial);
}

// Add loop code
void loop()
{
  static unsigned long requestDistanceTimer = millis();
  
  if (millis()-requestDistanceTimer>1000) {
    if (urm07.requestDistance(URM07_DEFAULT_ADDRESS)) {
      requestDistanceTimer = millis();
    }
  }
  
  static unsigned long requestTemperatureTimer = millis();
  
  if (millis()-requestTemperatureTimer>1000) {
    if (urm07.requestTemperature(URM07_DEFAULT_ADDRESS)) {
      requestTemperatureTimer = millis();
    }
  }
  
  if (urm07.available()) {
    Serial.print("Address:");
    Serial.println(urm07.readAddress());
    switch (urm07.readType()) {
      case urm07.Distance:
        int distance = urm07.read();
        Serial.print("Distance:");
        Serial.println(distance);
        break;
      case urm07.Temperature:
        float temperature = urm07.read();
        Serial.print("Temperature:");
        Serial.println(temperature);
        break;
      case urm07.TimeOut:
        Serial.println("Read timeOut");
        break;
      case urm07.WrongStack:
        Serial.println("Receice Wrong Stack");
        break;
      default:
        break;
    }
  }
}
