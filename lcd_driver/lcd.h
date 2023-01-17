/*
 *  2x16 minimalistic driver
 *  by Abdelrahman Yasser
 */


#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
#include "lcd_Cfg.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


/* LCD Commands */
#define LCD_CLEAR_DISPLAY	 		0x01
#define LCD_RETURN_HOME				0x02
#define LCD_ENTRY_MODE_SET			0x04
#define LCD_DISPLAY_ON				0x0C
#define LCD_DISPLAY_OFF				0x08
#define LCD_CURSOR_SHIFT 			0x10
#define LCD_DISPLAY_SHIFT			0x10
#define LCD_8BIT_2LINE_5x8_MODE 	0x38
#define LCD_8BIT_2LINE_5x11_MODE 	0x3C
#define LCD_4BIT_2LINE_5x8_MODE 	0x28
#define LCD_4BIT_2LINE_5x11_MODE 	0x2C
#define LCD_SET_CGRAM_ADDRESS		0x40
#define LCD_SET_DDRAM_ADDRESS 		0x80

/*******************************************************************************
 *                          Function prototypes                                *
 *******************************************************************************/

void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *str);
void LCD_moveCursor(uint8 row, uint8 col);
void LCD_displayStringRowColumn(const char *str, uint8 row, uint8 col);
void LCD_clearScreen(void);
void LCD_integerToString(uint8 integer);

#endif /* LCD_H_ */
