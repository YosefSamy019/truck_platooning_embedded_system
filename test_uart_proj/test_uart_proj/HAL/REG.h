///--------------------------------------------///
///AMIT KIT REGISTERS By Yossef Samy

#ifndef REG_H_
#define REG_H_

//add volatile to ignore optimization
//the compiler ignore this pointer as optimization
//optimization will ignore casting

#define DDRA *((volatile unsigned char *) 0x3A)
#define DDRB *((volatile unsigned char *) 0x37)
#define DDRC *((volatile unsigned char *) 0x34)
#define DDRD *((volatile unsigned char *) 0x31)

#define PINA *((volatile unsigned char *) 0x39)
#define PINB *((volatile unsigned char *) 0x36)
#define PINC *((volatile unsigned char *) 0x33)
#define PIND *((volatile unsigned char *) 0x30)

#define PORTA *((volatile unsigned char *) 0x3B)
#define PORTB *((volatile unsigned char *) 0x38)
#define PORTC *((volatile unsigned char *) 0x35)
#define PORTD *((volatile unsigned char *) 0x32)

//REG parameter can be DDR, PIN or PORT without specifying A, B, C or D

//PD
#define Y_RX_REG(REG) REG##D
#define Y_RX_NO 0

#define Y_TX_REG(REG) REG##D
#define Y_TX_NO 1

#define Y_BUTTON_2_REG(REG) REG##D
#define Y_BUTTON_2_NO 2

#define Y_LED_2_REG(REG) REG##D
#define Y_LED_2_NO 3

#define Y_H_EN_1_REG(REG) REG##D
#define Y_H_EN_1_NO 4

#define Y_H_EN_2_REG(REG) REG##D
#define Y_H_EN_2_NO 5

#define Y_BUTTON_1_REG(REG) REG##D
#define Y_BUTTON_1_NO 6

#define Y_SERVO_REG(REG) REG##D
#define Y_SERVO_NO 7

//PC
#define Y_SCL_REG(REG) REG##C
#define Y_SCL_NO 0

#define Y_SDA_REG(REG) REG##C
#define Y_SDA_NO 1

#define Y_LED_0_REG(REG) REG##C
#define Y_LED_0_NO 2

#define Y_H_A1_REG(REG) REG##C
#define Y_H_A1_NO 3

#define Y_H_A2_REG(REG) REG##C
#define Y_H_A2_NO 4

#define Y_H_A3_REG(REG) REG##C
#define Y_H_A3_NO 5

#define Y_H_A4_REG(REG) REG##C
#define Y_H_A4_NO 6

#define Y_LED_1_REG(REG) REG##C
#define Y_LED_1_NO 7

//PB
#define Y_BUTTON_0_REG(REG) REG##B
#define Y_BUTTON_0_NO 0

#define Y_LCD_RS_REG(REG) REG##B
#define Y_LCD_RS_NO 1

#define Y_LCD_RW_REG(REG) REG##B
#define Y_LCD_RW_NO 2

#define Y_LCD_E_REG(REG) REG##B
#define Y_LCD_E_NO 3

#define Y_SS_REG(REG) REG##B
#define Y_SS_NO 4

#define Y_MOSI_REG(REG) REG##B
#define Y_MOSI_NO 5

#define Y_MISO_REG(REG) REG##B
#define Y_MISO_NO 6

#define Y_SCK_REG(REG) REG##B
#define Y_SCK_NO 7

//PA
#define Y_N_C_REG(REG) REG##A
#define Y_N_C_NO 0

#define Y_POT_REG(REG) REG##A
#define Y_POT_NO 1

#define Y_RELAY_REG(REG) REG##A
#define Y_RELAY_NO 2

#define Y_BUZZER_REG(REG) REG##A
#define Y_BUZZER_NO 3

#define Y_LCD_D4_REG(REG) REG##A
#define Y_LCD_D4_NO 4

#define Y_LCD_D5_REG(REG) REG##A
#define Y_LCD_D5_NO 5

#define Y_LCD_D6_REG(REG) REG##A
#define Y_LCD_D6_NO 6

#define Y_LCD_D7_REG(REG) REG##A
#define Y_LCD_D7_NO 7

//7 Segment
#define Y_SEV_SEG_EN_2_REG(REG) REG##B
#define Y_SEV_SEG_EN_2_NO 1

#define Y_SEV_SEG_EN_1_REG(REG) REG##B
#define Y_SEV_SEG_EN_1_NO 2

#define Y_SEV_SEG_DIP_REG(REG) REG##B
#define Y_SEV_SEG_DIP_NO 3

#define Y_SEV_SEG_A_REG(REG) REG##A
#define Y_SEV_SEG_A_NO 4

#define Y_SEV_SEG_B_REG(REG) REG##A
#define Y_SEV_SEG_B_NO 5

#define Y_SEV_SEG_C_REG(REG) REG##A
#define Y_SEV_SEG_C_NO 6

#define Y_SEV_SEG_D_REG(REG) REG##A
#define Y_SEV_SEG_D_NO 7

#endif