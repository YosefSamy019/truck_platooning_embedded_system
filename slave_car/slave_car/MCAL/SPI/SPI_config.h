/*
 * SPI_config.h
 *
 * Created: 2024-02-08 1:39:09 PM
 *  Author: asus
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

//SPI MODE
#define SPI_SLAVE_MODE 0
#define SPI_MASTER_MODE 1
#define SPI_MODE SPI_SLAVE_MODE

///For more info about Clock Phase and Clock Polarity, see TABLE 59, PAGE 139

// Clock Phase
#define SPI_CLOCK_PHASE_SAMPLE_AT_LEADING_SETUP_AT_TRAILLING 0
#define SPI_CLOCK_PHASE_SETUP_AT_LEADING_SAMPLE_AT_TRAILLING 1
#define SPI_CLOCK_PHASE_SELECT SPI_CLOCK_PHASE_SAMPLE_AT_LEADING_SETUP_AT_TRAILLING

// Clock Polarity
#define SPI_CLOCK_POLARITY_IDLE_WHEN_LOW  0
#define SPI_CLOCK_POLARITY_IDLE_WHEN_HIGH 1
#define SPI_CLOCK_POLARITY_SELECT SPI_CLOCK_POLARITY_IDLE_WHEN_LOW

//Relationship Between SCK and the Oscillator Frequency
#define SPI_PRESCALER_4  0
#define SPI_PRESCALER_16 1
#define SPI_PRESCALER_64 2
#define SPI_PRESCALER_128 3
#define SPI_PRESCALER_2 4
#define SPI_PRESCALER_8 5
#define SPI_PRESCALER_32 6
#define SPI_PRESCALER_64 7
#define SPI_PRESCALER_SELECT SPI_PRESCALER_4

//DATA ORDER
#define SPI_DATA_ORDER_MSB_IS_FIRST 0
#define SPI_DATA_ORDER_LSB_IS_FIRST 1
#define SPI_DATA_ORDER_SELECT SPI_DATA_ORDER_MSB_IS_FIRST

//Enable interrupt code if the mode is SLAVE (0, 1)
#define SPI_ENABLE_INTERRUPT 1

#endif /* SPI_CONFIG_H_ */