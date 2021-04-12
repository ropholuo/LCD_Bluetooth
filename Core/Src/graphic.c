/*
 * graphic.c
 *
 *  Created on: Mar 4, 2019
 *      Author: Boning
 */

#include "main.h"
#include "lcd.h"

uint16_t COLOR = 0x5566;
uint8_t COLOR_LTDC = 0xF0;

void LCD_SetDrawAddr(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
	// Set Column Address
	LCD_WriteCommand(0x2A);
	LCD_WriteData( (x0 >> 8) & 0xFF);
	LCD_WriteData( x0 & 0xFF);
	LCD_WriteData((x1 >> 8) & 0xFF);
	LCD_WriteData(x1 & 0xFF);
	// Set Line Address
	LCD_WriteCommand(0x2B);
	LCD_WriteData((y0 >> 8) & 0xFF);
	LCD_WriteData(y0 & 0xFF);
	LCD_WriteData((y1 >> 8) & 0xFF);
	LCD_WriteData(y1 & 0xFF);
	// Memory Write
	LCD_WriteCommand(0x2c);
}

void LCD_SetColor(uint16_t c) {
	COLOR = c;
}

void LCD_SetColorLtdc(uint8_t c) {
	COLOR_LTDC = c;
}

void LCD_DrawRect_Spi(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
	LCD_SetDrawAddr(x0, y0, x1, y1);
	uint8_t buffer[] = {COLOR >> 8, COLOR};
	for(int y = y0; y <= y1; y++){
		for(int x = x0; x <= x1; x++) {
			LCD_WriteBulkData(buffer, 2);
		}
	}
}

void LCD_DrawRect_Ltdc(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
	for(int y = y0; y <= y1; y++){
		for(int x = x0; x <= x1; x++) {
			LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
		}
	}
}

void LCD_DrawH(uint16_t x0, uint16_t y0) {
	const uint8_t width = 8;
	for(int dy = 0; dy <= width; dy++){
			for(int dx = 0; dx <= width; dx++) {
				if ((dx < 2 || dx >= 7) || (dy == 3 || dy == 4)) {
					int y = y0 + dy;
					int x = x0 + dx;
					LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
				}
			}
		}
}


//Matthew's Addition
void LCD_DrawABig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 || dx >= 12) || (dy <= 3 || (dy >= 6 && dy <= 9))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawBBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy >= 6 && dy <= 9 && dx <= 11) || (dy <= 3 && dx <= 11) || (dy >= 12 && dx <= 11)|| (dx >= 12 && (dy >= 3 && dy <= 6)) || ((dx >= 12) && (dy >= 9 && dy <= 12))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawCBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3) || (dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawDBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3 && dx <= 11) || (dy >= 12 && dx <= 11) || (dx >= 12 && (dy >= 4 && dy <= 11))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawEBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx < 4) || (dy <= 3 || dy == 6 || dy == 7 || dy == 8 || dy == 9|| dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawFBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3) || (dy >= 6 && dy <= 9 && dx <= 11)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawGBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3) || (dy >= 12) || (dy >= 6 && dx >= 12) || (dy >= 6 && dy <= 9 && dx >= 5)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawHBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 || dx >= 12) || (dy == 6 || dy == 7 || dy == 8 || dy == 9)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawIBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dy <= 3) || (dy >= 12) || (dx >= 6 && dx <= 9)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawJBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dy <= 3) || (dx >= 6 && dx <= 9) || (dx <= 9 && dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawKBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dx >= 12 && dy >= 12) || (dx >= 8 && dx <= 11 && dy >= 8 && dy <= 11) || (dx >= 4 && dx <= 7 && dy >= 4 && dy <= 7) || (dx >= 11 && dy <= 3) || (dx >= 8 && dx <= 11 && dy >= 4 && dy <= 7)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawLBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawMBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dx >= 12) || ((dx >= 6 && dx <= 9) && (dy >= 6 && dy <= 9)) || ((dx >= 3 && dx <= 6) && (dy >= 3 && dy <= 6)) || ((dx >= 9 && dx <= 12) && (dy >= 3 && dy <= 6))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawNBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dx >= 12) || ((dx >= 6 && dx <= 9) && (dy >= 6 && dy <= 9)) || ((dx >= 3 && dx <= 6) && (dy >= 3 && dy <= 6)) || ((dx >= 9 && dx <= 12) && (dy >= 9 && dy <= 12))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawOBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 || dx >= 12) || (dy <= 3 || dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawPBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3 && dx <= 11) || ((dy >= 6 && dy <= 9) && dx <= 11) || (dx >= 12 && (dy >= 3 && dy <= 6))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawQBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3)||(dx >= 12) || (dy <= 3) || (dy >= 12) || (dx >= 8 && dx <= 11 && dy >= 8 && dy <= 11)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawRBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3 && dx <= 11) || ((dy >= 6 && dy <= 9) && dx <= 11) || (dx >= 12 && (dy >= 3 && dy <= 6))|| (dx >= 12 && dy >= 12) || (dx >= 8 && dx <= 11 && dy >= 8 && dy <= 11)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawSBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 9) || (dx >= 12 && dy >= 6) || (dy <= 3 || dy == 6 || dy == 7 || dy == 8 || dy ==9 || dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawTBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dy <= 3) || (dx >= 6 && dx <= 9)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawUBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dx >= 12) || (dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawVBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 3) || (dx >= 12 && dy <= 3) || (dx >= 6 && dx <= 9 && dy >= 12) || (dy >= 4 && dy <= 7 && dx >= 2 && dx <= 5) || (dy >= 8 && dy <= 11 && dx >= 4 && dx <= 7) || (dy >= 4 && dy <= 7 && dx >= 10 && dx <= 13) || (dy >= 8 && dy <= 11 && dx >= 8 && dx <= 11) ) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawWBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 3) || (dx >= 12 && dy <= 3) || (dy >= 4 && dy <= 7 && dx >= 1 && dx <= 4) || (dy >= 8 && dy <= 11 && dx >= 2 && dx <= 5)  || (dy >= 12 && dy <= 15 && dx >= 3 && dx <= 6)|| (dy >= 4 && dy <= 7 && dx >= 11 && dx <= 14) || (dy >= 8 && dy <= 11 && dx >= 10 && dx <= 13) || (dy >= 12 && dy <= 15 && dx >= 9 && dx <= 12) || (dx >= 6 && dx <= 9 && dy >= 6 && dy <= 11)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawXBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 3) || (dx >= 12 && dy <= 3) || (dx <= 3 && dy >= 12) || (dx >= 12 && dy >= 12) || (dy >= 4 && dy <= 11 && dx >= 4 && dx <= 11)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawYBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx >= 6 && dx <= 9 && dy >= 8) || (dx <= 3 && dy <= 3) || (dx >= 12 && dy <= 3) || (dx >= 4 && dx <= 7 && dy >= 4 && dy <= 7) || (dx >= 8 && dx <= 11 && dy >= 4 && dy <= 7)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_DrawZBig(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dy >= 12 || (dy >= 4 && dy <= 7 && dx >= 8 && dx <= 11) || (dy >= 8 && dy <= 11 && dx >= 4 && dx <= 7)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Draw0Big(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 || dx >= 12) || (dy <= 3 || dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Draw1Big(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dx >= 6 && dx <= 9) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Draw2Big(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dy >= 12|| (dx >= 12 && dy <= 5) || (dx <= 3 && dy >= 10) || (dy >= 6 && dy <= 9)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Draw3Big(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dy >= 12 || (dy >= 6 && dy <= 9) || (dx >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Draw4Big(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 9) || (dy >= 6 && dy <= 9) || (dx >= 10 && dx <= 13)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Draw5Big(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dy >= 12|| (dy >= 6 && dy <= 9) || (dx >= 12 && dy >= 6) || (dx <= 3 && dy <= 9)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Draw6Big(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dx <= 3 || dy >= 12 || (dy >= 6 && dy <= 9) || (dx >= 12 && dy >= 6)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Draw7Big(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dy <= 3) || (dx <= 3 && dy >= 12) || (dy >= 4 && dy <= 7 && dx >= 8 && dx <= 11) || (dy >= 8 && dy <= 11 && dx >= 4 && dx <= 7)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Draw8Big(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dy >= 12 || (dy >= 6 && dy <= 9) || (dx >= 12) || (dx <= 3)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Draw9Big(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 9) || (dy >= 6 && dy <= 9) || (dx >= 12) || (dy <= 3) || (dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}
