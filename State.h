#ifndef State_h
#define State_h

#include "DEFS.h"
#include "MotorControl.h"
#include "ButtonControl.h"

class State
{
public:
  State();
  void init(int _index, MotorControl *_motorControl, String _stateName, bool _states[]);
  int getIndex();
  virtual void enterState();
  virtual void loopState();
  virtual void exitState();

protected:
  MotorControl *motorControl;
  bool valveStates[NUMBER_OF_VALVES];
  int index;
  String stateName;
};

class FillState : public State, public ButtonListener
{
public:
  void init(int _index, MotorControl *_motorControl, ButtonControl *_buttonControl, String _stateName, bool _states[]);
  void enterState();
  void exitState();
  void buttonEvent(int _buttonIndex);

private:
  ButtonControl *buttonControl;
  bool fillStateActive;
  bool pumpIsOn;
};

#endif
