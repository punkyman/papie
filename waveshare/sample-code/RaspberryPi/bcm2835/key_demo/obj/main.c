#include <bcm2835.h>

#include <stdio.h>		//printf()
#include <stdlib.h>		//exit()
#include <time.h>  

#include "DEV_Config.h"
#include "LCD_Driver.h"
#include "LCD_GUI.h"
#include "LCD_Key.h"

int main(void)
{
	//1.System Initialization
	if(System_Init())
		exit(0);
	
	//2.show
	printf("**********Init LCD**********\r\n");
	LCD_SCAN_DIR LCD_ScanDir = SCAN_DIR_DFT;//SCAN_DIR_DFT = D2U_L2R
	LCD_Init(LCD_ScanDir );		
	LCD_Clear(WHITE);
	
	printf("Listen Key\r\n");
	Listen_Key();
	
	//3.System Exit
	System_Exit();
	return 0;
	
}

