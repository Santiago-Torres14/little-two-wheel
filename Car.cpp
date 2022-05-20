#include "Car.h"

Car::Car(const Motor& motorR, const Motor& motorL)
    : motorR_(motorR), motorL_(motorL)
{   
}

void Car::setVelocity(int velocity)
{
    this->motorR_.setVelocity(velocity);
    this->motorL_.setVelocity(velocity);
}

bool Car::getIsOn()
{
    return this->isOn_;
}

void Car::setIsOn(bool value)
{
    this->isOn_ = value;
}

void Car::driveForward(int velocity)
{
    this->driveCar();
    this->setVelocity(velocity);
    this->setIsOn(true);
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
    this->setIsOn(false);
}

void Car::driveBackward(int velocity)
{
    this->reverseCar();
    this->setVelocity(velocity);
    this->setIsOn(true);
}

void Car::turnRight(int velocity)
{
    this->motorR_.reverse();
    this->motorL_.drive();
    this->setVelocity(velocity);
    this->setIsOn(true);
}

void Car::turnLeft(int velocity)
{
    this->motorL_.reverse();
    this->motorR_.drive();
    this->setVelocity(velocity);
    this->setIsOn(true);
}
