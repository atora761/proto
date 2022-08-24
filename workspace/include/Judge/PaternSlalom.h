#pragma once
#define SLALOMPATERNA 1
#define SLALOMPATERNB 2
#include <cstdint>
#include <string.h>
#include <memory>
#include <string>
#include "ev3api.h"
#include "system.h"
class PaternSlalom //: public Comparison
{
private:
    int16 distance;
public:
    PaternSlalom();

    ~PaternSlalom();

    int8 decide(); 
};

