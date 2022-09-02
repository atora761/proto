#pragma once
#define SLALOMPATERNA 1
#define SLALOMPATERNB 2

#include <cstdint>
//#include <cstring>
//#include <memory>
#include <string>
#include "ev3api.h"

#include "../../include/Judge/UseJudgement.h"
class PaternSlalom  : public UseJudgement
{
private:
    int16 distance;
public:
    PaternSlalom();

    ~PaternSlalom();

    int8_t decide(); 
};

