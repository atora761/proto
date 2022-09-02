/// 2022/07/13
/// yoshitome
/// Curve

#include "./Action.h"
#include "./TrapezoidControl.h"
#include "../CarData/CarData.h"
#include "../system/system.h"
#include "../Steering/Steering.h"

#define PAI         (3.14f)         // 円周率
#define LEFT_CURVE  (1)             // 左カーブ
#define RIGHT_CURVE (2)             // 右カーブ

#ifdef  EV3
//#define CAR_WIDTH   (90)            // 車体幅(ごめんしらん)

#endif

#ifdef  SPIKE
//#define CAR_WIDTH   (100)           // 車体幅(しらない)

#endif

class Curve : public Action{
private:
    float           radius;                 // 半径
    int8          direction;              // カーブ方向
	COORDINATE      target_coordinate;      // 目標座標

public:

    Curve();
    Curve(float _radius, int8 _direction,COORDINATE _coordenate);
    ~Curve();

    int8 run(int32 speed);
};