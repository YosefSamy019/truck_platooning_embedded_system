/*
 * MOTOR_Interface.h
 *
 * Created: 7/10/2024 1:30:46 AM
 *  Author: menna
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>
#include <util/delay.h>

// Define motor control pins
#define IN1 PIN_B4
#define IN2 PIN_B5
#define IN3 PIN_B6
#define IN4 PIN_B7

// Define motion and rotation enums
enum motion { forward, backward, stop };
enum rotation { right, left, noRotate };




// Function
void MOTOR_init(void);
void MOTOR_setDutyCycle(char speed);  // Declaration only, implementation assumed to be in timer0 driver
void MOTOR_setMotion(enum motion m);
void MOTOR_setRotate(enum rotation r);
//void MOTOR_control(void);





#endif /* MOTOR_H_ */