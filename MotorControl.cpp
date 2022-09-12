#include "DEBUG.h"
#include "MotorControl.h"

#include "DEFS.h"

MotorControl::MotorControl()
{
}

void MotorControl::init()
{
  // Create the motor shield object with the default I2C address
  AFMS1 = Adafruit_MotorShield();
  // Create second object with second I2C address
  AFMS2 = Adafruit_MotorShield(0x61);

  // Setup Motorshields
  DPRINTLN("Adafruit Motorshield v2 - DC Motor test!");
  if (!AFMS1.begin())
  { // create with the default frequency 1.6KHz
    DPRINTLN("Could not find Motor Shield 1. Check wiring.");
    while (1)
      ;
  }
  DPRINTLN("Motor Shield 1 found.");

  if (!AFMS2.begin())
  { // create with the default frequency 1.6KHz
    DPRINTLN("Could not find Motor Shield 2. Check wiring.");
    while (1)
      ;
  }
  DPRINTLN("Motor Shield 2 found.");

  DPRINTLN("Setting up motors");
  for (int i = 0; i < 8; i++)
  {
    if (i < 4)
    {
      motors[i] = AFMS1.getMotor(i + 1);
      motors[i]->setSpeed(PWR_OFF);
      motors[i]->run(FORWARD);
    }
    else
    {
      motors[i] = AFMS2.getMotor(i - 3);
      motors[i]->setSpeed(PWR_OFF);
      motors[i]->run(FORWARD);
    }
  }

  DPRINTLN("Testing outputs");
  for (int i = 0; i < 8; i++)
  {
    motors[i]->setSpeed(OUT_PWR);
    delay(200);
    motors[i]->setSpeed(PWR_OFF);
  }
}

void MotorControl::turnOnMotor(int _number)
{
  motors[_number]->setSpeed(OUT_PWR);
}

void MotorControl::turnOffMotor(int _number)
{
  motors[_number]->setSpeed(PWR_OFF);
}
