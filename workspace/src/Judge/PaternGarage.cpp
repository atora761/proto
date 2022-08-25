#include "../../include/Judge/PaternGarage.h"
#include "../../include/ColorSpace/ColorSpace.h"
#include "../../include/Judge/UseJudgement.h"
/*
PaternGarage::PaternGarage(){}

PaternGarage::~PaternGarage(){}

int8_t PaternGarage::decide(){
    int8 garagestate=0;
    ColorSpace color = ColorSpace::getInstance();
    rgb=color.getRGB();
    //黄色
    if(rgb.r>100&&rgb.g>50&&rgb.b>50){
        garagestate=YELLOWTHRESHOL;
    }
    //赤
    if(rgb.r>100){
        garagestate=REDTHRESHOLD;
    }
    //緑
    if(rgb.g>100){
        garagestate=GREENTHRESHOLD;
    }
    //青
    if(rgb.b>100){
        garagestate=BLUETHRESHOLD;
    }
    return garagestate;
}
*/