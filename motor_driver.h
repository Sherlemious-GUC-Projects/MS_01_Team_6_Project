#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "pico/stdlib.h"

// GPIO pin definitions
#define MOTOR_PWM_PIN 8  // GPIO pin 8 for PWM (speed control)
#define MOTOR_DIR_PIN1 6 // GPIO pin 6 for direction control
#define MOTOR_DIR_PIN2 7 // GPIO pin 7 for direction control

// Function Declarations
void motor_init();
void motor_control(uint16_t speed, bool direction);

#endif