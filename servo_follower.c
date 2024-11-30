#include <Servo.h>

// Motor control pins
const int leftMotor1 = 2;  
const int leftMotor2 = 3;  
const int rightMotor1 = 4; 
const int rightMotor2 = 5; 

// Line sensor pins
const int leftSensor = A0;
const int rightSensor = A1;

// Threshold for detecting the black line
const int threshold = 500; 

void setup() {
  // Configure motor control pins as outputs
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);

  // Configure sensor pins as inputs
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
}

void loop() {
  // Read sensor values
  int leftSensorValue = analogRead(leftSensor);
  int rightSensorValue = analogRead(rightSensor);

  // Determine movement based on sensor readings
  if (leftSensorValue < threshold && rightSensorValue < threshold) {
    // Both sensors detect the black line
    moveForward();
  } else if (leftSensorValue >= threshold && rightSensorValue < threshold) {
    // Left sensor is off the line, turn right
    turnRight();
  } else if (leftSensorValue < threshold && rightSensorValue >= threshold) {
    // Right sensor is off the line, turn left
    turnLeft();
  } else {
    // Both sensors are off the line, stop or search
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
