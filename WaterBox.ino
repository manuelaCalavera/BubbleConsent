#include "DEBUG.h"
#include "MotorControl.h"
#include "ButtonControl.h"
#include "StateManager.h"
#include "DisplayControl.h"
#include "State.h"
#include <Adafruit_MotorShield.h>

MotorControl motorControl;
ButtonControl buttonControl;
DisplayControl displayControl;
StateManager stateManager;

void setup()
{
  Serial.begin(115200); // set up Serial library at 9600 bps

  motorControl.init();
  buttonControl.init();
  displayControl.init();
  stateManager.init(&buttonControl, &motorControl, &displayControl);
}

void loop()
{
  buttonControl.checkButtonStates();
  stateManager.manageState();
}
