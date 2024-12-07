#pragma once

#include "pico/stdlib.h"

// GPIO pin definitions
#define MOTOR_PWM_PIN 16  // GPIO pin 8 for PWM (speed control)
#define MOTOR_DIR_PIN1 18 // GPIO pin 6 for direction control
#define MOTOR_DIR_PIN2 19 // GPIO pin 7 for direction control

// Function Declarations
void motor_setup();
void motor_control(uint16_t speed, bool forward);
void motor_loop();
