#ifndef PREFERENCEHELPER_H
#define PREFERENCEHELPER_H

#include <Preferences.h>

class PreferenceHelper {
  public:
    PreferenceHelper();
    ~PreferenceHelper();

    void storeTargetAngle(double targetAngle);
    double getTargetAngle();

    void storeRotations(double rotation);
    double getRotations();

    void storeSteps(int step);
    int getSteps();

    void storeMoveByAngle(double moveByAngle);
    double getMoveByAngle();
    
    void storeMoveToAngleValue(double moveToAngleValue);
    double getMoveToAngleValue();
    
    void storeMotorVelocity(double motorVelocity);
    double getMotorVelocity();
    
  private:
    Preferences preferences;
    const char* NAMESPACE = "profile_data";
};

#endif // PREFERENCEHELPER_H
