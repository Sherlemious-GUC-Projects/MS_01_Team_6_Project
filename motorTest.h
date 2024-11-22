#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <stdint.h>
#include <stdbool.h>



#define MOTOR1_PWM_PIN 0
#define MOTOR1_DIR_PIN1 16
#define MOTOR1_DIR_PIN2 17


void motor_init();
void motor_control(uint16_t speed, bool direction);

#endif // MOTOR_CONTROL_H