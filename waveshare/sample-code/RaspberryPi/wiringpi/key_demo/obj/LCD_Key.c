#include "LCD_Key.h"
#include "LCD_GUI.h"
#include "DEV_Config.h"

void Draw_Init(void)
{
	//Press
	GUI_DrawCircle(45, 64, 15, RED, DRAW_EMPTY, DOT_PIXEL_DFT);	
	GUI_DisString_EN(40, 58, "P", &Font16, GUI_BACKGROUND, BLUE);
	
	//Left
	GUI_DrawRectangle(0, 49, 30, 79, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
	GUI_DisString_EN(10, 58, "L", &Font16, GUI_BACKGROUND, BLUE);
	
	//Down
	GUI_DrawRectangle(30, 79, 60, 109, RED, DRAW_EMPTY, DOT_PIXEL_DFT);	
	GUI_DisString_EN(40, 88, "D", &Font16, GUI_BACKGROUND, BLUE);
	
	//Right
	GUI_DrawRectangle(60, 49, 90, 79, RED, DRAW_EMPTY, DOT_PIXEL_DFT);	
	GUI_DisString_EN(70, 58, "R", &Font16, GUI_BACKGROUND, BLUE);
	
	//Up
	GUI_DrawRectangle(30, 19, 60, 49, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
	GUI_DisString_EN(40, 28, "U", &Font16, GUI_BACKGROUND, BLUE);
	
	//Key1
	GUI_DrawRectangle(95, 20, 125, 45, RED, DRAW_EMPTY, DOT_PIXEL_DFT);	
	GUI_DisString_EN(100, 27, "K1", &Font16, GUI_BACKGROUND, BLUE);
	
	//Key2	
	GUI_DrawRectangle(95, 52, 125, 78, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
	GUI_DisString_EN(100, 59, "K2", &Font16, GUI_BACKGROUND, BLUE);
	
	//Key3
	GUI_DrawRectangle(95, 85, 125, 110, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
	GUI_DisString_EN(100, 92, "K3", &Font16, GUI_BACKGROUND, BLUE);	
}

void Listen_Key(void)
{
	for(;;){
		Draw_Init();	
		if(GET_KEY_UP == 0){
			while(GET_KEY_UP == 0){
				GUI_DrawRectangle(30, 19, 60, 49, RED, DRAW_FULL, DOT_PIXEL_DFT);
				GUI_DisString_EN(40, 28, "U", &Font16, GUI_BACKGROUND, BLUE);
				Driver_Delay_ms(500);
			}		
			GUI_DrawRectangle(30, 19, 60, 49, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
		}
		if(GET_KEY_DOWN == 0){
			while(GET_KEY_DOWN == 0){
				GUI_DrawRectangle(30, 79, 60, 109, RED, DRAW_FULL, DOT_PIXEL_DFT);	
				GUI_DisString_EN(40, 88, "D", &Font16, GUI_BACKGROUND, BLUE);
				Driver_Delay_ms(500);
			}		
			GUI_DrawRectangle(30, 79, 60, 109, WHITE, DRAW_FULL, DOT_PIXEL_DFT);	
		}
		if(GET_KEY_LEFT == 0){
			while(GET_KEY_LEFT == 0){
				GUI_DrawRectangle(0, 49, 30, 79, RED, DRAW_FULL, DOT_PIXEL_DFT);
				GUI_DisString_EN(10, 58, "L", &Font16, GUI_BACKGROUND, BLUE);
				Driver_Delay_ms(500);
			}		
			GUI_DrawRectangle(0, 49, 30, 79, WHITE, DRAW_FULL, DOT_PIXEL_DFT);	
		}
		if(GET_KEY_RIGHT == 0){
			while(GET_KEY_RIGHT == 0){
				GUI_DrawRectangle(60, 49, 90, 79, RED, DRAW_FULL, DOT_PIXEL_DFT);	
				GUI_DisString_EN(70, 58, "R", &Font16, GUI_BACKGROUND, BLUE);
				Driver_Delay_ms(500);
			}		
			GUI_DrawRectangle(60, 49, 90, 79, WHITE, DRAW_FULL, DOT_PIXEL_DFT);	
		}
		if(GET_KEY_PRESS == 0){
			while(GET_KEY_PRESS == 0){
				GUI_DrawCircle(45, 64, 15, RED, DRAW_FULL, DOT_PIXEL_DFT);	
				GUI_DisString_EN(40, 58, "P", &Font16, GUI_BACKGROUND, BLUE);
				Driver_Delay_ms(500);
			}		
			GUI_DrawCircle(45, 64, 15, WHITE, DRAW_FULL, DOT_PIXEL_DFT);	
		}
		if(GET_KEY1 == 0){
			while(GET_KEY1 == 0){
				GUI_DrawRectangle(95, 20, 125, 45, RED, DRAW_FULL, DOT_PIXEL_DFT);	
				GUI_DisString_EN(100, 27, "K1", &Font16, GUI_BACKGROUND, BLUE);
				Driver_Delay_ms(500);
			}		
			GUI_DrawRectangle(95, 20, 125, 45, WHITE, DRAW_FULL, DOT_PIXEL_DFT);	
		}
		if(GET_KEY2 == 0){
			while(GET_KEY2 == 0){
				GUI_DrawRectangle(95, 52, 125, 78, RED, DRAW_FULL, DOT_PIXEL_DFT);	
				GUI_DisString_EN(100, 59, "K2", &Font16, GUI_BACKGROUND, BLUE);
				Driver_Delay_ms(500);
			}		
			GUI_DrawRectangle(95, 52, 125, 78, WHITE, DRAW_FULL, DOT_PIXEL_DFT);	
		}
		if(GET_KEY3 == 0){
			while(GET_KEY3 == 0){
				GUI_DrawRectangle(95, 85, 125, 110, RED, DRAW_FULL, DOT_PIXEL_DFT);	
				GUI_DisString_EN(100, 92, "K3", &Font16, GUI_BACKGROUND, BLUE);
				Driver_Delay_ms(500);
			}		
			GUI_DrawRectangle(95, 85, 125, 110, WHITE, DRAW_FULL, DOT_PIXEL_DFT);	
		}
	}
	
}