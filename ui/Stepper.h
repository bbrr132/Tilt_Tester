#ifndef STEPPER_H
#define STEPPER_H

#include "PreferenceHelper.h"

#define PIN_A 17
#define PIN_B 16
#define PIN_C 4
#define PIN_D 22 //SCL

extern volatile int direction;
extern volatile int startStop;
extern volatile double targetAngle;
extern volatile int moveToAngleFlag;
extern volatile int step;
extern volatile double rotations;
extern volatile double angle;
extern volatile int zeroMotorFlag;
extern volatile int delayTime;
extern volatile double motorVelocity;
extern volatile double moveByAngle;
extern volatile double moveToAngleValue;
extern PreferenceHelper prefHelper;
extern bool saveAngle;
void getTotalAngle();
void moveStepperMotor();
void setupStepperMotor();
void moveToAngle(double targetAngle, volatile int &moveToAngleFlag, double angle, volatile int &startStop, volatile int &direction);
void zeroMotor();
void setMotorVelocity();

#endif
