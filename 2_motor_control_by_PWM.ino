#include <M5Stack.h>

// Define GPIO pins for motor control
const int motor1Pin1 = 33; // Example: Motor 1 Pin 1
const int motor1Pin2 = 32; // Example: Motor 1 Pin 2
const int motor2Pin1 = 25; // Example: Motor 2 Pin 1
const int motor2Pin2 = 26; // Example: Motor 2 Pin 2

void setup() {
  // Initialize M5Stack
  M5.begin();

  // Set motor control pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}

void loop() {
  // Rotate motor 1 in one direction
  analogWrite(motor1Pin1, 200); // Set PWM value to 200
  analogWrite(motor1Pin2, 0);   // Set PWM value to 0

  // Rotate motor 2 in the opposite direction
  analogWrite(motor2Pin1, 0);   // Set PWM value to 0
  analogWrite(motor2Pin2, 200); // Set PWM value to 200

  delay(2000); // Delay for 2 seconds

  // Stop the motors
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, 0);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, 0);

  delay(2000); // Delay for 2 seconds
}
