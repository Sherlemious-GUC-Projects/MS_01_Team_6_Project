#include "servo_driver.h"
#include "hardware/pwm.h"

void servo_init()
{
    // Initialize the PWM pin
    gpio_set_function(SERVO_PWM_PIN, GPIO_FUNC_PWM);

    // Get the PWM slice number
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PWM_PIN);

    // Set PWM frequency for servo (50 Hz)
    pwm_set_clkdiv(slice_num, 64.0f);   // Clock divisor
    pwm_set_wrap(slice_num, 20000 - 1); // Wrap value for 50 Hz (20 ms period)

    // Enable PWM
    pwm_set_enabled(slice_num, true);
}

void servo_control(uint16_t angle)
{
    // Convert angle (0-180 degrees) to PWM duty cycle (1ms to 2ms pulse)
    uint16_t duty_cycle = 1000 + (angle * 1000 / 180);

    // Get the PWM slice number
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PWM_PIN);

    // Set the PWM duty cycle
    pwm_set_gpio_level(SERVO_PWM_PIN, duty_cycle);
}
