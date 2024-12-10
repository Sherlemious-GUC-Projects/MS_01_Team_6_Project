#include "hardware/pwm.h"
#include "../../include/actuators/motor.h"

void motor_setup() {
  gpio_init(MOTOR_DIR_PIN1);
  gpio_init(MOTOR_DIR_PIN2);

  gpio_set_dir(MOTOR_DIR_PIN1, GPIO_OUT);
  gpio_set_dir(MOTOR_DIR_PIN2, GPIO_OUT);

  gpio_set_function(MOTOR_PWM_PIN, GPIO_FUNC_PWM);

  uint slice_num = pwm_gpio_to_slice_num(MOTOR_PWM_PIN);

  pwm_set_wrap(slice_num, 255);
  pwm_set_clkdiv(slice_num, 4.0f);

  pwm_set_enabled(slice_num, true);
}

void motor_control(uint16_t speed, bool forward) {
  speed = speed > 255 ? 255 : speed;

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

void motor_loop() {
  // Set the motor speed to 50% and direction to forward
  motor_control(127, true);
  sleep_ms(2000);

  // Set the motor speed to 50% and direction to reverse
  motor_control(127, false);
  sleep_ms(2000);

  // Set the motor to MAX speed and direction to forward
  motor_control(255, true);
}
