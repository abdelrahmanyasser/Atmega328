/*
 * @author: Abdelrahman Yasser
 *  @breif: configuration header for LCD module for atmega328p
 */

#ifndef CONFIG_LCD_CFG_H_
#define CONFIG_LCD_CFG_H_

/* Configure LCD_INIT */

/* LCD model */
#define LCD_LINES 2
#define LCD_CHARACTERS 16

/* Ports & Pins connections */
#define LCD_RS_PORT 	PORT_B
#define LCD_RW_PORT 	PORT_B
#define LCD_E_PORT 		PORT_B

#define LCD_RS_PIN 		PIN_2
#define LCD_RW_PIN 		PIN_1
#define LCD_E_PIN 		PIN_0

#define LCD_DATA 		PORT_D

#endif /* CONFIG_LCD_CFG_H_ */
