/*
 * LCD.h
 *
 * Created: 2023-08-28 11:21:04 AM
 *  Author: asus
 */ 


#ifndef LCD_H_
#define LCD_H_


#define DATA_DDR DDRA
#define DATA_PORT PORTA

#define E_DDR DDRB
#define E_PORT PORTB
#define E_PIN_NO 3

#define RS_DDR DDRB 
#define RS_PORT PORTB
#define RS_PIN_NO 1

#define RW_DDR DDRB
#define RW_PORT PORTB
#define RW_PIN_NO 2

//lcd size 16*2
#define LCD_WIDTH 16
#define LCD_HEIGHT 2

//data length must be 4 or 8
#define LCD_DATA_LENGTH 4

//the delay of enable pin when at exact level (high or low) is 2 ms
#define EN_IN_PULSE_DELAY 2
//the delay of enable pin after any clk is 20 ms
#define EN_OUT_OF_PULSE_DELAY 20
//the delay of lcd until reach 4.5 volts is 30 ms
#define LCD_INIT_DELAY 20

//DDRAM Addresses
#define LCD_ROW_ONE_ADDRESS 0x00
#define LCD_ROW_TWO_ADDRESS 0x40


void lcd_init();
void lcd_send_cmd(unsigned char cmd);
void lcd_send_data(unsigned char data);
void lcd_send_str( char* str);
void lcd_send_str_center(char* str,unsigned char row);
void lcd_send_number(int number);
void lcd_send_number_center(int number,unsigned char row);
void lcd_send_number_fixed(int number,unsigned char width);
void lcd_set_cursor(unsigned char row,unsigned char col);
void lcd_clear();
void lcd_shift_right();
void lcd_shift_left();


#endif /* LCD_H_ */