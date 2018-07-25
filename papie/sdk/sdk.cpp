#include "sdk.h"

#include <wiringPi.h>
#include "hardware.h"
#include "Renderer/driver/Adafruit_ST7735.h"

namespace SDK
{

int init()
{
    if(wiringPiSetupGpio() < 0)
        return 1;

    // unused by the display driver, but it does exist on hardware    
    pinMode(LCD_BL,OUTPUT);

    wiringPiSPISetupMode(0, 32000000, 0);
    Renderer = new Adafruit_ST7735(LCD_CS, LCD_DC, LCD_RST);
 
    return 0;
}    

} // SDK
