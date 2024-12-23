#include "PreferenceHelper.h"

PreferenceHelper::PreferenceHelper() {
  preferences.begin(NAMESPACE, false); // Open NVS namespace in RW mode
}

PreferenceHelper::~PreferenceHelper() {
  preferences.end(); // Close the NVS namespace
}

void PreferenceHelper::storeTargetAngle(double angle) {
  preferences.begin(NAMESPACE, false);
  Serial.println(angle);
  preferences.putDouble("angle", angle);
  Serial.println(preferences.getDouble("angle", 0.0));
  preferences.end();
}
double PreferenceHelper::getTargetAngle() {
  preferences.begin(NAMESPACE, true);
  double angle = preferences.getDouble("angle", 0.0);
  preferences.end();
  return angle;
}

void PreferenceHelper::storeMoveByAngle(double moveByAngle) {
  preferences.begin(NAMESPACE, false);
  preferences.putDouble("moveByAngle", moveByAngle);
  preferences.end();
}
double PreferenceHelper::getMoveByAngle() {
  preferences.begin(NAMESPACE, true);
  double moveByAngle = preferences.getDouble("moveByAngle", 0.0);
  preferences.end();
  return moveByAngle;
}

void PreferenceHelper::storeMoveToAngleValue(double moveToAngleValue) {
  preferences.begin(NAMESPACE, false);
  preferences.putDouble("moveToAngle", moveToAngleValue);
  preferences.end();
}
double PreferenceHelper::getMoveToAngleValue() {
  preferences.begin(NAMESPACE, true);
  double moveToAngleValue = preferences.getDouble("moveToAngle", 0.0);
  preferences.end();
  return moveToAngleValue;
}

void PreferenceHelper::storeMotorVelocity(double motorVelocity) {
  preferences.begin(NAMESPACE, false);
  preferences.putDouble("motorVelocity", motorVelocity);
  preferences.end();
}
double PreferenceHelper::getMotorVelocity() {
  preferences.begin(NAMESPACE, true);
  double motorVelocity = preferences.getDouble("motorVelocity", 1.0);
  preferences.end();
  return motorVelocity;
}

void PreferenceHelper::storeRotations(double rotation) {
  preferences.begin(NAMESPACE, false);
  preferences.putDouble("rotation", rotation);
  preferences.end();
}
double PreferenceHelper::getRotations(){
  preferences.begin(NAMESPACE, true);
  double rotation = preferences.getDouble("rotation", 0.0);
  preferences.end();
  return rotation;
}

void PreferenceHelper::storeSteps(int step){
  preferences.begin(NAMESPACE, false);
  preferences.putInt("step", step);
  preferences.end();
}
int PreferenceHelper::getSteps(){
  preferences.begin(NAMESPACE, true);
  int step = preferences.getInt("step", 0);
  preferences.end();
  return step;
}
