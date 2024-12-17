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
    gpio_put(MOTOR_DIR_PIN1, 1); // Forward direction pin
    gpio_put(MOTOR_DIR_PIN2, 0); // Forward direction pin
  } else if (speed > 0) {        // If speed is greater than 0, reverse motor
    gpio_put(MOTOR_DIR_PIN1, 0); // Reverse direction pin
    gpio_put(MOTOR_DIR_PIN2, 1); // Reverse direction pin
  } else {                       // If speed is 0, stop the motor
    gpio_put(MOTOR_DIR_PIN1, 0); // Both pins low to stop the motor
    gpio_put(MOTOR_DIR_PIN2, 0); // Both pins low to stop the motor
  }

  // set the PWM duty cycle
  pwm_set_gpio_level(MOTOR_PWM_PIN, speed);
}

void motor_loop(void *ptr) {
  uint16_t *seconds = (uint16_t *)ptr;
  while (1) {
    const TickType_t xDelay = *seconds * 1000 / portTICK_PERIOD_MS;

    // Set the motor speed to 100% and direction to forward
    motor_control(255, true);
    vTaskDelay(xDelay);

    // set the motor speed to 0% and direction to forward
    motor_control(0, true);
    vTaskDelay(xDelay);

    // Set the motor speed to 100% and direction to reverse
    motor_control(255, false);
    vTaskDelay(xDelay);
  }
}

void run_for_seconds(void *ptr) {
  uint16_t *seconds = (uint16_t *)ptr;
  const TickType_t xDelay = *seconds * 1000 / portTICK_PERIOD_MS;

  // Set the motor speed to 50% and direction to forward
  motor_control(255, 1);
  vTaskDelay(xDelay);

  // turn off the motor
  motor_control(0, 0);
  vTaskDelay(xDelay);
}
