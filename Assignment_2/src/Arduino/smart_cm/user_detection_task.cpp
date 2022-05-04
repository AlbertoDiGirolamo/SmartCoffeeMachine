#include "user_detection_task.h"
#include <Arduino.h>
#include "display_impl.h"
#include "shared_variables.h"

#include "pir_impl.h"
#include <avr/sleep.h>
#include <EnableInterrupt.h>


UserDetectionTask::UserDetectionTask(int pinPir){
  this->pinPir = pinPir;
}

void UserDetectionTask::init(int period){
  
  Task::init(period);
  this-> pir = new PirImpl(pinPir);
  this->state = NOT_DETECTED;
  enableInterrupt(pinPir, wakeUp, RISING);
  

}
void UserDetectionTask::tick(){
  if(!pir->isReady()){
    return;
  }
  switch(state){
    case DETECTED:
      if(!pir->isDetected()){
        state = NOT_DETECTED;
        lastDetectionTime = millis();
        //Serial.println("not detected");
        
      }
      break;
    case NOT_DETECTED:
    if (pir->isDetected()){
      state = DETECTED;
    }else if (!pir->isDetected() and millis() - lastDetectionTime >= T_IDLE){
      enableInterrupt(pinPir, wakeUp, RISING);
      set_sleep_mode(SLEEP_MODE_PWR_DOWN);
      sleep_enable();
      sleep_mode();

      sleep_disable();
      disableInterrupt(pinPir);
      
      //Serial.println("SLEEP");
    }
    break;
       
  }
  
  
}

static void UserDetectionTask::wakeUp(){

}
