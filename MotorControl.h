#ifndef MotorControl_h
#define MotorControl_h
#include <Adafruit_MotorShield.h>

class MotorControl
{
public:
  MotorControl();
  void init();
  void turnOnMotor(int _number);
  void turnOffMotor(int _number);

private:
  Adafruit_MotorShield AFMS1;
  Adafruit_MotorShield AFMS2;
  Adafruit_DCMotor *motors[8];
};
#endif
