#ifndef __SELECTIONTASK__
#define __SELECTIONTASK__

#include "Task.h"
#include "button.h"
#include "button_impl.h"
#include "shared_variables.h"
#include "potentiometer.h"
#include "potentiometer_impl.h"


class SelectionTask: public Task {
  Button* buttonUp;
  Button* buttonDown;
  Button* buttonMake;
  Potentiometer* potentiometer;
  
  int pin[4];
  int delta;
  int sugarLevel;
  enum {SELECTING, WAIT_DELIVERY } state;

  const int T_READY = 5000;
  unsigned long lastIteration;

 
public:

  SelectionTask(int pinUp, int pinDown, int pinMake, int pinPot);
  
  void init(int period);
  void tick();
  void checkButtonPressed();
  void nextProduct();
  void checkSugarLevel();
}; 
#endif
