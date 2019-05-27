#include "stdlib.h"
#include "math.h"
//#include "main.h"
#include "stm32f4xx_hal.h"

#define TP_PRES_DOWN 0x80
#define TP_CATH_PRES 0x40

typedef struct
{
	uint8_t (*init)(void);
	uint8_t (*scan)(uint8_t);
	//void (*adjust)(void);
	uint16_t x0;
	uint16_t y0;
	uint16_t x;
	uint16_t y;
	uint8_t  sta;


	float xfac;
	float yfac;
	short xoff;
	short yoff;

	uint8_t touchtype;
}_m_tp_dev;

extern _m_tp_dev tp_dev;

//#define PEN  		PBin(1)  	//T_PEN
#define T_IRQ		HAL_GPIO_ReadPin(T_IRQ_GPIO_Port, T_IRQ_Pin)

//#define T_DO 		PBin(2)   	//T_MISO
#define T_DO_ON		HAL_GPIO_WritePin(T_DO_GPIO_Port, T_DO_Pin, GPIO_PIN_SET)
#define T_DO_OFF	HAL_GPIO_WritePin(T_DO_GPIO_Port, T_DO_Pin, GPIO_PIN_RESET)
#define T_DO		HAL_GPIO_ReadPin(T_DO_GPIO_Port, T_DO_Pin)

//#define T_DIN 	PFout(11)  	//T_MOSI
#define T_DIN_ON	HAL_GPIO_WritePin(T_DIN_GPIO_Port, T_DIN_Pin, GPIO_PIN_SET)
#define T_DIN_OFF	HAL_GPIO_WritePin(T_DIN_GPIO_Port, T_DIN_Pin, GPIO_PIN_RESET)

//#define T_CLK 	PBout(0)  	//T_SCK
#define T_CLK_ON	HAL_GPIO_WritePin(T_CLK_GPIO_Port, T_CLK_Pin, GPIO_PIN_SET)
#define T_CLK_OFF	HAL_GPIO_WritePin(T_CLK_GPIO_Port, T_CLK_Pin, GPIO_PIN_RESET)

//#define TCS  		PCout(5)  	//T_CS
#define T_CS_ON		HAL_GPIO_WritePin(T_CS_GPIO_Port, T_CS_Pin, GPIO_PIN_SET)
#define T_CS_OFF	HAL_GPIO_WritePin(T_CS_GPIO_Port, T_CS_Pin, GPIO_PIN_RESET)

void TP_Write_Byte(uint8_t num);
uint16_t TP_Read_AD(uint8_t CMD);
uint16_t TP_Read_XOY(uint8_t xy);
uint8_t TP_Read_XY(uint16_t *x,uint16_t *y);
uint8_t TP_Read_XY2(uint16_t *x,uint16_t *y);
void TP_Drow_Touch_Point(uint16_t x,uint16_t y,uint16_t color);
void TP_Draw_Big_Point(uint16_t x,uint16_t y,uint16_t color);
uint8_t TP_Scan(uint8_t tp);
void TP_Save_Adjdata(void);
uint8_t TP_Get_Adjdata(void);
void TP_Adjust(void);
uint8_t TP_Init(void);

void TP_Adj_Info_Show(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t x3,uint16_t y3,uint16_t fac);
