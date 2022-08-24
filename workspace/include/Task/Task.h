#pragma once
#include <cstdint>
#include <string.h>
#include <memory>
#include <string>
#include "ev3api.h"
#include "system.h"

class Task {
private:
	MoveData moveData;
	CorrectionData correctionData;
	//PARAMETER parameter;
public:
	Task();
	Task(MoveData *movedata,CorrectionData *correctiondata);
	~Task();

	int8 init();
	int8 run();
};