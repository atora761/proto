#pragma once
/* ------------------------------------------------------------------------- */
/* UltraSonic.h     														 */
/* 障害物からの距離を取得する            									 */
/* シングルトンで定義														 */
/* ------------------------------------------------------------------------- */
/* 番号	更新履歴								日付		   氏名			 */
/* 000000	新規作成							2022/07/14     筈尾　辰也	 */
/* ------------------------------------------------------------------------- */
/* Secure 宣言																 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* Include File																 */
/* ------------------------------------------------------------------------- */
#include "system.h"                              /* system.hが不明            */
#include "UltraSonicSensor.h"

/* ------------------------------------------------------------------------- */
/* Define宣言																 */
/* ------------------------------------------------------------------------- */
#define PI 3.141592653589793
#define DIST ((PI) * (double)CAR_WHEEL_WIDTH) / 360.0f

/* ------------------------------------------------------------------------- */
/* 構造体定義																 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* Class定義																 */
/* ------------------------------------------------------------------------- */
class UltraSonic {
private:
    int16_t prevDisCM;                          /* 前回の距離(CM)            */
    int16_t critDisCM;                          /* 基準となるCM              */
    MOTOR_ANGLE   prevMorter;                   /* 前回のモータのエンコーダ  */
    MOTOR_ANGLE   nowMorter;                    /* 最新のモータのエンコーダ  */

    UltraSonic();                               /* コンストラクタ            */
    int8_t  calc();                             /* 平均化してmm単位で取得    */

public:

    uint16_t distanceCM;                          /* 距離情報(CM)            　*/
    double distanceMM;
    ~UltraSonic();                              /* デストラクタ              */
    int16_t getDistance();                      /* 距離の取得                */
    int8_t  update();                           /* distance更新              */

    static UltraSonic& getInstance()
    {
        static UltraSonic UltraSonic_;	// インスタンスの生成 
        return UltraSonic_;
    }
};
/* ------------------------------------------------------------------------- */
/*              Copyright HAL Collage of Technology & Design                 */
/* ------------------------------------------------------------------------- */
