#ifndef DisplayControl_h
#define DisplayControl_h
#include <Adafruit_GFX.h> // Core graphics library
#include "Adafruit_ThinkInk.h"
#include <SdFat.h>                    // SD card & FAT filesystem library
#include <Adafruit_ImageReader_EPD.h> // Image-reading functions

#define SD_CS 14
#define SRAM_CS 32
#define EPD_CS 15
#define EPD_DC 33
#define EPD_RESET -1 // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY -1  // can set to -1 to not use a pin (will wait a fixed delay)

#include "DEFS.h"

class DisplayControl
{
public:
    DisplayControl();
    void init();
    void updateState(int _state);
    void updateWaterLevel(int _level);

private:
    ThinkInk_290_Grayscale4_T5 display;
    SdFat SD;                        // SD card filesystem
    Adafruit_ImageReader_EPD reader; // Image-reader object, pass in SD filesys
    char currentStateFile[80] = {0};
    char currentFillFile[80] = {0};
    void updateDisplay();
};
#endif