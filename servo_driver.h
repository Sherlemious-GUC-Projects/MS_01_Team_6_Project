#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include "pico/stdlib.h"

// GPIO pin definitions
#define SERVO_PWM_PIN 15 // GPIO pin for servo PWM signal

// Function Declarations
void servo_init();
void servo_control(uint16_t angle);

#endif
