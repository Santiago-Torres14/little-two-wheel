#ifndef CAR_H
#define CAR_H

#include "Motor.h"
#include <Arduino.h>

class Car
{
private:
bool isOn_;
Motor motorR_, motorL_;
void driveCar();
void reverseCar();
void setVelocity(int velocity);
void setIsOn(bool value);
public:
Car(const Motor& motorR, const Motor& motorL);
void driveForward(int velocity);
void driveBackward(int velocity);
void stopCar();
void turnRight(int velocity);
void turnLeft(int velocity);
bool getIsOn() const;
};

#endif
