#pragma once
//#include <cstdint>
//#include <cstring>
//#include <memory>
//#include <string>
#include "ev3api.h"
#include "../system/system.h"


class SceneControl{
    private:
    int8  error;       //エラー値
    int16 scene_num;   //シーン数
    int16 now_scene;   //現シーン番号
    int8  now_scenario; //現在シナリオ
    int8 slalom_patern;
    int8 garage_card;
    SceneData sceneData;
    public:
    //コンストラクタ
    SceneControl();
    //デストラクタ
    ~SceneControl();
    //init      初期化
    //引数      -
    //戻り値    int8     エラー値
    int8  init();
    //run       動作
    //引数      -
    //戻り値    int8     エラー値
    int8  run();
    //switch    シーン切り替え
    //引数      -
    //戻り値    int8     エラー値
    int8  SceneSwitch();

    static SceneControl &getInstance()
    {
        static SceneControl sceneControl;
        return sceneControl;
    }
};