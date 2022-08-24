#include "../../include/Avoidance/AvoidanceRoute.h"

//コンストラクタ(引数なし)
AvoidanceRoute::AvoidanceRoute(){}

//コンストラクタ(引数あり)
AvoidanceRoute::AvoidanceRoute(int8_t sulalom_patarn){
    patarn = sulalom_patarn;    //スラロームパターン
    correctionAngle = 0;         //切り替え情報(補正後)
    error = 0;                  //エラー値

    //スラロームパターンが１の場合の障害物位置
    //※初期はスラローム板の左下角が原点になっている
    if(patarn == 1){
        //障害物1の位置
        obstacle[0].x = 990;
        obstacle[0].y = 75;
        //障害物2の位置
        obstacle[1].x = 735;
        obstacle[1].y = 255;
        //障害物3の位置
        obstacle[2].x = 530;
        obstacle[2].y = 45;
        //障害物4の位置
        obstacle[3].x = 365;
        obstacle[3].y = 275;
        //障害物5の位置
        obstacle[4].x = 100;
        obstacle[4].y = 390;
        //障害物6の位置
        obstacle[5].x = 315;
        obstacle[5].y = 560;
    }
    else{
        //障害物1の位置
        obstacle[0].x = 990;
        obstacle[0].y = 75;
        //障害物2の位置
        obstacle[1].x = 735;
        obstacle[1].y = 255;
        //障害物3の位置
        obstacle[2].x = 530;
        obstacle[2].y = 45;
        //障害物4の位置
        obstacle[3].x = 245;
        obstacle[3].y = 230;
        //障害物5の位置
        obstacle[4].x = 370;
        obstacle[4].y = 410;
        //障害物6の位置
        obstacle[5].x = 120;
        obstacle[5].y = 545;
    }
    coordinate.x = 0;
    coordinate.y = 0;
}

//デストラクタ
AvoidanceRoute::~AvoidanceRoute(){}

//実行
float AvoidanceRoute::run(){
    correctionAngle = avoidanceRoute();
    
    return correctionAngle;
}

//回避経路補正
float AvoidanceRoute::avoidanceRoute(){
    int16_t defference_x = 0;
    int16_t defference_y = 0;
    //自己位置の取得
    //test
    coordinate.x = 1500;
    coordinate.y = 85;

    //自己位置によって計算場所を変える
    if(obstacle[1].x < coordinate.x){
        defference_x = obstacle[0].x - obstacle[1].x;
        defference_y = obstacle[0].y - obstacle[1].y;
        defference_x = defference_x / 2;
        defference_y = defference_y / 2;
    }else if(obstacle[2].x < coordinate.x){
        defference_x = obstacle[1].x - obstacle[2].x;
        defference_y = obstacle[1].y - obstacle[2].y;
        defference_x = defference_x / 2;
        defference_y = defference_y / 2;
    }else if(obstacle[3].x < coordinate.x){
        defference_x = obstacle[2].x - obstacle[3].x;
        defference_y = obstacle[2].y - obstacle[3].y;
        defference_x = defference_x / 2;
        defference_y = defference_y / 2;
    }else if(obstacle[4].y < coordinate.y){ //左上を座標原点とする場合は＞
        defference_x = obstacle[3].x - obstacle[4].x;
        defference_y = obstacle[3].y - obstacle[4].y;
        defference_x = defference_x / 2;
        defference_y = defference_y / 2;
    }else if(obstacle[5].y < coordinate.y){ //左上を座標原点とする場合は＞
        defference_x = obstacle[4].x - obstacle[5].x;
        defference_y = obstacle[4].y - obstacle[5].y;
        defference_x = defference_x / 2;
        defference_y = defference_y / 2;
    }

    //角度を求める
    defference_x = coordinate.x - defference_x;
    defference_y = coordinate.y - defference_y;
    correctionAngle = atan(defference_x/defference_y);

    //ラジアンから度に変換
    correctionAngle = correctionAngle * 180 / 3.141592;
    
    return correctionAngle;
}