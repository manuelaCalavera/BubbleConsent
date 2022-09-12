#include "DEBUG.h"
#include "StateManager.h"

#include "DEFS.h"

StateManager::StateManager()
{
}

void StateManager::init(ButtonControl *_buttonControl, MotorControl *_motorControl, DisplayControl *_displayControl)
{
  DPRINTLN("StateManager init");
  buttonControl = _buttonControl;
  motorControl = _motorControl;
  displayControl = _displayControl;

  bool flowStateArray[NUMBER_OF_VALVES] = {FLOW_STATE_VALVES};
  flowState.init(FLOW_STATE_INDEX, motorControl, String("FLOW"), flowStateArray);

  bool fillStateArray[NUMBER_OF_VALVES] = {FILL_STATE_VALVES};
  fillState.init(FILL_STATE_INDEX, motorControl, buttonControl, String("FILL"), fillStateArray);

  bool cityWaterStateArray[NUMBER_OF_VALVES] = {CITYWATER_STATE_VALVES};
  cityWaterState.init(CITYWATER_STATE_INDEX, motorControl, String("CITYWATER"), cityWaterStateArray);

  bool emptyStateArray[NUMBER_OF_VALVES] = {EMPTY_STATE_VALVES};
  emptyState.init(EMPTY_STATE_INDEX, motorControl, String("EMPTY"), emptyStateArray);

  bool standByStateArray[NUMBER_OF_VALVES] = {STANDBY_STATE_VALVES};
  standByState.init(STANDBY_STATE_INDEX, motorControl, String("STANDBY"), standByStateArray);

  buttonControl->registerForButtonPress(this);
  standByState.enterState();

  currentState = &standByState;
  previousState = &standByState;
}

void StateManager::manageState()
{
  currentState->loopState();
}

void StateManager::buttonEvent(int _buttonIndex)
{
  switch (_buttonIndex)
  {
  case FLOW_BUTTON_INDEX:
    currentState = &flowState;
    break;
  case FILL_BUTTON_INDEX:
    currentState = &fillState;
    break;
  case CITYWATER_BUTTON_INDEX:
    currentState = &cityWaterState;
    ;
    break;
  }

  if (currentState->getIndex() != previousState->getIndex())
  {
    previousState->exitState();
    currentState->enterState();
    displayControl->updateState(currentState->getIndex());
    previousState = currentState;
  }
}
