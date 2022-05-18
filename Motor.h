#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor
{
private:
    int velocityPin_;
    int controlPinA_;
    int controlPinB_;

public:
    Motor(int vPin, int aPin, int bPin);
    int getVelocityPin() const;
    int getControlPinA() const;
    int getControlPinB() const;
    void setVelocity(int velocity) const;
    void drive();
    void reverse();
    void stop();
};

#endif
