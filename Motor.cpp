#include "Motor.h"

Motor::Motor(int vPin, int aPin, int bPin)
    : velocityPin_(vPin), controlPinA_(aPin), controlPinB_(bPin)
{
    pinMode(velocityPin_, OUTPUT);
    pinMode(controlPinA_, OUTPUT);
    pinMode(controlPinB_, OUTPUT);

    digitalWrite(velocityPin_, 0);
    digitalWrite(controlPinA_, 0);
    digitalWrite(controlPinB_, 0);
}

int Motor::getVelocityPin() const
{
    return this->velocityPin_;
}

int Motor::getControlPinA() const
{
    return this->controlPinA_;
}

int Motor::getControlPinB() const
{
    return this->controlPinB_;
}

void Motor::drive()
{
    digitalWrite(getControlPinA(), 0);
    digitalWrite(getControlPinB(), 1);
    analogWrite(getVelocityPin(), 0);
}

void Motor::reverse()
{
    digitalWrite(getControlPinA(), 1);
    digitalWrite(getControlPinB(), 0);
    analogWrite(getVelocityPin(), 0);
}

void Motor::setVelocity(int velocity) const
{
    analogWrite(getVelocityPin(), velocity);
}

void Motor::stop()
{
    digitalWrite(getControlPinA(), 0);
    digitalWrite(getControlPinB(), 0);
    analogWrite(getVelocityPin(), 0);
}