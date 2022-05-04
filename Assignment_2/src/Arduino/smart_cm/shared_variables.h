#ifndef __SHARED_VARIABLES__
#define __SHARED_VARIABLES__
#include "display.h"
#include "servo_motor.h"

extern bool selected;

extern char* productList[3];

extern int quantityList[3];

extern int selectedIndex;

extern int nSelfTest;

extern char* msg;

extern Display* machineDisplay;

extern bool productDone;

extern ServoMotor* servoMotor;

extern bool delivered;

extern bool assistanceRequired;

extern bool isWorking;

extern bool isReady;

extern const int N_MAX;



#endif
