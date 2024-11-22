#include "motor_driver.h"
#include "hardware/pwm.h"

void motor_init(void) {
  // set the dir pins as output
  gpio_init(MOTOR_DIR_PIN1);
  gpio_init(MOTOR_DIR_PIN2);
  gpio_set_dir(MOTOR_DIR_PIN1, GPIO_OUT);
  gpio_set_dir(MOTOR_DIR_PIN2, GPIO_OUT);

  // set the PWM pin as output for speed control
  gpio_set_function(MOTOR_PWM_PIN, GPIO_FUNC_PWM);

  // get the PWM slice number
  uint slice_num = pwm_gpio_to_slice_num(MOTOR_PWM_PIN);

  // set the PWM configuration: wrap value, and clock divider
  pwm_set_wrap(slice_num, 255);
  pwm_set_clkdiv(slice_num, 4.0f);

  // enable the PWM output
  pwm_set_enabled(slice_num, true);
}

void motor_control(uint16_t speed, bool forward) {
  // constrain the speed value to 0-255
  speed = speed > 255 ? 255 : speed;

  // set the direction pins
  if (forward) {
    gpio_put(MOTOR_DIR_PIN1, 1);
    gpio_put(MOTOR_DIR_PIN2, 0);
  } else {
    gpio_put(MOTOR_DIR_PIN1, 0);
    gpio_put(MOTOR_DIR_PIN2, 1);
  }

  // set the PWM duty cycle
  pwm_set_gpio_level(MOTOR_PWM_PIN, speed);
}
