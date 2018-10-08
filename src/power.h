/* Power Output Handling Module
 *
 * Used to initialize, control, and manage the motor's power output
 *
 * This includes PWM and direction output of the motor.
 *
 * The motor is automatically disabled for a short while before and after switching directions.
 * This may block code from running temporarily.
 *
 * The Timer1 unit is used to control the power output in phase-correct PWM mode,
 * running at about 122 Hz.
 *
 * Written by Ana Tavares <tavaresa13@gmail.com>
 */

#ifndef power_h
#define power_h
#include <arduino.h>
#include "safety.h"

/////////////////////////
// CONFIGURATION VARIABLES
/////////////////////////

// PWM presets
const uint8_t PWM_SPEED_SLOW = 100;
const uint8_t PWM_SPEED_FAST = 255;

// Motor state delays
const unsigned int MOTOR_FLYBACK_DELAY = 100;
const unsigned int MOTOR_RELAY_CHANGE_DELAY = 250;


/////////////////////////
// PIN DEFINITIONS
/////////////////////////

const byte MOTOR_DIR_PIN = 8;
const byte MOTOR_PWM_PIN = 9;
const byte MAGNET_PWM_PIN = 10;  // Unused


/////////////////////////
// ENUMERATIONS
/////////////////////////

typedef enum {
	SLOW,
	FAST
} motor_speed_t;

typedef enum {
	FORWARD,
	BACKWARD,
	HALT
} motor_movement_t;


/////////////////////////
// AVAILABLE FUNCTIONS
/////////////////////////

void initPowerOutputs();
/*
 * Initializes the power output
 * Must be called at startup
 *
 * Initialization involves setting status variables, pin configuration, and PWM values.
 * Initial motor direction is also set.
 */

void setMotorOutput(motor_movement_t movement);
/*
 * Sets the motor output type
 *
 * Affects Motor_Enabled
 * INPUT:  Type of movement
 */

void setMotorSpeed(motor_speed_t speed);
/*
 * Sets the speed of the motor
 *
 * Affects Motor_Speed
 * INPUT:  Motor speed
 */

bool motorEnabled();
/*
 * Gets the state of the motor
 *
 * OUTPUT: State of being enabled
 */


#endif
