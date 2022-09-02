#pragma once
#include"../system/system.h"
#include "ev3api.h"

class Motor
{
protected:
	motor_port_t portNum;
public:
	Motor( );
	~Motor( );
	int8 setPWM( int8 );
	float getCounts();
	
private:
	
};