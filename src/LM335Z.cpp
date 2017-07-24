/*
  LM335Z - Library for using a LM335Z temperature sensor.
  
  Created by Josip Krajinovic, July 24, 2017.
  Released into the public domain.
  
 */

#include "LM335Z.h"

LM335Z::LM335Z(float mCal, int mPin)
{
  cal = mCal;
  pin = mPin;
}
float LM335Z::measureV()
{
  float uzorakTem = 0;
  float retVal;
  for (int i = 0; i < 50; i++) {
    uzorakTem += (float) analogRead(pin);
    delayMicroseconds(1);
  }
  retVal = uzorakTem / 50;
  retVal = (retVal * cal) / 1024.0;
  return retVal;
}
float LM335Z::measureK()
{
  return measureV() / tempCoef; //10mV/k
}
float LM335Z::measureC()
{
  return (measureV() / tempCoef) - 273.15;
}
float LM335Z::measureF()
{
  return (((measureV() / tempCoef) - 273.15) * 1.8) + 32;
}
float LM335Z::measureRankine()
{
  return measureF() + 458.67;
}