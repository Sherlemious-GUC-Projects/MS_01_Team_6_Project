#include "motor_driver.h"
#include "hardware/pwm.h"

void motor_init() {
  // Initialize the GPIO pins
  gpio_init(MOTOR_DIR_PIN1);
  gpio_set_dir(MOTOR_DIR_PIN1, GPIO_OUT);
  gpio_init(MOTOR_DIR_PIN2);
  gpio_set_dir(MOTOR_DIR_PIN2, GPIO_OUT);

  // Initialize the PWM
  gpio_set_function(MOTOR_PWM_PIN, GPIO_FUNC_PWM);

  // Get PWM slice number
  uint slice_num = pwm_gpio_to_slice_num(MOTOR_PWM_PIN);

  // Set the PWM Config
  pwm_set_wrap(slice_num, 255);
  pwm_set_clkdiv(slice_num, 4.0f);

  // enable PWM output
  pwm_set_enabled(slice_num, true);
}

void motor_control(uint16_t speed, bool direction) {
  // control speed
  if (speed > 255) {
    speed = 255;
  }
  // control direction
  if (direction) {
    gpio_put(MOTOR_DIR_PIN1, 1);
    gpio_put(MOTOR_DIR_PIN2, 0);
  } else {
    gpio_put(MOTOR_DIR_PIN1, 0);
    gpio_put(MOTOR_DIR_PIN2, 1);
  }
  // set PWM duty cycle
  pwm_set_gpio_level(MOTOR_PWM_PIN, speed);
}
