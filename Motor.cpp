#include "Motor.h"

Motor::Motor(int vPin, int aPin, int bPin)
    : velocityPin_(vPin),
    controlPinA_(aPin), 
    controlPinB_(bPin)
{

}

int Motor::getVelocityPin const()
{
    return this.velocityPin_;
}

int Motor::getControlPinA const ()
{
    return this.controlPinA_;
}

int Motor::getControlPinB const ()
{
    return this.controlPinB_;
}

void Motor::start(){
    digitalWrite(getControlPinA(), 0);
    digitalWrite(getControlPinB(), 1);
    analogWrite(getVelocityPin(), 0);
}

void Motor::stop(){
    digitalWrite(getControlPinA(), 0);
    digitalWrite(getControlPinB(), 0);
    analogWrite(getVelocityPin(), 0);
}