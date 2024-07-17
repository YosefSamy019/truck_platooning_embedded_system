/*
 * BIT_MATH.h
 *
 * Created: 2024-01-26 3:51:22 PM
 *  Author: asus
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

//1 bit
#define SET_BIT(REG, BIT) ((REG)=(REG)|(1<<(BIT)))
#define TOG_BIT(REG, BIT) ((REG)=(REG)^(1<<(BIT)))
#define CLR_BIT(REG, BIT) ((REG)=(REG)&~(1<<(BIT)))
#define GET_BIT(REG, BIT) (((REG)>>(BIT))&1)
#define CLEAR_BIT(REG, BIT) ((REG)=(REG)&~(1<<(BIT)))


//nipples
#define GET_LOW_NIPPLE(REG)   ((REG)&0x0f)
#define GET_HIGH_NIPPLE(REG)  (((REG)&0xf0)>>4)
#define SET_LOW_NIPPLE(REG)   ((REG) = ((REG) | 0x0f))
#define SET_HIGH_NIPPLE(REG)  ((REG) = ((REG) | 0xf0))
#define CLR_LOW_NIPPLE(REG)   ((REG) = ((REG) & 0xf0))
#define CLR_HIGH_NIPPLE(REG)  ((REG) = ((REG) & 0x0f))


#endif /* BIT_MATH_H_ */