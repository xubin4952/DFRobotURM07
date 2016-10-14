/*!
 * @file DFRobotRomeoBLEMini.h
 * @brief DFRobot's Romeo BLE mini - Arduino with Motor Driver and Bluetooth 4.0 (SKU:DFR0351)
 * @n CPP file for DFRobot's Romeo BLE mini
 * @n [Schematics](https://raw.githubusercontent.com/CainZ/Romeo-BLE-mini/master/Romeo%20BLE%20mini%20V1.1%20Schematics%20.pdf)
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @author [Angelo](Angelo.qiao@dfrobot.com)
 * @version  V1.0
 * @date  2016-01-27
 */
#include "Arduino.h"

#define ReceivedCommandStackLength 10
#define SendingCommandStackLength 10

#ifndef DFRobotURM07_cpp
    #define DFRobotURM07_cpp

class DFRobotURM07 {
  
  static boolean _isBusy;  //whether the serial is busy
  
  Stream* _serial;
  
  byte receivedCommandStack[ReceivedCommandStackLength];
  byte sendingCommandStack[SendingCommandStackLength];
  
  byte receivedCommandStackIndex;
  //  boolean isReceiving;
  
  void sendStack();
  void parseStack();
  boolean validateStack();
  
  
  public:
  DFRobotURM07();
  
  enum DataType {
    TimeOut,
    Distance,
    Temperature,
    Baudrate,
    Address,
    WrongStack
  } dataType;
  
  
  /**
   The Stream class can accept not only hardware serial but also software serial

   @param theSerial The port use to communicate.
   */
  void begin(Stream& theSerial);
  
  
  /**
   Read distance in blocking mode;

   @param address The address of the devide.

   @return the distance value
   */
  int readDistance(int address);
  /**
   Read temperature in blocking mode;

   @param address The address of the devide.

   @return the temperature in Celsius degree
   */
  float readTemperature(int address);
  
  
  /**
   Set a new address for a device

   @param address The new address

   @return Whether it is set successfully.
   */
  boolean writeAddress(int address);
  
  /**
   Set a new baud rate for a device

   @param baudRate The baud rate ie: 9600, 115200 and etc.

   @return Whether it is set successfully.
   */
  boolean writeBaudRate(unsigned long baudRate);
  
  
  /**
   Request distance in non-blocking mode

   @param address The address of the devide.

   @return Whether it runs successfully (will return false if other serial communication is in progress).
   */
  boolean requestDistance(int address);
  
  /**
   Request temperature in non-blocking mode

   @param address The address of the devide.

   @return Whether it runs successfully (will return false if other serial communication is progress).
   */
  boolean requestTemperature(int address);
  
  
  /**
   Used to check whether there are some replies from device.

   @return the checking result.
   */
  boolean available();
  
  
  /**
   Check the received type of the data (Distance, Temperature, ErrorStack, Timeout, BaudRate reply)

   @return The type of the data
   */
  DataType readType();

  
  /**
   Read data in available()

   @return The data which can be Distance, Temperature, ErrorStack, Timeout, BaudRate reply and etc.
   */
  float read();
  
  
  /**
   Read the address of device

   @return The address.
   */
  int readAddress();
};

#endif
