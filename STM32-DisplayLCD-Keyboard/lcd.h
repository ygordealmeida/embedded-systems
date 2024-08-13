#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "main.h"

void lcd_command(uint8_t cmd);
void lcd_data(uint8_t data);
void lcd_texto (char* frase);
void lcd_goto_XY(uint8_t row, uint8_t col);


#endif 