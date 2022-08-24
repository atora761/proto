#include "../../include/Judge/PaternSlalom.h"

PaternSlalom::PaternSlalom(){
    distance=0;
}

PaternSlalom::~PaternSlalom(){}

int8 PaternSlalom::decide(){
    int8 slalomstate=0;
//    UltraSonic ultrasonic = UltraSonic::getInstance();
//    distance=ultrasonic.getDistance();
    //距離によってパターン１，２を判定する
    if(distance<10){
        slalomstate=SLALOMPATERNA;
    }
    else{
        slalomstate=SLALOMPATERNB;
    }
    return slalomstate;
}