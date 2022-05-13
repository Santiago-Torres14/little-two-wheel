#include "Sensor.h"

Sensor::Sensor(int echoPin, int trigPin)
    : echoPin_(echoPin), triggerPin_(trigPin)
{
    pinMode(triggerPin_, OUTPUT);
    pinMode(echoPin_, INPUT);
}

int Sensor::getEchoPin() const
{
    return this->echoPin_;
}

int Sensor::getTrigPin() const
{
    return this->triggerPin_;
}

int Sensor::catch_signal()
{
    int trigPin = getTrigPin();
    int echoPin = getEchoPin();
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    return pulseIn(echoPin, HIGH) * 0.034 / 2;
}
