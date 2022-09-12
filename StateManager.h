#ifndef StateManager_h
#define StateManager_h

#include "DEFS.h"
#include "ButtonControl.h"
#include "DisplayControl.h"
#include "State.h"

class StateManager : public ButtonListener
{
public:
  StateManager();
  void init(ButtonControl *_buttonControl, MotorControl *_motorControl, DisplayControl *_displayControl);
  void manageState();
  void buttonEvent(int _buttonIndex);

protected:
  ButtonControl *buttonControl;
  MotorControl *motorControl;
  DisplayControl *displayControl;
  State flowState;
  FillState fillState;
  State cityWaterState;
  State emptyState;
  State standByState;

  State *previousState;
  State *currentState;
};
#endif
