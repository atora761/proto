#pragma once

#define RANGE_LIMIT 2 //使用範囲上限



class AngleDecision : public UseJudgement {

public:

	AngleDecision();
	AngleDecision( float target_angle, int8 range );

	int8 decide( void );//角度判定メソッド

private:

	float m_target_angle;//目標角度
	uint8 m_range;//使用範囲
};

