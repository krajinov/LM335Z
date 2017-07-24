/*
  LM335Z - Library for using a LM335Z temperature sensor.
  
  Created by Josip Krajinovic, July 24, 2017.
  Released into the public domain.
  
 */
 
#ifndef LM335Z_h
#define LM335Z_h

#include "Arduino.h"

class LM335Z
{
  private:
    const float tempCoef = 0.010106;
    float cal;
    int pin;
  public:
    LM335Z(float mCal, int mPin);
    float measureV();
    float measureK();
    float measureC();
    float measureF();
    float measureRankine();
};

#endif

