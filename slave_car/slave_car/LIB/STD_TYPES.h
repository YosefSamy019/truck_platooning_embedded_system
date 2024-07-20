/*
 * STD_TYPES.h
 *
 * Created: 2024-02-19 5:43:26 PM
 *  Author: asus
 */ 

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define NULL				((void*) 0)

typedef unsigned char		u8;
typedef unsigned char		uint8;
typedef signed char			sint8;

typedef unsigned short		uint16;
typedef signed short		sint16;

typedef unsigned long		uint32;
typedef signed long			sint32;

typedef unsigned long long	uint64;
typedef signed long long	sint64;

typedef float				float32;
typedef double				float64;

typedef unsigned char		string[25];



typedef void (*ptr2fun)(void);


#endif /* STD_TYPES_H_ */