/*
 * screens.c
 *
 *  Created on: Mar 4, 2021
 *      Author: Matthew T Suzuki
 */

#include "main.h"
#include "graphic.h"
#include "lcd.h"
#include <string.h>

void letterselect(const char letter, int x, int y){
	if( letter == 'A' ) {
		LCD_DrawABig(x, y);
	}
	else if( letter == 'B' ) {
		LCD_DrawBBig(x, y);
	}
	else if( letter == 'C' ) {
		LCD_DrawCBig(x, y);
	}
	else if( letter == 'D' ) {
		LCD_DrawDBig(x, y);
	}
	else if( letter == 'E' ) {
		LCD_DrawEBig(x, y);
	}
	else if( letter == 'F' ) {
		LCD_DrawFBig(x, y);
	}
	else if( letter == 'G' ) {
		LCD_DrawGBig(x, y);
	}
	else if( letter == 'H' ) {
		LCD_DrawHBig(x, y);
	}
	else if( letter == 'I' ) {
		LCD_DrawIBig(x, y);
	}
	else if( letter == 'J' ) {
		LCD_DrawJBig(x, y);
	}
	else if( letter == 'K' ) {
		LCD_DrawKBig(x, y);
	}
	else if( letter == 'L' ) {
		LCD_DrawLBig(x, y);
	}
	else if( letter == 'M' ) {
		LCD_DrawMBig(x, y);
	}
	else if( letter == 'N' ) {
		LCD_DrawNBig(x, y);
	}
	else if( letter == 'O' ) {
		LCD_DrawOBig(x, y);
	}
	else if( letter == 'P' ) {
		LCD_DrawPBig(x, y);
	}
	else if( letter == 'Q' ) {
		LCD_DrawQBig(x, y);
	}
	else if( letter == 'R' ) {
		LCD_DrawRBig(x, y);
	}
	else if( letter == 'S' ) {
		LCD_DrawSBig(x, y);
	}
	else if( letter == 'T' ) {
		LCD_DrawTBig(x, y);
	}
	else if( letter == 'U' ) {
		LCD_DrawUBig(x, y);
	}
	else if( letter == 'V' ) {
		LCD_DrawVBig(x, y);
	}
	else if( letter == 'W' ) {
		LCD_DrawWBig(x, y);
	}
	else if( letter == 'X' ) {
		LCD_DrawXBig(x, y);
	}
	else if( letter == 'Y' ) {
		LCD_DrawYBig(x, y);
	}
	else if( letter == 'Z') {
		LCD_DrawZBig(x, y);
	}
	else if( letter == '0' ) {
		LCD_Draw0Big(x, y);
	}
	else if( letter == '1' ) {
		LCD_Draw1Big(x, y);
	}
	else if( letter == '2' ) {
		LCD_Draw2Big(x, y);
	}
	else if( letter == '3' ) {
		LCD_Draw3Big(x, y);
	}
	else if( letter == '4' ) {
		LCD_Draw4Big(x, y);
	}
	else if( letter == '5') {
		LCD_Draw5Big(x, y);
	}
	else if( letter == '6' ) {
		LCD_Draw6Big(x, y);
	}
	else if( letter == '7' ) {
		LCD_Draw7Big(x, y);
	}
	else if( letter == '8' ) {
		LCD_Draw8Big(x, y);
	}
	else {
		LCD_Draw9Big(x, y);
	}
}

void type(char const * word, int x, int y){
	for (int i = 0; i < strlen(word); i++){
		letterselect(word[i], x, y);
		x = (x + 18) % LCD_WIDTH;
	}
}



void InitialScreen(void)
{
	LCD_ClearScreenLtdc(0xFF);
	type("WELCOME", 50, 152);
	type("PAMA" , 85, 294);
	HAL_Delay(3000);
	LCD_ClearScreenLtdc(0xFF);
}

void MenuScreen(void)
{
	LCD_ClearScreenLtdc(0x04);
	type("MENU", 70, 152);
	type("PAMA" , 85, 294);
}

void BluetoothScreen(void)
{
	LCD_ClearScreenLtdc(0x12);
	type("BLUETOOTH", 40, 152);
	type("PAIRING", 40, 170);
	type("PAMA" , 85, 294);
}

void ScheduleScreen()
{
	LCD_ClearScreenLtdc(0x05);
	type("SCHEDULE", 50, 152);
	type("PAMA", 85, 294);
}

void DispensedScreen()
{
	LCD_ClearScreenLtdc(0x09);
	type("DISPENSED", 50, 152);
	type("PAMA" , 85, 294);
}
