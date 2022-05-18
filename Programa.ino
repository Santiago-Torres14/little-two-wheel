#include "./Motor.h"
#include "./Car.h"
#include "./Sensor.h"

#define echoPin1 12
#define trigPin1 13
#define echoPin2 10
#define trigPin2 11
#define echoPin3 3
#define trigPin3 2

// LEFT MOTOR
#define controlA 7
#define controlB 8
#define velocityPin 5

// RIGHT MOTOR
#define controlA2 9
#define controlB2 4
#define velocityPin2 6

// defines variables
int distance[3]; // variable for the distance measurement
Sensor sensors[3] = {Sensor(12, 13), Sensor(10, 11), Sensor(3, 2)};
Motor motorR(velocityPin2, controlA2, controlB2);
Motor motorL(velocityPin, controlA, controlB);
Car car(motorR, motorL);;

void setup()
{
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop()
{
  car.driveForward(70);
  for (int i = 0; i < 3; i++)
  {
    if (sensors[i].catch_signal() >= 1 and sensors[i].catch_signal() <= 15 )
    {
      car.stopCar();
    }
  }
}
