#include "DEBUG.h"
#include "State.h"

State::State() {}

void State::init(int _index, MotorControl *_motorControl, String _stateName, bool _states[])
{
  motorControl = _motorControl;
  memcpy(valveStates, _states, sizeof(bool) * NUMBER_OF_VALVES);
  stateName = _stateName;
  index = _index;
}

int State::getIndex()
{
  return index;
}

void State::enterState()
{
  DPRINT("entering State: ");
  DPRINTLN(stateName);
  DPRINTLN("\n");
  for (int i = 0; i < NUMBER_OF_VALVES; i++)
  {
    if (valveStates[i])
    {
      motorControl->turnOnMotor(i);
    }
    else if (!valveStates[i])
    {
      motorControl->turnOffMotor(i);
    }
  }
}
void State::exitState()
{
}

void State::loopState()
{
}

void FillState::init(int _index, MotorControl *_motorControl, ButtonControl *_buttonControl, String _stateName, bool _states[])
{
  State::init(_index, _motorControl, _stateName, _states);
  buttonControl = _buttonControl;
  fillStateActive = false;
  pumpIsOn = false;
  buttonControl->registerForButtonPress(this);
  DPRINTLN("fillstate init");
}

void FillState::enterState()
{
  State::enterState();
  fillStateActive = true;
  pumpIsOn = false;
}

void FillState::buttonEvent(int _buttonIndex)
{
  if (fillStateActive && _buttonIndex == FILL_BUTTON_INDEX)
  {
    if (!pumpIsOn)
    {
      motorControl->turnOnMotor(SECOND_PUMP_MOTOR);
      pumpIsOn = true;
    }
    else if (pumpIsOn)
    {
      motorControl->turnOffMotor(SECOND_PUMP_MOTOR);
      pumpIsOn = false;
    }
  }
}

void FillState::exitState()
{
  State::exitState();
  motorControl->turnOffMotor(SECOND_PUMP_MOTOR);
  pumpIsOn = false;
  fillStateActive = false;
}