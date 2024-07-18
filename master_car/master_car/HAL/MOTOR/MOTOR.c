
/*
 * MOTOR_Program.c
 *
 * Created: 7/10/2024 1:30:14 AM
 *  Author: menna
 */ 

#include "MOTOR.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "TIMER_0/Timer0_PWM.h"


// Global variables to store current motion and rotation
enum motion currentMotion = stop;
enum rotation currentRotation = noRotate;

static void MOTOR_control(void) ;

void MOTOR_init(void) {
	// Set motor control pins as outputs
	DIO_pinMode(IN1, OUTPUT);
	DIO_pinMode(IN2, OUTPUT);
	DIO_pinMode(IN3, OUTPUT);
	DIO_pinMode(IN4, OUTPUT);

	// Initialize motors to be stopped
	DIO_digitalWrite(IN1, LOW);
	DIO_digitalWrite(IN2, LOW);
	DIO_digitalWrite(IN3, LOW);
	DIO_digitalWrite(IN4, LOW);
}

void MOTOR_setDutyCycle(char speed) {
	// This function is assumed to call TIMER0_setDutyCycle from timer0 driver
	TIMER0_setDutyCycle(speed);
	
}

void MOTOR_setMotion(enum motion m) {
	currentMotion = m;
	MOTOR_control();
}

void MOTOR_setRotate(enum rotation r) {
	currentRotation = r;
	MOTOR_control();
}

static void MOTOR_control(void) {
	// Handle combined motion and rotation
	switch (currentMotion) {
		case forward:
		switch (currentRotation) {
			case left:
			DIO_digitalWrite(IN1, LOW);
			DIO_digitalWrite(IN2, LOW);
			DIO_digitalWrite(IN3, LOW);
			DIO_digitalWrite(IN4, HIGH);
			break;
			case right:
			DIO_digitalWrite(IN1, LOW);
			DIO_digitalWrite(IN2, HIGH);
			DIO_digitalWrite(IN3, LOW);
			DIO_digitalWrite(IN4, LOW);
			break;
			case noRotate:
			DIO_digitalWrite(IN1, LOW);
			DIO_digitalWrite(IN2, HIGH);
			DIO_digitalWrite(IN3, LOW);
			DIO_digitalWrite(IN4, HIGH);
			break;
		}
		break;
		case backward:
		switch (currentRotation) {
			case right:
			DIO_digitalWrite(IN1, LOW);
			DIO_digitalWrite(IN2, LOW);
			DIO_digitalWrite(IN3, HIGH);
			DIO_digitalWrite(IN4, LOW);
			break;
			case left:
			DIO_digitalWrite(IN1, HIGH);
			DIO_digitalWrite(IN2, LOW);
			DIO_digitalWrite(IN3, LOW);
			DIO_digitalWrite(IN4, LOW);
			break;
			case noRotate:
			DIO_digitalWrite(IN1, HIGH);
			DIO_digitalWrite(IN2, LOW);
			DIO_digitalWrite(IN3, HIGH);
			DIO_digitalWrite(IN4, LOW);
			break;
		}
		break;
		case stop:
		DIO_digitalWrite(IN1, LOW);
		DIO_digitalWrite(IN2, LOW);
		DIO_digitalWrite(IN3, LOW);
		DIO_digitalWrite(IN4, LOW);
		break;
	}
}
