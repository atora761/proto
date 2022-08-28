#pragma once
#define slalom 0
#define garage 1
#include <cstdint>
#include <string.h>
#include <memory>
#include <string>
#include "ev3api.h"
#include "system.h"
#include "../../include/Judge/UseJudgement.h"
#include "../../include/Judge/PaternGarage.h"
#include "../../include/Judge/PaternSlalom.h"
#include <vector>
#include <stdlib.h>
using namespace std;
//判定のクラス名追加が必要
class PaternJudge
{
private:
    int8 patern[2];
    vector<UseJudgement*> judgement;
    vector<UseJudgement*>::iterator it=judgement.begin();
public:
    PaternJudge();

    ~PaternJudge();

    int8 Judge(int8);
    int8 getSlalom();
    int8 getGarage();
    static PaternJudge &getInstance()
    {
        static PaternJudge paternJudge;
        return paternJudge;
    }
};