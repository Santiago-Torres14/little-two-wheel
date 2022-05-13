#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor
{
private:
    int echoPin_, triggerPin_;

public:
    Sensor(int echoPin, int trigPin);
    int catch_signal();
    int getEchoPin() const;
    int getTrigPin() const;
};

#endif
