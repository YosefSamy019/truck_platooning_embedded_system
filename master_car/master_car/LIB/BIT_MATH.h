/*
 * BIT_MATH.h
 *
 * Created: 2024-02-12 5:33:03 PM
 *  Author: asus
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, BIT) ((REG)=(REG)|(1<<(BIT)))
#define TOG_BIT(REG, BIT) ((REG)=(REG)^(1<<(BIT)))
#define CLR_BIT(REG, BIT) ((REG)=(REG)&~(1<<(BIT)))
#define GET_BIT(REG, BIT) (((REG)>>(BIT))&1)

#endif /* BIT_MATH_H_ */