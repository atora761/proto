#ifndef COORDINATEDECISION

#define COORDINATEDECISION

#define USAGE_LIMIT 2//判定実行上限
#define RANGE_LIMIT 2//使用範囲上限

class CoordinateDecision : public UseJudgement{

public:

	CoordinateDecision();
	CoordinateDecision( COORDINATE coordinate, uint8 range[ USAGE_LIMIT ] );

	int8 decide();//判定メソッド

private:

	COORDINATE m_coordinate;//目標座標
	uint8 m_range[ USAGE_LIMIT ];//使用範囲
};

#endif