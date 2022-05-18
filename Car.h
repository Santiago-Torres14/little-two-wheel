#ifndef CAR_H
#define CAR_H

#include "Motor.h"
#include <Arduino.h>

class Car
{
private:
Motor motorR_, motorL_;
void driveCar();
void reverseCar();
public:
Car(const Motor& motorR, const Motor& motorL);
void driveForward(int velocity);
void driveBackward(int velocity);
void stopCar();
};

#endif
