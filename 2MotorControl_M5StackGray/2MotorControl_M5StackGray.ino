#include <M5Stack.h>

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

#include "CytronMotorDriver.h"

// Define GPIO pins for motor control
const int motorRPin1 = 25; // Example: Motor 1 Pin 1
const int motorRPin2 = 2; // Example: Motor 1 Pin 2
const int motorLPin1 = 26; // Example: Motor 2 Pin 1
const int motorLPin2 = 5; // Example: Motor 2 Pin 2

CytronMD motor_R(PWM_DIR, motorRPin1, motorRPin2);
CytronMD motor_L(PWM_DIR, motorLPin1, motorLPin2);

void setup() {
  // Initialize M5Stack
  M5.begin();
  
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  
  M5.Lcd.setTextSize(2);
}

void loop() {
  
  if (SerialBT.available()) {
    int16_t speed1 = SerialBT.read();
    if (speed1 == 1) {
      Serial.println(1);
      motor_R.setSpeed(0);
      motor_L.setSpeed(0);
    }  
    if (speed1 == 2) {
      Serial.println(2);
      motor_R.setSpeed(255);
      motor_L.setSpeed(0);
    }  
    if (speed1 == 3) {
      Serial.println(3);
      motor_R.setSpeed(-255);
      motor_L.setSpeed(0);
    }  
    if (speed1 == 4) {
      Serial.println(4);
      motor_R.setSpeed(0);
      motor_L.setSpeed(255);
    }  
    if (speed1 == 5) {
      Serial.println(5);
      motor_R.setSpeed(255);
      motor_L.setSpeed(255);
    }  
    if (speed1 == 6) {
      Serial.println(6);
      motor_R.setSpeed(-255);
      motor_L.setSpeed(255);
    }  
    if (speed1 == 7) {
      Serial.println(7);
      motor_R.setSpeed(0);
      motor_L.setSpeed(-255);
    }  
    if (speed1 == 8) {
      Serial.println(8);
      motor_R.setSpeed(255);
      motor_L.setSpeed(-255);
    }  
    if (speed1 == 9) {
      Serial.println(9);
      motor_R.setSpeed(-255);
      motor_L.setSpeed(-255);
    }  
  }
  delay(20);

  
//  int16_t speed1 = map(analogRead(35), 0, 4095, -255, 255);
//  int16_t speed2 = map(analogRead(36), 0, 4095, -255, 255);
 
//  M5.Lcd.setCursor(0, 0);
//  M5.Lcd.print("R: ");
//  M5.Lcd.print(speed1, DEC);
//  M5.Lcd.println("      ");
//  M5.Lcd.print("L: ");
//  M5.Lcd.print(speed2, DEC);
//  M5.Lcd.println("      ");
  
//  motor_R.setSpeed(speed1);
//  motor_L.setSpeed(speed2);
//  delay(20);
  
}
