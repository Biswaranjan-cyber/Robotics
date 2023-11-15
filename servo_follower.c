
#include <Servo.h>


const int leftMotor1 = 2;  
const int leftMotor2 = 3;  
const int rightMotor1 = 4; 
const int rightMotor2 = 5; 


const int leftSensor = A0;
const int rightSensor = A1;


Servo servo;

void setup() {
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);


  servo.attach(9);  // Connect the servo to pin 9

  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
}

void loop() {
  int leftSensorValue = analogRead(leftSensor);
  int rightSensorValue = analogRead(rightSensor);

  if (leftSensorValue < 500 && rightSensorValue < 500) {
    moveForward();
  } else if (leftSensorValue >= 500 && rightSensorValue < 500) {
    turnRight();
  } else if (leftSensorValue < 500 && rightSensorValue >= 500) {
    turnLeft();
  } else {
    stopMotors();
  }
}


void moveForward() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void turnLeft() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void turnRight() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
}

void stopMotors() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}