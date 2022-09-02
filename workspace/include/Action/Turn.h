//#include <cstdint>
//#include <cstring>
//#include <memory>
//#include <string>
#include "ev3api.h"

#include "./Action.h"
#include "../CarData/CarData.h"

class Turn : public Action {
private:
	unsigned char  angle;
public:
	Turn(unsigned char );
	~Turn();

	int8 run(int32 speed);

};