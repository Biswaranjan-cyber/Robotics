// Sensor pins
const int leftSensorPin = 2;  
const int rightSensorPin = 3;  

// Motor control pins
const int leftMotorPin1 = 4; 
const int leftMotorPin2 = 5;
const int rightMotorPin1 = 6;
const int rightMotorPin2 = 7;

void setup() {
  // Configure sensor pins as inputs
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  // Configure motor control pins as outputs
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
}

void loop() {
  // Read sensor values
  int leftSensorValue = digitalRead(leftSensorPin);
  int rightSensorValue = digitalRead(rightSensorPin);

  // Logic for robot movement
  if (leftSensorValue == HIGH && rightSensorValue == HIGH) {
    // Both sensors on the line
    moveForward();
  } else if (leftSensorValue == LOW && rightSensorValue == HIGH) {
    // Left sensor off the line, turn right
    turnRight();
  } else if (leftSensorValue == HIGH && rightSensorValue == LOW) {
    // Right sensor off the line, turn left
    turnLeft();
  } else {
    // Both sensors off the line, stop
    stopMotors();
  }
}

// Function to move the robot forward
void moveForward() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

// Function to turn the robot left
void turnLeft() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

// Function to turn the robot right
void turnRight() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}

// Function to stop the motors
void stopMotors() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}
