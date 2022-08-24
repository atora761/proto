#include "../../include/Task/Task.h"
#include "../../include/Avoidance/AvoidanceRoute.h"
#include "../../include/Judge/PaternJudge.h"
#include "../../include/Action/LineTrace.h"
#include "../../include/Action/Curve.h"
#include "../../include/Action/Straight.h"

Task::Task() {}
Task::Task(MoveData *movedata,CorrectionData *correctiondata){
    moveData = *movedata;
    correctionData = *correctiondata;
}
Task::~Task() {}

int8_t Task::run(){
    int8_t retChk = SYS_NG;
    if(moveData.motion == '0'){
        Action* action = new LineTrace(moveData.gain,moveData.target_val,moveData.edge,moveData.coordinate);
        retChk = action->run(moveData.speed);
    }
    else if(moveData.motion == '1'){
        Action* action = new Curve(moveData.radius,moveData.direction,moveData.coordinate);
        retChk = action->run(moveData.speed);
    }
    else if(moveData.motion == '2'){

    }
    else if(moveData.motion == '3'){
        Action* action = new Straight(moveData.coordinate);
        retChk = action->run(moveData.speed);
    }
    else{
        printf("motion_error\n");
    }
    //アーム動作が設定されていれば行う
    /*if(arm == 1){
        printf("arm_move\n");
    }*/
    //回避経路補正の値が設定されていれば行う
    /*if(avoidance == 1){
        int8_t patern = 0;
        //スラロームのパターンを取得する
        PaternJudge &paternjudge = PaternJudge::getInstance();
        patern = paternjudge.getSlalom();
        //回避経路補正を行う
        SceneInfo& sceneInfo = SceneInfo::getInstance();
        sceneData = sceneInfo.get(now_scenario,now_scene,paternjudge.getSlalom());
        AvoidanceRoute *avoidanceroute = new AvoidanceRoute(patern);
        angle = avoidanceroute->run();
    }*/
    //自己位置補正の値が設定されていれば行う
    /*if(correction == 1){
        //自己位置補正を行う
        printf("coorection_start\n");
    }*/

    return SYS_OK;
}