#pragma once

// GPIO pin definitions
#define MOTOR_PWM_PIN 16  // pin D4
#define MOTOR_DIR_PIN1 18 // D6
#define MOTOR_DIR_PIN2 19 // D7

// Function Declarations
void motor_setup();
void motor_control(uint16_t speed, bool forward);
void motor_loop(void *ptr);
void run_for_seconds(void *ptr);
