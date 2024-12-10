#include "hardware/pwm.h"
#include "../../include/actuators/servo.h"

void servo_setup() {
  gpio_set_function(SERVO_PWM_PIN, GPIO_FUNC_PWM);

  uint slice_num = pwm_gpio_to_slice_num(SERVO_PWM_PIN);

  // Set PWM frequency for servo (50Hz, 20ms period)
  pwm_set_wrap(slice_num, 39062);   // Wrap value for 50Hz (20ms period)
  pwm_set_clkdiv(slice_num, 64.0f); // Clock divisor for 50Hz

  pwm_set_enabled(slice_num, true);
}

void set_servo_angle(uint16_t angle) {
  // Convert angle (0-180) to pulse width (1ms to 2ms)
  uint16_t pulse_width = 1000 + (angle * 1000 / 180);
  uint16_t duty_cycle = (pulse_width * 39062 / 20000);

  pwm_set_gpio_level(SERVO_PWM_PIN, duty_cycle);
}

void servo_loop() {
  set_servo_angle(0);
  sleep_ms(1000);
  set_servo_angle(270);
  sleep_ms(1000);
}