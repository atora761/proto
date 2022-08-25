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
#include "etroboc_ext.h"
#include "./workspace/include/Action/LineTrace.h"
#include "./workspace/include/Action/Curve.h"
#include "./workspace/include/Action/Straight.h"
#include "./workspace/include/CarData/CarData.h"
#include "./workspace/include/Scene/SceneControl.h"\

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

    act_tsk(MAIN_TASK);
    ext_tsk();
}

/* メインタスク */
void main_task(intptr_t unused)
{
	printf("change_task_start\n");
	CarData&            car_data    = CarData::getInstance();
    SceneControl &scenecontrol = SceneControl::getInstance();
    int8 retChk = SYS_NG;
    while(1){
        car_data.update();
        retChk = scenecontrol.run();
        scenecontrol.SceneSwitch();
        if(retChk == ALL_SCENE_END){
            break;
        }
        if(retChk == SYS_NG){
            ext_tsk();
        }
        tslp_tsk(10 * 1000U);
    }
   	
	ETRoboc_notifyCompletedToSimulator();
    ext_tsk();
}

/* シーン切り替えタスク */
void change_task(intptr_t unused)
{
    int8 retChk = SYS_NG;
    SceneControl &scenecontrol = SceneControl::getInstance();
	printf("change_task_start\n");

    //シーン切り替え
    retChk = scenecontrol.SceneSwitch();
    if(retChk != SYS_OK){
		printf("scene_switch_error\n");
        ext_tsk();
    }
    ext_tsk();
}
