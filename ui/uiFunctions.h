#include "PreferenceHelper.h"
PreferenceHelper prefHelper;

bool uiReady = false;
void KeyboardDone(lv_event_t * e)
{
  if (lv_keyboard_get_textarea(ui_Keyboard1) == ui_MoveToAngleTextArea) {
    moveToAngleValue = (double)atof(lv_textarea_get_text(ui_MoveToAngleTextArea));
    targetAngle = moveToAngleValue;
    Serial.println(targetAngle);
  }
  if (lv_keyboard_get_textarea(ui_Keyboard1) == ui_MoveByAngleTextArea) {
    moveByAngle = atof(lv_textarea_get_text(ui_MoveByAngleTextArea));
    Serial.println(moveByAngle);
  }
  if (lv_keyboard_get_textarea(ui_Keyboard1) == ui_VelocityTextArea) {
    motorVelocity = atof(lv_textarea_get_text(ui_VelocityTextArea));
    setMotorVelocity();
    Serial.println(motorVelocity);
  }
  
  prefHelper.storeMoveByAngle(moveByAngle);
  prefHelper.storeMoveToAngleValue(moveToAngleValue);
  prefHelper.storeMotorVelocity(motorVelocity);
}
void ZeroButton(lv_event_t * e)
{
  Serial.println("Zeroing");
  zeroMotorFlag = true;
}

void MoveToAngleButton(lv_event_t * e)
{
  Serial.println("MoveToAngle");
  targetAngle = moveToAngleValue;
  startStop = true;
  moveToAngleFlag = true;
}
void MoveByAngleButton(lv_event_t * e)
{
  Serial.println("MoveByAngle");
  if (!startStop && !moveToAngleFlag) {
    targetAngle = angle + moveByAngle;
    startStop = true;
    moveToAngleFlag = true;
  }
}
