#pragma once
#include "../../include/Judge/UseJudgement.h"
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

class PaternGarage : public UseJudgement {

private:
    RGB_DATA rgb;
public:
    PaternGarage();

    ~PaternGarage();

    int8_t decide(); 

};
