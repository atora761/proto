#pragma once
#include <cstdint>
#include <string.h>
#include <memory>
#include <string>
#include "ev3api.h"
#include "system.h"

#define obstacle_width 84

class AvoidanceRoute{
    private:
    float       correctionAngle; //切り替え向き
    int8_t      error;
    int8_t      patarn;         //障害物パターン
    COORDINATE  obstacle[6];      //障害物位置
    COORDINATE  coordinate;     //自己位置座標

    //回避経路補正
    float avoidanceRoute();

    public:
    //コンストラクタ(引数なし)
    AvoidanceRoute();

    //コンストラクタ(引数あり)
    AvoidanceRoute(int8_t patern);

    //デストラクタ
    ~AvoidanceRoute();

    //実行
    float run();
};