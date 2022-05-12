#define echoPin1 12 
#define trigPin1 13
#define echoPin2 10
#define trigPin2 11
#define echoPin3 3
#define trigPin3 2

// defines variables
int distance[3]; // variable for the distance measurement
int triggers[] = {trigPin1, trigPin2, trigPin3};
int echos[] = {echoPin1, echoPin2, echoPin3};
enum Direction {
  LEFT = 0,
  RIGHT = 1
};
class Motor{
  private:
  int velocity;
  int velocityPin;
  Direction controlA;
  Direction ControlB;
  int controlPinA, controlPinB;
  public:
  motor(int velocity, int velocityPin, int controlPinA, int controlPinB){
    this.velocity = velocity;
    this.controlPinA = controlPinA;
    this.controlPinB = controlPinB;
    this.velocityPin = velocityPin      
  }
  void drive(int velocity, Direction controlA, Direction controlB){
    digitalWrite(controlPinA,controlA); 
    digitalWrite(controlPinB,controlB);    
    analogWrite(velocityPin,velocity);
  }
  
}

void setup() {
  for(int i=0; i<3; i++){
    pinMode(triggers[i], OUTPUT);
    pinMode(echos[i], INPUT);
  }
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

int catch_signal(int trigPin, int echoPin);

void loop() {
  for(int i=0; i<3; i++) {
    distance[i] = catch_signal(triggers[i], echos[i]);
    Serial.print(distance[i]);
    Serial.print(" cm");
    Serial.println(i);
  }
  Serial.println("--------------------------");
  delay(500);
}

int catch_signal(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}
