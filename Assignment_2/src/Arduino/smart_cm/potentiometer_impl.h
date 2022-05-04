#ifndef __POTENTIOMETER_IMPL__
#define __POTENTIOMETER_IMPL__
#include "potentiometer.h"



class PotentiometerImpl: public Potentiometer {

    public:

        PotentiometerImpl(int pin);

        int getValue();

   

    private:

        int pin;

};
#endif
