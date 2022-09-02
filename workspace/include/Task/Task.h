#pragma once
//#include <cstdint>
//#include <cstring>
//#include <memory>
//#include <string>
#include "ev3api.h"
#include "../system/system.h"

class Task {
private:
	MoveData moveData;
	CorrectionData correctionData;
	//PARAMETER parameter;
public:
	Task();
	Task(MoveData movedata,CorrectionData correctiondata);
	~Task();

	int8 init();
	int8 run();
};