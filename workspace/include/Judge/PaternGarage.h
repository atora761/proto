#pragma once
enum GarageColor
{
  YELLOWTHRESHOL,
  REDTHRESHOLD ,
  GREENTHRESHOLD,
  BLUETHRESHOLD ,
};

#include <cstdint>
#include <string.h>
#include <memory>
#include <string>
#include "ev3api.h"
#include "system.h"
class PaternGarage //: public Comparison
{
private:
    RGB_DATA rgb;
public:
    PaternGarage();

    ~PaternGarage();

    int8 decide(); 
};
