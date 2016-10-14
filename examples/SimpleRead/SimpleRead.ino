#include "Arduino.h"
#include "DFRobotURM07.h"

DFRobotURM07 urm07;

#define URM07_DEFAULT_ADDRESS 0x11

// Add setup code
void setup()
{
  Serial.begin(19200);
  urm07.begin(Serial);
}

// Add loop code
void loop()
{
  urm07.readDistance(URM07_DEFAULT_ADDRESS);
  urm07.readTemperature(URM07_DEFAULT_ADDRESS);
  delay(1000);
}
