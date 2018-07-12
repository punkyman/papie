
import LCD_1in44
import LCD_Config
import RPi.GPIO as GPIO

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
from PIL import ImageColor

LCD = LCD_1in44.LCD()
image = Image.new("RGB", (LCD.LCD_Dis_Column, LCD.LCD_Dis_Page), "WHITE")
draw = ImageDraw.Draw(image)
font = ImageFont.truetype('cambriab.ttf', 16)

class KEY():
	def Draw_Init(self):
		LCD.LCD_Init(LCD_1in44.SCAN_DIR_DFT)
		#Press
		draw.ellipse((30, 49, 60, 79), 'WHITE', 'RED')   
		draw.text((40, 53), 'P', fill = "BLUE",font = font)

		#Left
		draw.rectangle([(0, 49),(30, 79)],'WHITE', 'RED')
		draw.text((10, 53), 'L', fill = "BLUE",font = font)
		
		#Down
		draw.rectangle([(30, 79),(60, 109)],'WHITE', 'RED')
		draw.text((40, 83), 'D', fill = "BLUE",font = font)
		
		#Right
		draw.rectangle([(60, 49),(90, 79)],'WHITE', 'RED')
		draw.text((70, 53), 'R', fill = "BLUE",font = font)
		
		#Up
		draw.rectangle([(30, 19),(60, 49)],'WHITE', 'RED')
		draw.text((40, 23), 'U', fill = "BLUE",font = font)

		#Key1
		draw.rectangle([(95, 20),(125, 45)],'WHITE', 'RED')
		draw.text((100, 23), 'K1', fill = "BLUE",font = font)

		#Key2	
		draw.rectangle([(95, 52),(125, 78)],'WHITE', 'RED')
		draw.text((100, 55), 'K2', fill = "BLUE",font = font)
		
		#Key3
		draw.rectangle([(95, 85),(125, 110)],'WHITE', 'RED')
		draw.text((100, 87), 'K3', fill = "BLUE",font = font)
		
		LCD.LCD_ShowImage(image,0,0)

	def Listen_Key(self):
		self.Draw_Init()
		while(True):
			if GPIO.input(LCD_Config.KEY_UP_PIN) == 0:
				draw.rectangle([(30, 19),(60, 49)],'RED', 'RED')
				LCD.LCD_ShowImage(image,0,0)
				while(LCD_Config.KEY_UP_PIN == 0):
					LCD_Config.Driver_Delay_ms(300)
				draw.rectangle([(30, 19),(60, 49)],'WHITE', 'RED')
				draw.text((40, 23), 'U', fill = "BLUE",font = font)	
				LCD.LCD_ShowImage(image,0,0)
			if GPIO.input(LCD_Config.KEY_DOWN_PIN) == 0:
				draw.rectangle([(30, 79),(60, 109)],'RED', 'RED')
				LCD.LCD_ShowImage(image,0,0)
				while(LCD_Config.KEY_DOWN_PIN == 0):
					LCD_Config.Driver_Delay_ms(300)
				draw.rectangle([(30, 79),(60, 109)],'WHITE', 'RED')
				draw.text((40, 83), 'D', fill = "BLUE",font = font)
				LCD.LCD_ShowImage(image,0,0)
			if GPIO.input(LCD_Config.KEY_LEFT_PIN) == 0:
				draw.rectangle([(0, 49),(30, 79)],'RED', 'RED')
				LCD.LCD_ShowImage(image,0,0)
				while(LCD_Config.KEY_LEFT_PIN == 0):
					LCD_Config.Driver_Delay_ms(300)
				draw.rectangle([(0, 49),(30, 79)],'WHITE', 'RED')
				draw.text((10, 53), 'L', fill = "BLUE",font = font)
				LCD.LCD_ShowImage(image,0,0)
			if GPIO.input(LCD_Config.KEY_RIGHT_PIN) == 0:
				draw.rectangle([(60, 49),(90, 79)],'RED', 'RED')
				LCD.LCD_ShowImage(image,0,0)
				while(LCD_Config.KEY_RIGHT_PIN == 0):
					LCD_Config.Driver_Delay_ms(300)
				draw.rectangle([(60, 49),(90, 79)],'WHITE', 'RED')
				draw.text((70, 53), 'R', fill = "BLUE",font = font)
				LCD.LCD_ShowImage(image,0,0)
			if GPIO.input(LCD_Config.KEY_PRESS_PIN) == 0:
				draw.ellipse((30, 49, 60, 79), 'RED', 'RED')
				LCD.LCD_ShowImage(image,0,0)
				while(LCD_Config.KEY_PRESS_PIN == 0):
					LCD_Config.Driver_Delay_ms(300)
				draw.ellipse((30, 49, 60, 79), 'WHITE', 'RED')   
				draw.text((40, 53), 'P', fill = "BLUE",font = font)
				LCD.LCD_ShowImage(image,0,0)
			if GPIO.input(LCD_Config.KEY1_PIN) == 0:
				draw.rectangle([(95, 20),(125, 45)],'RED', 'RED')
				LCD.LCD_ShowImage(image,0,0)
				while(LCD_Config.KEY1_PIN == 0):
					LCD_Config.Driver_Delay_ms(300)
				draw.rectangle([(95, 20),(125, 45)],'WHITE', 'RED')
				draw.text((100, 23), 'K1', fill = "BLUE",font = font)
				LCD.LCD_ShowImage(image,0,0)
			if GPIO.input(LCD_Config.KEY2_PIN) == 0:
				draw.rectangle([(95, 52),(125, 78)],'RED', 'RED')
				LCD.LCD_ShowImage(image,0,0)
				while(LCD_Config.KEY2_PIN == 0):
					LCD_Config.Driver_Delay_ms(300)
				draw.rectangle([(95, 52),(125, 78)],'WHITE', 'RED')
				draw.text((100, 55), 'K2', fill = "BLUE",font = font)
				LCD.LCD_ShowImage(image,0,0)
			if GPIO.input(LCD_Config.KEY3_PIN) == 0:
				draw.rectangle([(95, 85),(125, 110)],'RED', 'RED')
				LCD.LCD_ShowImage(image,0,0)
				while(LCD_Config.KEY3_PIN == 0):
					LCD_Config.Driver_Delay_ms(300)
				draw.rectangle([(95, 85),(125, 110)],'WHITE', 'RED')
				draw.text((100, 87), 'K3', fill = "BLUE",font = font)		
				LCD.LCD_ShowImage(image,0,0)				
