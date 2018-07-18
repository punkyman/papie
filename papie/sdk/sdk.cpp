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
    
    pinMode(LCD_RST,OUTPUT);
    pinMode(LCD_DC,OUTPUT);
    pinMode(LCD_BL,OUTPUT);
    pinMode(LCD_CS,OUTPUT);

    wiringPiSPISetupMode(0, 32000000, 0);
    Renderer = new Adafruit_ST7735(LCD_CS, LCD_DC, LCD_RST);
 
    return 0;
}    

} // SDK
