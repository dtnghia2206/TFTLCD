#include "stm32f4xx_hal.h"
#include <stdlib.h>
#include "main.h"

#define  RESET_OFF 		HAL_GPIO_WritePin(GPIOA,RESET_Pin,GPIO_PIN_SET)
#define  RESET_ON 		HAL_GPIO_WritePin(GPIOA,RESET_Pin,GPIO_PIN_RESET)
#define  CS_OFF 		HAL_GPIO_WritePin(GPIOA,CS_Pin,GPIO_PIN_SET)
#define  CS_ON 			HAL_GPIO_WritePin(GPIOA,CS_Pin,GPIO_PIN_RESET)
#define  DC_DATA 		HAL_GPIO_WritePin(GPIOA,DC_Pin,GPIO_PIN_SET)
#define  DC_COMMAND 	HAL_GPIO_WritePin(GPIOA,DC_Pin,GPIO_PIN_RESET)

#define BLACK       	0x0000
#define NAVY        	0x000F
#define DARKGREEN   	0x03E0
#define DARKCYAN    	0x03EF
#define MAROON      	0x7800
#define PURPLE      	0x780F
#define OLIVE       	0x7BE0
#define LIGHTGREY   	0xC618
#define DARKGREY    	0x7BEF
#define BLUE        	0x001F
#define GREEN       	0x07E0
#define CYAN        	0x07FF
#define RED         	0xF800
#define MAGENTA     	0xF81F
#define YELLOW      	0xFFE0
#define WHITE       	0xFFFF
#define ORANGE      	0xFD20
#define GREENYELLOW 	0xAFE5
#define PINK        	0xF81F

#define swap(a,b) 		{int16_t t=a;a=b;b=t;}
#define BURST_MAX_SIZE 	500

void Show_Menu(void);
void ILI9341_Init(void);
void ILI9341_Reset(void);
void ILI9341_Set_Rotation(unsigned char rotation);
void ILI9341_Fill_Screen(unsigned int color);

void ILI9341_Draw_Pixel(int x, int y, unsigned int color);
void ILI9341_Draw_Double_Pixel(int x, int y, unsigned int color1, unsigned int color2);
void ILI9341_Draw_Circle(unsigned int x0, unsigned int y0, int r, unsigned int color, unsigned char flood);
void ILI9341_Draw_Line(unsigned int color, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
void ILI9341_Draw_Filled_Rectangle(unsigned int color,unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
void ILI9341_Draw_Empty_Rectangle(unsigned int color,unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
void ILI9341_Draw_String(unsigned int x, unsigned int y, unsigned int color, unsigned int phone, char *str, unsigned char size);
