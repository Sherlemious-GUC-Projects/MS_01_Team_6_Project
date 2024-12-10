#pragma once

#include "pico/stdlib.h"

// GPIO pin definitions
#define SERVO_PWM_PIN 15 // D3

// Function Declarations
void servo_setup();
void servo_loop();
void set_servo_angle(uint16_t angle);
