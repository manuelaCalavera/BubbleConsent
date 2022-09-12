#ifndef DEFS_h
#define DEFS_h

/////////////////////// Buttons ///////////////////////
#define NUMBER_OF_BUTTONS 4
#define BUTTONS A0, A1, 4, 27

#define FLOW_BUTTON_INDEX 0
#define FILL_BUTTON_INDEX 1
#define CITYWATER_BUTTON_INDEX 2

#define BUTTEN_EVENT_PRESS 0
#define BUTTEN_EVENT_LONG_PRESS 1
#define BUTTEN_EVENT_DOWN 2
#define BUTTEN_EVENT_UP 3

#define BUTTON_MAX_SHORT_PRESS 500
#define BUTTON_MAX_LONG_PRESS 2000

/////////////////////// Valves ///////////////////////
#define NUMBER_OF_VALVES 7
#define FLOW_STATE_VALVES 1, 0, 0, 0, 1, 0, 0
#define FILL_STATE_VALVES 0, 1, 0, 0, 0, 1, 0
#define CITYWATER_STATE_VALVES 0, 0, 0, 1, 0, 0, 0
#define EMPTY_STATE_VALVES 1, 1, 0, 0, 1, 1, 0
#define STANDBY_STATE_VALVES 0, 0, 0, 0, 0, 0, 0

#define OUT_PWR_BOOST 255
#define OUT_PWR 127
#define PWR_OFF 0

/////////////////////// States ///////////////////////
#define STANDBY_STATE_INDEX 0
#define FLOW_STATE_INDEX 1
#define FILL_STATE_INDEX 2
#define CITYWATER_STATE_INDEX 3
#define EMPTY_STATE_INDEX 4

#define SECOND_PUMP_MOTOR 7

/////////////////////// Display ///////////////////////
#define BOTTLE_IMAGE_HEIGHT 106
#define BOTTLE_IMAGE_WIDTH 61
#define BOTTLE_IMAGE_PATH "/icons/fillbottle/"
#define BOTTLE_0 "/icons/fillbottle/0.bmp"
#define BOTTLE_10 "/icons/fillbottle/10.bmp"
#define BOTTLE_20 "/icons/fillbottle/20.bmp"
#define BOTTLE_30 "/icons/fillbottle/30.bmp"
#define BOTTLE_40 "/icons/fillbottle/40.bmp"
#define BOTTLE_50 "/icons/fillbottle/50.bmp"
#define BOTTLE_60 "/icons/fillbottle/60.bmp"
#define BOTTLE_70 "/icons/fillbottle/70.bmp"
#define BOTTLE_80 "/icons/fillbottle/80.bmp"
#define BOTTLE_90 "/icons/fillbottle/90.bmp"
#define BOTTLE_100 "/icons/fillbottle/100.bmp"

#define STATE_IMAGE_HEIGHT 119
#define STATE_IMAGE_CITY "/icons/states/city.bmp"
#define STATE_IMAGE_EMPTY "/icons/states/empty.bmp"
#define STATE_IMAGE_FILL "/icons/states/fill.bmp"
#define STATE_IMAGE_FLOW "/icons/states/flow.bmp"

#define IMAGE_HEIHGT_DIFF 8

#endif
