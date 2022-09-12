#ifndef ButtonControl_h
#define ButtonControl_h

#include "DEFS.h"
#include <LinkedPointerList.h>
#include "Arduino.h"

class ButtonListener
{
public:
  ButtonListener();
  virtual void buttonEvent(int _buttonIndex){};
};

class ButtonControl
{
public:
  ButtonControl();
  void init();
  void checkButtonStates();
  void registerForButtonPress(ButtonListener *_listener);
  void registerForLongButtonPress(ButtonListener *_listener);

private:
  uint8_t pins[NUMBER_OF_BUTTONS] = {BUTTONS};
  unsigned long lastButtonDownMillis[NUMBER_OF_BUTTONS];
  unsigned long lastButtonUpMillis[NUMBER_OF_BUTTONS];
  int previousButtonState[NUMBER_OF_BUTTONS];
  LinkedPointerList<ButtonListener> pressListeners;
  LinkedPointerList<ButtonListener> longPressListeners;
};
#endif
