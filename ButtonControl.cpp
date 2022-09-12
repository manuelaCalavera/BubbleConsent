#include "DEBUG.h"
#include "ButtonControl.h"

ButtonControl::ButtonControl()
{
}

void ButtonControl::init()
{
  // Setup Inputs
  for (int i = 0; i < NUMBER_OF_BUTTONS; ++i)
  {
    pinMode(pins[i], INPUT_PULLUP);
    previousButtonState[i] = 1;
  }
}

void ButtonControl::checkButtonStates()
{
  // DPRINTLN("checking button states");
  int now = millis();
  for (int i = 0; i < NUMBER_OF_BUTTONS; ++i)
  {
    int currentState = digitalRead(pins[i]);
    int stateDiff = currentState - previousButtonState[i];

    switch (stateDiff)
    {
    case 1:
    {
      // button up
      lastButtonUpMillis[i] = now;
      unsigned long pressDuration = lastButtonUpMillis[i] - lastButtonDownMillis[i];
      if (pressDuration < long(BUTTON_MAX_SHORT_PRESS))
      {
        DPRINTLN("short press");
        for (int p = 0; p < pressListeners.size(); ++p)
        {
          pressListeners.get(p)->buttonEvent(i);
        }
      }
      else if (pressDuration > BUTTON_MAX_SHORT_PRESS && pressDuration < BUTTON_MAX_LONG_PRESS)
      {
        DPRINTLN("long press");
        for (int l = 0; l < longPressListeners.size(); ++l)
        {
          longPressListeners.get(l)->buttonEvent(i);
        }
      }
      break;
    }

    case 0:
    { // no change
      break;
    }

    case -1:
    { // button down
      DPRINTLN("btn down");
      lastButtonDownMillis[i] = now;
      break;
    }
    }
    previousButtonState[i] = currentState;
  }
}

void ButtonControl::registerForButtonPress(ButtonListener *_listener)
{
  DPRINTLN("Button Listener registered");
  pressListeners.add(_listener);
}
void ButtonControl::registerForLongButtonPress(ButtonListener *_listener)
{
  longPressListeners.add(_listener);
}

ButtonListener::ButtonListener() {}
