#ifndef ULTRASONICDECISION

#define ULTRASONICDECISION

#define RANGE_LIMIT 2//使用範囲上限

class UltraSonicDecision : public UseJudgement {

public:

	UltraSonicDecision();
	UltraSonicDecision( int16 target_distance, int8 range );

	int8 decide();//判定メソッド

private:
	int16 m_target_distance;//目標距離
	uint8 m_range;//使用範囲

};

#endif