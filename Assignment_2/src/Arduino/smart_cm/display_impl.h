#ifndef __DISPLAY_IMPL__
#define __DISPLAY_IMPL__
/*SDA A4 SCL A5*/
#include "display.h"
#include <LiquidCrystal_I2C.h> 


class DisplayImpl: public Display {

public:
  DisplayImpl();

  void displayMessage(char* msg);
  //LiquidCrystal_I2C lcd;

private:
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2);
};


#endif
