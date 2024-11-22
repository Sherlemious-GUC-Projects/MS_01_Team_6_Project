#include "servo_driver.h"
#include "hardware/pwm.h"

void servo_init() {
  // Initialize the PWM pin
  gpio_set_function(SERVO_PWM_PIN, GPIO_FUNC_PWM);

  // Get the PWM slice number
  uint slice_num = pwm_gpio_to_slice_num(SERVO_PWM_PIN);

  // Set PWM frequency for servo (50 Hz)
  pwm_set_wrap(slice_num, 255);    // Wrap value for 50 Hz (20 ms period)
  pwm_set_clkdiv(slice_num, 4.0f); // Clock divisor

  // Enable PWM
  pwm_set_enabled(slice_num, true);
}

void set_servo_angle(uint16_t angle) {
  // Convert angle (0-180) to pulse width (1ms to 2ms)
  uint16_t pulse_width = 1000 + (angle * 1000 / 180); // 1000us to 2000us
  uint16_t duty_cycle =
      (pulse_width * 5000) / 20000; // Convert to duty cycle (0-5000)

  uint slice_num = pwm_gpio_to_slice_num(SERVO_PWM_PIN);
  pwm_set_gpio_level(SERVO_PWM_PIN, duty_cycle);
}
