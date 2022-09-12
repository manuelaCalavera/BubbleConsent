#include "DisplayControl.h"

#include "DEBUG.h"

DisplayControl::DisplayControl() : reader(SD),
                                   display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY)
{
}

void DisplayControl::init()
{
    display.begin();
    display.clearBuffer();
    display.fillScreen(EPD_WHITE);
    if (!SD.begin(SD_CS, SD_SCK_MHZ(10)))
    { // Breakouts require 10 MHz limit due to longer wires
        DPRINTLN(F("SD begin() failed"));
        display.setCursor(10, 100);
        display.println("SD failed!");
        display.display();
        for (;;)
            ; // Fatal error, do not continue
    }
    display.setCursor(10, 100);
    display.println("Welcome =)");
    display.display();
    DPRINTLN("Display init OK!");
    /// todo implement bottle logic
    strcpy(currentFillFile, BOTTLE_30);
}

void DisplayControl::updateState(int _state)
{
    switch (_state)
    {
    case FLOW_STATE_INDEX:
        strcpy(currentStateFile, STATE_IMAGE_FLOW);
        break;
    case FILL_STATE_INDEX:
        strcpy(currentStateFile, STATE_IMAGE_FILL);
        break;
    case CITYWATER_STATE_INDEX:
        strcpy(currentStateFile, STATE_IMAGE_CITY);
        break;
    case EMPTY_STATE_INDEX:
        strcpy(currentStateFile, STATE_IMAGE_EMPTY);
        break;
    }
    updateDisplay();
}

void DisplayControl::updateWaterLevel(int _level)
{
    switch (_level)
    {
    case 0:
        strcpy(currentFillFile, BOTTLE_0);
        break;
    case 10:
        strcpy(currentFillFile, BOTTLE_10);
        break;
    case 20:
        strcpy(currentFillFile, BOTTLE_20);
        break;
    case 30:
        strcpy(currentFillFile, BOTTLE_30);
        break;
    case 40:
        strcpy(currentFillFile, BOTTLE_40);
        break;
    case 50:
        strcpy(currentFillFile, BOTTLE_50);
        break;
    case 60:
        strcpy(currentFillFile, BOTTLE_60);
        break;
    case 70:
        strcpy(currentFillFile, BOTTLE_70);
        break;
    case 80:
        strcpy(currentFillFile, BOTTLE_80);
        break;
    case 90:
        strcpy(currentFillFile, BOTTLE_90);
        break;
    case 100:
        strcpy(currentFillFile, BOTTLE_100);
        break;
    }
    updateDisplay();
}

void DisplayControl::updateDisplay()
{
    ImageReturnCode stat; // Status from image-reading functions
    display.clearBuffer();
    if (currentStateFile[0] != 0)
    {
        DPRINT("Loading ");
        DPRINT(currentStateFile);
        DPRINTLN(" to canvas...");
        stat = reader.drawBMP(currentStateFile, display, 30, display.height() - 0 - STATE_IMAGE_HEIGHT);
        reader.printStatus(stat); // How'd we do?
    }
    if (currentFillFile[0] != 0)
    {
        DPRINT("Loading ");
        DPRINT(currentFillFile);
        DPRINTLN(" to canvas...");
        stat = reader.drawBMP(currentFillFile, display, display.width() - 30 - BOTTLE_IMAGE_WIDTH, display.height() - IMAGE_HEIHGT_DIFF - BOTTLE_IMAGE_HEIGHT);
        reader.printStatus(stat); // How'd we do?
    }
    display.display();
}