#include "../../include/Judge/PaternJudge.h"
#include "../../include/Judge/PaternSlalom.h"
#include "../../include/Judge/PaternGarage.h"

PaternJudge::PaternJudge(){
    slalomPatarn=0;
    garagePatarn=0;
}
PaternJudge::~PaternJudge(){
//    delete comparison;
}
int8 PaternJudge::Judge(int8 _patern){
    int8 paternChk=0;
//    Comparison comparison;
    if(_patern==slalom){
//        comparison=new PaternSlalom;
    }
    else if(_patern==garage){
//        comparison=new PaternGarage;
    }

//    paternChk=comparison.decide();
    
    if(_patern==slalom){
        slalomPatarn=paternChk;
        return SYS_OK;
    }    
    else if(_patern==garage){
        garagePatarn=paternChk;
        return SYS_OK;
    }
}
int8 PaternJudge::getSlalom(){
    return slalomPatarn;
}
int8 PaternJudge::getGarage(){
    return garagePatarn;
}