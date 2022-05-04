#ifndef __CHECKTASK__
#define __CHECKTASK__

#include "Task.h"
#include "shared_variables.h"
#include <Arduino.h>
#include "temp_sensor.h"



class CheckTask: public Task {
  const long T_CHECK = 180000;
  const long T_CHECK_PERIOD = 120000;
  const float T_MIN = 17.0;
  const float T_MAX = 24.0;
  enum  {WAITING_CHECK, SELF_TEST, TEMP_CHECK} state;
  TempSensor* tempSensor;
  int pinTempSensor;
  unsigned long lastCheckTime;
  unsigned long servoDelay;
  float temperature;

 
public:

  CheckTask(int pinTempSensor); 
  void init(int period);
  void tick();
}; 
#endif
