#ifndef __SENDINFOTASK__
#define __SENDINFOTASK__

#include "Task.h"

#include "shared_variables.h"
#include <Arduino.h>


class SendInfoTask: public Task {

  int indexModality;
  char* modalityNames[3];
  enum {VERIFY_MODALITY, SEND, RECEIVE} state;

public:
  SendInfoTask();
  void init(int period);
  void tick();
  void verifyMachineModality();
  void sendMsg();
  void readMsg();

}; 

extern SendInfoTask sendInfoTask;
#endif
