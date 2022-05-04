#ifndef __USERDETECTIONTASK__
#define __USERDETECTIONTASK__

#include "Task.h"

#include "shared_variables.h"
#include <Arduino.h>
#include "pir.h"



class UserDetectionTask: public Task {

  enum {DETECTED, NOT_DETECTED } state;
  int pinPir;
  Pir* pir;
  const int T_IDLE = 60000;
  unsigned long lastDetectionTime;
  
 
public:

  UserDetectionTask(int pinPir);
  
  void init(int period);
  void tick();
  void checkButtonPressed();
  static void wakeUp();
}; 
#endif
