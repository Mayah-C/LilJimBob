#include <Servo.h>

Servo servoX;      // Controlled by X-axis (pin 9)
Servo servoY1;     // Controlled by Y-axis (pin 8, normal direction)
Servo servoY2;     // Controlled by Y-axis (pin 7, reversed direction)

const int joyXPin = A0;  // Joystick X-axis (left-right)
const int joyYPin = A1;  // Joystick Y-axis (up-down)

void setup() {
  servoX.attach(9);    // X-axis servo
  servoY1.attach(8);   // Y-axis servo 1
  servoY2.attach(7);   // Y-axis servo 2 (reversed)
}

void loop() {
  int joyX = analogRead(joyXPin);             // 0–1023
  int joyY = analogRead(joyYPin);             // 0–1023

  int angleX = map(joyX, 0, 1023, 0, 180);     // Normal mapping
  int angleY = map(joyY, 0, 1023, 0, 180);     // Y1 gets this angle
  int angleY_rev = 180 - angleY;              // Y2 gets the opposite

  servoX.write(angleX);
  servoY1.write(angleY);
  servoY2.write(angleY_rev);

  delay(15);  // Small delay for smooth motion
}
