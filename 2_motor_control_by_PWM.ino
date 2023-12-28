#include <M5Stack.h>
#include "CytronMotorDriver.h"

// Define GPIO pins for motor control
const int motorRPin1 = 25; // Example: Motor 1 Pin 1
const int motorRPin2 = 18; // Example: Motor 1 Pin 2
const int motorLPin1 = 26; // Example: Motor 2 Pin 1
const int motorLPin2 = 19; // Example: Motor 2 Pin 2

CytronMD motor_R(PWM_DIR, motorRPin1, motorRPin2);
CytronMD motor_L(PWM_DIR, motorLPin1, motorLPin2);

void setup() {
  // Initialize M5Stack
  M5.begin();
  M5.Lcd.setTextSize(2);
}

void loop() {
  int16_t speed1 = map(analogRead(35), 0, 4095, -255, 255);
  int16_t speed2 = map(analogRead(36), 0, 4095, -255, 255);
 
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("R: ");
  M5.Lcd.print(speed1, DEC);
  M5.Lcd.println("      ");
  M5.Lcd.print("L: ");
  M5.Lcd.print(speed2, DEC);
  M5.Lcd.println("      ");
  
  motor_R.setSpeed(speed1);
  motor_L.setSpeed(speed2);
  delay(20);
  
}
