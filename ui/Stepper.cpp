#include "Stepper.h"
#include <Arduino.h>

volatile int direction = 0;
volatile int startStop = 0;
volatile int step = 0;
volatile double rotations = 0.0;
volatile double angle = 0.0;
volatile int moveToAngleFlag = 0;
volatile int zeroMotorFlag = 0;
volatile double targetAngle = 0.0;
volatile double moveByAngle = 0.0;
volatile double moveToAngleValue = 0.0;
volatile int delayTime = 10;
volatile double motorVelocity = 5;
bool saveAngle = false;

void setupStepperMotor()
{
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
}

void moveStepperMotor()
{
  moveToAngle(targetAngle, moveToAngleFlag, angle, startStop, direction);
  if (startStop)
  {
    switch (step)
    {
      case 0:
        digitalWrite(PIN_A, LOW);
        digitalWrite(PIN_B, LOW);
        digitalWrite(PIN_C, LOW);
        digitalWrite(PIN_D, HIGH);
        break;
      case 1:
        digitalWrite(PIN_A, LOW);
        digitalWrite(PIN_B, LOW);
        digitalWrite(PIN_C, HIGH);
        digitalWrite(PIN_D, HIGH);
        break;
      case 2:
        digitalWrite(PIN_A, LOW);
        digitalWrite(PIN_B, LOW);
        digitalWrite(PIN_C, HIGH);
        digitalWrite(PIN_D, LOW);
        break;
      case 3:
        digitalWrite(PIN_A, LOW);
        digitalWrite(PIN_B, HIGH);
        digitalWrite(PIN_C, HIGH);
        digitalWrite(PIN_D, LOW);
        break;
      case 4:
        digitalWrite(PIN_A, LOW);
        digitalWrite(PIN_B, HIGH);
        digitalWrite(PIN_C, LOW);
        digitalWrite(PIN_D, LOW);
        break;
      case 5:
        digitalWrite(PIN_A, HIGH);
        digitalWrite(PIN_B, HIGH);
        digitalWrite(PIN_C, LOW);
        digitalWrite(PIN_D, LOW);
        break;
      case 6:
        digitalWrite(PIN_A, HIGH);
        digitalWrite(PIN_B, LOW);
        digitalWrite(PIN_C, LOW);
        digitalWrite(PIN_D, LOW);
        break;
      case 7:
        digitalWrite(PIN_A, HIGH);
        digitalWrite(PIN_B, LOW);
        digitalWrite(PIN_C, LOW);
        digitalWrite(PIN_D, HIGH);
        break;
      default:
        digitalWrite(PIN_A, LOW);
        digitalWrite(PIN_B, LOW);
        digitalWrite(PIN_C, LOW);
        digitalWrite(PIN_D, LOW);
        break;
    }

    if (direction)
    {
      step++;
    }
    else
    {
      step--;
    }

    if (step > 7)
    {
      step = 0;
      rotations += 5.625 / (63.68395) * 8;
    }
    if (step < 0)
    {
      step = 7;
      rotations -= 5.625 / (63.68395) * 8;
    }
    delayMicroseconds(delayTime);
  }
}

void getTotalAngle()
{
  angle = rotations + step * 5.625 / (63.68395);
  /*
    Serial.print("rotations: ");
    Serial.print(rotations);
    Serial.print(" step: ");
    Serial.println(step);
  */
}

void moveToAngle(double targetAngle, volatile int &moveToAngleFlag, double angle, volatile int &startStop, volatile int &direction)
{
  //Serial.println(angle - targetAngle);
  if (startStop && moveToAngleFlag)
  {
    Serial.println("Moving to angle");
    Serial.println();
    if (abs(angle - targetAngle) < 5.625 / (63.68395))
    {
      Serial.println("Reached Goal");
      saveAngle = true;
      startStop = 0;
      moveToAngleFlag = 0;
    }
    else if (angle < targetAngle)
    {
      Serial.println("Direction Set to 1");
      direction = 1;
    }
    else if (angle > targetAngle)
    {
      direction = 0;
      Serial.println("Direction Set to 0");
    }
  }
}

void zeroMotor()
{
  if (zeroMotorFlag)
  {
    unsigned long startTime = millis();
    startStop = 1;
    direction = 0;
    while (millis() < startTime + 500)
    {
      moveStepperMotor();
    }
    zeroMotorFlag = 0;
    startStop = 0;
    rotations = 0;
    step = 0;
    saveAngle = true;
  }
}

void setMotorVelocity()
{
  if (motorVelocity) {
    delayTime = round(5.625 * 1000000 / (63.68395 * motorVelocity));
    Serial.println(delayTime);
  }
  else {
    motorVelocity = 10;
  }
}
