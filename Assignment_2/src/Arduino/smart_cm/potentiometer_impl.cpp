#include "potentiometer_impl.h"

#include "Arduino.h"

PotentiometerImpl::PotentiometerImpl(int pin){

    this->pin = pin;

    pinMode(pin, INPUT);

}


int PotentiometerImpl::getValue(){

    return map(analogRead(pin), 0, 1023, 0, 5);

}
