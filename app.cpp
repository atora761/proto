/**
 ******************************************************************************
 ** ファイル名 : app.c
 **
 ** 概要 : 二輪差動型ライントレースロボットのTOPPERS/HRP3用Cサンプルプログラム
 **
 ** 注記 : sample_c4 (sample_c3にBluetooth通信リモートスタート機能を追加)
 ******************************************************************************
 **/
#include "ev3api.h"
#include "app.h"
#ifdef MAKE_SIM
#include "etroboc_ext.h"
#endif
#include "./workspace/include/Action/LineTrace.h"
#include "./workspace/include/Action/Curve.h"
#include "./workspace/include/Action/Straight.h"
#include "./workspace/include/CarData/CarData.h"
#include "./workspace/include/Scene/SceneControl.h"
#include "../../include/CarData/CarData.h"

#include "../../include/Sonic/UltraSonic.h"
#include "../../include/ColorSpace/ColorSpace.h"

/*
#if defined(MAKE_SIM)
#elif defined(MAKE_EV3)
#elif defined(MAKE_EV3)

#elif defined(MAKE_SPIKE)

#else

#elif defined(MAKE_SPIKE)
#else*/

#endif

#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif
bool flag = false;
/**
 * EV3システム生成
 * モーター設定
 */
static void user_system_create()
{

}
static void user_system_destroy()
{

}
/*  スタート処理タスク */
void start_task(intptr_t unused)
{
    char command[] = {"logon -section -trace \n"};
    
    uint16 index = 0;
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    /* 動的に生成するインスタンスの初期化 */
    user_system_create();
    //フライング
    while (1)
    {
        if (ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1)
        {
            break;
        }
        tslp_tsk(10 * 1000U);
    }
    ColorSpace &colorspace = ColorSpace::getInstance();
    colorspace.update();
	UltraSonic &ultrasonic = UltraSonic::getInstance();
    ultrasonic.update();
    act_tsk(MAIN_TASK);
    ext_tsk();
}

/* メインタスク */
void main_task(intptr_t unused)
{
	CarData&            car_data    = CarData::getInstance();
    SceneControl &scenecontrol = SceneControl::getInstance();
    int8 retChk = SYS_NG;
    sta_cyc(SONIC_PERIOD);
    sta_cyc(COLOR_PERIOD);
    sta_cyc(CARDATA_PERIOD);
    while(1){
        car_data.update();
        retChk = scenecontrol.run();
        if(retChk == ALL_SCENE_END){
            break;
        }
        retChk = scenecontrol.SceneSwitch();
        if(retChk == SYS_NG){
            ext_tsk();
        }
        tslp_tsk(10 * 1000U);
    }
    
   	stp_cyc(SONIC_PERIOD);
    stp_cyc(COLOR_PERIOD);
    stp_cyc(CARDATA_PERIOD);
#ifdef MAKE_SIM
	ETRoboc_notifyCompletedToSimulator();
#endif
    ext_tsk();
}
ETRoboc_notifyCompletedToSimulator();
    ext_tsk();
/* 周期タスク */
void sonic_task(intptr_t exinf)
{
    int8 retChk = SYS_NG;
    UltraSonic &ultrasonic = UltraSonic::getInstance();
    retChk = ultrasonic.update();
    if( retChk != SYS_OK ){
    }
}

void color_task(intptr_t exinf)
{
    int8 retChk = SYS_NG;
    ColorSpace &colorspace = ColorSpace::getInstance();
    retChk = colorspace.update();
    if( retChk != SYS_OK ){
    }
}

void cardata_task(intptr_t exinf)
{
    int8 retChk = SYS_NG;
    CarData &cardata = CarData::getInstance();
    retChk = cardata.update();
    if( retChk != SYS_OK ){
    }
}


