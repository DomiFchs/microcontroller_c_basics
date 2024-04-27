#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

//reminder: placeholders
// %d - integer
// %f - float
// %c - char
// %u - unsigned int
// %0.2f - float with 2 decimal places

void init_lcd();

volatile char lcd_buffer[16];

int main() {
    init_lcd();

    sprintf(lcd_buffer, "Hello World! %d", 123); //sprintf is like printf but writes to a buffer
    lcd_puts(lcd_buffer);

    while(1);
}

void init_lcd(){
    lcd_init(LCD_DISP_ON);
    lcd_clrscr();
}


