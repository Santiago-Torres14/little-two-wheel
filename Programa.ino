#include "./Motor.h"
#include "./Car.h"
#include "./Sensor.h"

// LEFT
#define echoPin1 12
#define trigPin1 13
// CENTER
#define echoPin2 10
#define trigPin2 11
// RIGHT
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
  for (int i = 0; i < 3; i++)
  {
    distance[i] = sensors[i].catch_signal();
  }

  // None of the sensors are capturing objects close to the car
  if((distance[0] >= 15 || distance[0] == 0) && (distance[1] >= 20 || distance[1] == 0) && (distance[2] >= 15 || distance[2] == 0))
  {
    if(!car.getIsOn())
    {
      car.driveForward(60);
      delay(1000);
    }
  } else if (distance[0] >=1 && distance <= 15) // Left sensor
  {
    if(distance[1] >= 15 || distance[1] == 0)
    {
      if(!car.getIsOn()) // middle sensor
      {
        car.driveForward(60);
        delay(1000);
      }
    } else { // Right sensor
      if(!car.getIsOn()){
        car.driveBackward(50);
        delay(1000);
        car.turnRight(60);
        delay(1000);
        car.stopCar();
        delay(1000);
      }
    }
  } else if(distance[2] >= 1 && distance[2] <= 15) // Right sensor 
  {
    if(distance[1] >= 15 || distance[1] == 0)
    {
      if(!car.getIsOn())
      {
        car.driveForward(60);
        delay(1000);
      }
    } else {
      car.driveBackward(50);
      delay(1000);
      car.turnLeft(60);
      delay(1000);
      car.stopCar();
      delay(1000);
    }
  } else if (distance[1] >= 1 && distance[1] <= 15) // middle sensor 
  {
    if(distance[0] >= 15 || distance[0] == 0)
    {
      if(!car.getIsOn())
      {
        car.driveBackward(50);
        delay(1000);
        car.turnLeft(60);
        delay(1000);
        car.stopCar(1000);
        delay(1000);
      }
    } else {
      car.driveBackward(50);
      delay(1000);
      car.turnRight(60);
      delay(1000);
      car.stopCar();
      delay(1000);
    }
  } else {
    if (!car.getIsOn()){
      car.driveBackward(50);
      delay(1000);
      car.stopCar();
      delay(1000);
    }
  }
  
}
