#include "../../include/system/system.h"
#include "../../include/Judge/Judgement.h"
#include "../../include/Judge/UseJudgement.h"
#include "../../include/Judge/AngleDecision.h"
#include "../../include/Judge/RGBDecision.h"
#include "../../include/Judge/CoordinateDecision.h"
#include "../../include/Judge/HSVDecision.h"
#include "../../include/Judge/RGBDecision.h"
#include "../../include/Judge/UltraSonicDecision.h"

int8_t Judgement::judge( DecisionData decisiondata ) {

	AngleDecision angledecision( decisiondata.angle, decisiondata.angle_range );

	CoordinateDecision coordinatedecision_x( decisiondata.coordinate, decisiondata.coordinate_range ,X_JUDGE);
	CoordinateDecision coordinatedecision_y( decisiondata.coordinate, decisiondata.coordinate_range ,Y_JUDGE);
	HSVDecision hsvdecision( decisiondata.hsv, decisiondata.hsv_range );
	RGBDecision rgbdecision( decisiondata.rgb, decisiondata.rgb_range );
	UltraSonicDecision ultrasonicdecision( decisiondata.distance, decisiondata.distance_range );
	UseJudgement *usejudgement[] = { &coordinatedecision_x ,&coordinatedecision_y ,&angledecision ,
									 &rgbdecision ,&hsvdecision ,&ultrasonicdecision };
	int8_t judge_cnt = 0;
	int8_t result_check[ 2 ];

	memset( result_check, 0, sizeof( result_check ) );

	//判定実行
	for ( judge_cnt = 0; (judge_cnt < 2 )&& (decisiondata.decision[ judge_cnt ] != 0); judge_cnt++ ) {
		decisiondata.decision[ judge_cnt ]--;
		result_check[ judge_cnt ] = usejudgement[ decisiondata.decision[ judge_cnt ] ]->decide();
		if ( result_check[ judge_cnt ] < 0 ) {

			return SYS_NG;
		}
	}

	//判定結果
	if ( judge_cnt == 1 ) {//単独判定

		if ( result_check[ 0 ] == RESULT_TRUE ) {

			return RESULT_TRUE;
		}
		else {
			
			return RESULT_FALSE;
		}
	}
	else if ( judge_cnt >= 2 ) {//複数判定


		if ( decisiondata.logic == LOGICAL_CONJUNCTION ) {//AND(両方
			
			if ( ( result_check[ 0 ] == RESULT_TRUE ) && ( result_check[ 1 ] == RESULT_TRUE ) ) {
			
				return RESULT_TRUE;
			}
			else {
				return RESULT_FALSE;
			}
		}
		else if ( decisiondata.logic == LOGICAL_DISJUNCTION ) {//OR（片方
			printf("check1=%d,check2=%d\n",result_check[0],result_check[1]);
			if ( ( result_check[ 0 ] == RESULT_TRUE ) || ( result_check[ 1 ] == RESULT_TRUE ) ) {

				return RESULT_TRUE;
			}
			else {
				return RESULT_FALSE;
			}
		}
	}

	return SYS_NG;
}