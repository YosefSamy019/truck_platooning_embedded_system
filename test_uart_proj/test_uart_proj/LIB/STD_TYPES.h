/*
 * STD_TYPES.h
 *
 * Created: 2024-01-26 3:56:10 PM
 *  Author: asus
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define NULL ((void*)0)

typedef  unsigned char u8;
typedef signed char s8;

typedef  unsigned short u16;
typedef signed short s16;

typedef  unsigned long u32;
typedef signed long s32;

typedef  unsigned long long u64;
typedef signed long long s64;

typedef float float32;
typedef double float64;

#define TRUE  0x01
#define FALSE 0x00

typedef unsigned char boolean;

//pointer to function whose both of input and output are void 
typedef void(*func_ptr)(void);
typedef void(*func_u32_ptr)(u32);
typedef void(*func_u8_ptr)(u32);

#endif /* STD_TYPES_H_ */