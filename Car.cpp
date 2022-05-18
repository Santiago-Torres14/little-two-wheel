#include "Car.h"

Car::Car(const Motor& motorR, const Motor& motorL)
    : motorR_(motorR), motorL_(motorL)
{   
}

void Car::driveForward(int velocity)
{
    this->driveCar();
    this->motorR_.setVelocity(velocity);
    this->motorL_.setVelocity(velocity);
}

void Car::driveCar()
{
    this->motorR_.drive();
    this->motorL_.drive();
}

void Car::reverseCar()
{
    this->motorR_.reverse();
    this->motorL_.reverse();
}

void Car::stopCar()
{
    this->motorR_.stop();
    this->motorL_.stop();
}

void Car::driveBackward(int velocity)
{
    this->reverseCar();
    this->motorR_.setVelocity(velocity);
    this->motorL_.setVelocity(velocity);
}
