#ifndef MOTOR_H
#define MOTOR_H

// Constants for Motor 1
#define MOTOR_1_PWM_PIN 16
#define MOTOR_1_DIR_PIN1 18
#define MOTOR_1_DIR_PIN2 19

// Constants for Motor 2
#define MOTOR_2_PWM_PIN 13
#define MOTOR_2_DIR_PIN1 12
#define MOTOR_2_DIR_PIN2 11

#include "FreeRTOS.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "task.h"

/**
 * Initialize the motor by setting GPIO pins and PWM configurations.
 * args:
 *     MOTOR_DIR_PIN1: uint - GPIO pin for direction 1
 *     MOTOR_DIR_PIN2: uint - GPIO pin for direction 2
 *     MOTOR_PWM_PIN: uint - GPIO pin for PWM output
 * returns:
 *     void
 */
void motor_initialize(uint MOTOR_DIR_PIN1, uint MOTOR_DIR_PIN2,
                      uint MOTOR_PWM_PIN);

/**
 * Set up both motors with predefined constants.
 * args:
 *     None
 * returns:
 *     void
 */
void motor_setup();

/**
 * Control a single motor's direction and speed.
 * args:
 *     speed: uint16_t - Motor speed (0 to 255)
 *     forward: bool - Motor direction (true for forward, false for reverse)
 *     motor_id: uint - Motor identifier (1 or 2)
 * returns:
 *     void
 */
void motor_control(uint16_t speed, bool forward, uint motor_id);

/**
 * Infinite loop controlling a motor for a given duration.
 * args:
 *     ptr: void* - Pointer to duration in seconds
 * returns:
 *     void
 */
void motor_loop(void *ptr);

/**
 * Run both motors at full speed for a given duration.
 * args:
 *     ptr: void* - Pointer to duration in seconds
 * returns:
 *     void
 */
void run_for_seconds(void *ptr);

/**
 * Rotate the car for a given duration in a given direction.
 * args:
 *     ptr: void* - Pointer to duration and direction
 * returns:
 *     void
 */
void rotate_for_seconds(void *ptr);
#endif // MOTOR_H
