#include <display.h>
#include "ILI9341_Driver.h"
#include "icons_included.h"
#include "ironman.h"

void Display_Round_Icon_40x40(const unsigned int icon[], unsigned int x0, unsigned int y0, unsigned int r)
{
	uint64_t k = 0;

    ILI9341_Draw_Circle(x0, y0, r, BLUE, 1);

	for(uint32_t j = y0 - 19; j < y0 + 21; j++)
	{
		for(uint32_t i = x0 -19; i < x0 + 21; i++)
		{
				ILI9341_Draw_Pixel(i, j, icon[k]);
				k++;
		}
	}
}

void Display_Square_Icon_40x40(const unsigned int icon[], unsigned int x0, unsigned int y0)
{
	uint64_t k = 0;

	for(uint32_t j = y0; j < y0 + 40; j++)
	{
		for(uint32_t i = x0; i < x0 + 40; i++)
		{
				ILI9341_Draw_Pixel(i, j, icon[k]);
				k++;
		}
	}
}

void Display_Menu()
{

	ILI9341_Set_Rotation(3);

	/* Refresh the screen to black background */
	ILI9341_Fill_Screen(BLACK);
	HAL_Delay(500);

	/* Counting through all the bytes of those icons */
	uint64_t k = 0;
	/* Draw border for the menu */
    ILI9341_Draw_Empty_Rectangle(YELLOW, 10, 30, 310, 230);

    /* Write something */
	ILI9341_Draw_String(10,10,WHITE,BLACK,"Welcome!",2);

	/* Battery Icon in the top right corner */
    for(uint32_t j = 10; j < 20; j++) {
    	for(uint32_t i = 280; i < 300; i++) {
				ILI9341_Draw_Pixel(i, j, battery_icon[k]);
				k++;
			}
	}

    /* =================================List of Icons================================= */

    /* ===========================Icon No.1=========================== */
    Display_Round_Icon_40x40(home_icon_40x40, 59, 79, 40);

    /* ===========================Icon No.2=========================== */
    Display_Round_Icon_40x40(music_icon_40x40, 159, 79, 40);

    /* ===========================Icon No.3=========================== */
    Display_Round_Icon_40x40(note_icon_40x40, 259, 79, 40);

    /* ===========================Icon No.4=========================== */
    Display_Round_Icon_40x40(game_icon_40x40, 59, 179, 40);

    /* ===========================Icon No.5=========================== */
    Display_Round_Icon_40x40(facebook_icon_40x40, 159, 179, 40);

    /* ===========================Icon No.6=========================== */
    Display_Round_Icon_40x40(image_icon_40x40, 259, 179, 40);

	CS_OFF;
}


void Display_Picture()
{
	/* Set the rotation that fit the image */
	ILI9341_Set_Rotation(0);

	/* Drawing Image to the LCD */
	uint64_t k = 0;
	for(uint32_t i = 0; i < 240; i++)
	{
		for(uint32_t j = 320; j > 0; j--)
		{
			ILI9341_Draw_Pixel(i, j, ironman[k]);
			k++;
		}
	}
}

void Display_Text()
{
	/* Refresh the screen to black background */
	ILI9341_Fill_Screen(BLACK);
	HAL_Delay(500);

	/* Draw border for the menu */
    ILI9341_Draw_Empty_Rectangle(YELLOW, 10, 30, 310, 230);

    /* Write something */
	ILI9341_Draw_String(20, 40, WHITE, BLACK, "Hello User!", 2);

	ILI9341_Draw_String(20, 60, WHITE, BLACK, "This is the test for TFT LCD!", 2);

	ILI9341_Draw_String(20, 80, WHITE, BLACK, "For more information, please visit:", 2);

	ILI9341_Draw_String(20, 100, WHITE, BLACK, "    aweirdolife.wordpress.com    ", 2);

	Display_Square_Icon_40x40(back_icon_40x40, 0, 200);
}

void Display_Color_Picture()
{
	for (uint16_t i = 0; i < 280; i++)
	{
		for (uint16_t j = 0; j < 320; j++)
		{
			ILI9341_Draw_Double_Pixel(j, i, ironman[(640 * i) + j * 2], ironman[(640 * i) + j * 2 + 1]);
		}
	}

	Display_Square_Icon_40x40(back_icon_40x40, 0, 200);
}
