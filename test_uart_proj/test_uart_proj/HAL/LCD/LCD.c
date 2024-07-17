#define  F_CPU 16000000ul
#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../REG.h"
#include "LCD.h"


void lcd_init(){
	SET_BIT(RW_DDR,RW_PIN_NO);
	SET_BIT(RS_DDR,RS_PIN_NO);
	SET_BIT(E_DDR,E_PIN_NO);
	
	#if LCD_DATA_LENGTH == 4
		DATA_DDR |= 0xF0;
		//delay until LCD reach 4.5 volts
		_delay_ms(LCD_INIT_DELAY);
		lcd_send_cmd(0x02); //return home
		lcd_send_cmd(0x28); //function set of 4 bit mode
		
	#elif LCD_DATA_LENGTH == 8
		DATA_DDR = 0xFF;
		//delay until LCD reach 4.5 volts
		_delay_ms(LCD_INIT_DELAY);
		lcd_send_cmd(0x02); //return home
		lcd_send_cmd(0x38); //function set of 8 bit mode
	#else
		#error invalid data length passed to lcd
	#endif
	
	lcd_send_cmd(0x0f); //display control (display on, cursor on, blink on)
	lcd_send_cmd(0x06); //entry set mode (cursor shift right, display shift left)
	lcd_send_cmd(0x01); //clear display
	
	//delay of LCD responding
	_delay_ms(LCD_INIT_DELAY);
}

void lcd_send_cmd(unsigned char cmd){
	CLEAR_BIT(RW_PORT,RW_PIN_NO);
	CLEAR_BIT(RS_PORT,RS_PIN_NO);
	
	#if LCD_DATA_LENGTH == 4
		DATA_PORT = (DATA_PORT & 0x0f) | (cmd & 0xf0);
		
		SET_BIT(E_PORT , E_PIN_NO);
		_delay_ms(EN_IN_PULSE_DELAY);
		CLEAR_BIT(E_PORT , E_PIN_NO);
		
		_delay_ms(EN_IN_PULSE_DELAY);
		
		DATA_PORT = (DATA_PORT & 0x0f) | (cmd << 4);
		
		SET_BIT(E_PORT , E_PIN_NO);
		_delay_ms(EN_IN_PULSE_DELAY);
		CLEAR_BIT(E_PORT , E_PIN_NO);
		
		_delay_ms(EN_OUT_OF_PULSE_DELAY);

	#elif LCD_DATA_LENGTH == 8
		DATA_PORT = cmd;
	
		SET_BIT(E_PORT , E_PIN_NO);
		_delay_ms(EN_IN_PULSE_DELAY);
		CLEAR_BIT(E_PORT , E_PIN_NO);
		_delay_ms(EN_OUT_OF_PULSE_DELAY);
		
	#else
	#error invalid data length passed to lcd
	#endif
}

void lcd_send_data(unsigned char data){
	CLEAR_BIT(RW_PORT,RW_PIN_NO);
	SET_BIT(RS_PORT,RS_PIN_NO);
	
	#if LCD_DATA_LENGTH == 4
	DATA_PORT = (DATA_PORT & 0x0f) | (data & 0xf0);
	
	SET_BIT(E_PORT , E_PIN_NO);
	_delay_ms(EN_IN_PULSE_DELAY);
	CLEAR_BIT(E_PORT , E_PIN_NO);
	
	_delay_ms(EN_IN_PULSE_DELAY);
	
	DATA_PORT = (DATA_PORT & 0x0f) | (data << 4);
	
	SET_BIT(E_PORT , E_PIN_NO);
	_delay_ms(EN_IN_PULSE_DELAY);
	CLEAR_BIT(E_PORT , E_PIN_NO);
	
	_delay_ms(EN_OUT_OF_PULSE_DELAY);

	#elif LCD_DATA_LENGTH == 8
	DATA_PORT = data;
	
	SET_BIT(E_PORT , E_PIN_NO);
	_delay_ms(EN_IN_PULSE_DELAY);
	CLEAR_BIT(E_PORT , E_PIN_NO);
	_delay_ms(EN_OUT_OF_PULSE_DELAY);
	
	#else
	#error invalid data length passed to lcd
	#endif
}

void lcd_send_str( char* str){
	while(*str != '\0'){
		lcd_send_data(*str);
		str++;
	}
}

void lcd_send_number(int number){
	char arr[32]={0};
	signed char i = 0;
	
	if(number<0){
		lcd_send_data('-');
		number = number * (-1);
	}
	
	//fill array with digits
	while(i < 32 && number!=0){
		arr[i] = (number%10);
		number/=10;
		i++;
	}

	//add this line to prevent printing an extra zero at left side of the original number
	if(i>0) i = i-1; 
	
	for(;i>=0;i--){
		lcd_send_data(arr[i]+48);
	}
}

void lcd_send_str_center(char* str,unsigned char row){
	unsigned char str_size=0;
	char* ptr;
	unsigned char padding=0;
	
	//get string size
	for(ptr = str; *ptr!=0 ;ptr++){
		str_size++;
	}
	
	padding = (LCD_WIDTH - str_size) / 2;
	
	lcd_set_cursor(row, padding);
	lcd_send_str(str);
}


void lcd_send_number_center(int number,unsigned char row){
	unsigned char int_size=0;
	int temp;
	unsigned char padding=0;
	
	//get int size
	temp = number;
	while(temp !=0){
		int_size++;
		temp/=10;
	}
	
	padding = (LCD_WIDTH - int_size) / 2;
	
	lcd_set_cursor(row, padding);
	lcd_send_number(number);
}

void lcd_send_number_fixed(int number,unsigned char width){
	char arr[32]={0};
	signed char i = 0,j;
	
	if(number<0){
		lcd_send_data('-');
		number = number * (-1);
	}
	
	//fill array with digits
	while(i < 32 && number!=0 && i<width){
		arr[i] = (number%10);
		number/=10;
		i++;
	}

	//add this line to prevent printing an extra zero at left side of the original number
	if(i>0) i = i-1;
	
	for(j= (width-i -1) ;j>0; j--){
		lcd_send_data('0');
	}
	
	for(;i>=0;i--){
		lcd_send_data(arr[i]+48);
	}
}
inline void lcd_set_cursor(unsigned char row,unsigned char col){
	//set the 7nth bit to be high due to data sheet instructions
	char temp = 0b10000000; 
	
	switch(row){
		case 0: temp |= (LCD_ROW_ONE_ADDRESS + col); break;
		case 1: temp |= (LCD_ROW_TWO_ADDRESS + col); break;
		default:  break; 
	}
	lcd_send_cmd(temp);
}
inline void lcd_clear(){
	lcd_send_cmd(0x01); //clear display
}
inline void lcd_shift_right(){
	lcd_send_cmd(0b00011100); 
}
inline void lcd_shift_left(){
	lcd_send_cmd(0b00011000); 
}