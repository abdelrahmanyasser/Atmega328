/*
 *  2x16 minimalistic driver
 *  by Abdelrahman Yasser
 */

/* TODO:
 * 1. More documentation and clear comments and descriptions
 * 2. Adding 4-bit mode!
 * 3. Add more than 2x16 model
 */

#include "lcd.h"
#include "gpio.h"
#include <util/delay.h>
#include <stdlib.h>

void LCD_init(void) {

	/* Initialization according to datasheet */
	/* Wait for more than 100 ms after start up */
	_delay_ms(100);
	LCD_sendCommand(0x30);
	/* Wait for more than 4.1 ms after SPECIAL FUNC SET */
	_delay_ms(5);
	LCD_sendCommand(0x30);
	/* Wait for more than 100 us after SPECIAL FUNC SET */
	_delay_ms(1);
	LCD_sendCommand(0x30);
	/* Wait for more than 100 us after SPECIAL FUNC SET */
	_delay_ms(1);

	/* 1.Func set (the real one) */
	LCD_sendCommand(LCD_8BIT_2LINE_5x8_MODE);
	/* Wait for more than 53 us or util Busy flag is clear */
	_delay_ms(1);

	/* 2.Display off */
	LCD_sendCommand(LCD_DISPLAY_ON);
	/* Wait for more than 53 us or util Busy flag is clear */
	_delay_ms(1);

	/* 3.Display clear */
	LCD_sendCommand(LCD_CLEAR_DISPLAY);
	/* Wait for more than 3 ms or util Busy flag is clear */
	_delay_ms(5);

//	/* 4.Entry mode */
//	LCD_sendCommand(0x05);
	/* Wait for more than 53 us or util Busy flag is clear */
//	_delay_us(60);
//	LCD_sendCommand(LCD_SET_DDRAM_ADRESS | 0x40);
}

void LCD_sendCommand(uint8 command) {

	gpio_writeChannel(LCD_RS_PORT, LCD_RS_PIN, LOGIC_LOW);
	gpio_writeChannel(LCD_RW_PORT, LCD_RW_PIN, LOGIC_LOW);
	/* Tas processing delay (50 ns) */
	_delay_ms(1);

	gpio_writeChannel(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	/* Tpw - Tdsw processing delay (190 ns) */
	_delay_ms(1);

	gpio_writePort(LCD_DATA, command);
	/* Tdsw processing delay (100 ns) */
	_delay_ms(1);

	gpio_writeChannel(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	/* Ts processing delay (13 ns) */
	_delay_ms(1);
}

void LCD_displayCharacter(uint8 data) {

	gpio_writeChannel(LCD_RS_PORT, LCD_RS_PIN, LOGIC_HIGH);
	gpio_writeChannel(LCD_RW_PORT, LCD_RW_PIN, LOGIC_LOW);
	/* Tas processing delay (50 ns) */
	_delay_ms(1);

	gpio_writeChannel(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	/* Tpw - Tdsw processing delay (190 ns) */
	_delay_ms(1);

	gpio_writePort(LCD_DATA, data);
	/* Tdsw processing delay (100 ns) */
	_delay_ms(1);

	gpio_writeChannel(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	/* Ts processing delay (13 ns) */
	_delay_ms(1);
}

void LCD_displayString(const char *str) {
	uint8 i = 0;
	while (*(str + i) != '\0') {
		LCD_displayCharacter(*(str + i));
		i++;
	}
}

void LCD_moveCursor(uint8 row, uint8 col) {
	uint8 address_counter = 0;

	/* Guard from invalid inputs */
	/* print error message and exit function */
	if (row > 3 || col > 39) {
		LCD_clearScreen();
		/* 16 character Error message */
		LCD_displayString("ERR MOV CURSOR !");
		return;
	}

	switch (row) {
	case 0:
		address_counter = col;
		break;
	case 1:
		address_counter = 0x40 + col;
		break;
	case 2:
		address_counter = 0x14 + col;
		break;
	case 3:
		address_counter = 0x54 + col;
		break;
	default:
		return;
	}

	LCD_sendCommand(LCD_SET_DDRAM_ADDRESS | address_counter);
}

void LCD_displayStringRowColumn(const char *str, uint8 row, uint8 col) {
	LCD_moveCursor(row, col);
	LCD_displayString(str);
}

void LCD_clearScreen(void) {
	LCD_sendCommand(LCD_CLEAR_DISPLAY);
}

void LCD_integerToString(uint8 integer) {
	/* array of char to hold the ASCII value */
	char buff[LCD_CHARACTERS];
	itoa(integer, buff, 10);
	LCD_displayString(buff);
}

