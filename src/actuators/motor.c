#include "../../include/actuators/motor.h"
#include <stdio.h>

/**
 * motor_initialize
 */
void motor_initialize(uint MOTOR_DIR_PIN1, uint MOTOR_DIR_PIN2,
                      uint MOTOR_PWM_PIN) {
  // Initialize the GPIO pins
  gpio_init(MOTOR_DIR_PIN1);
  gpio_init(MOTOR_DIR_PIN2);

  // Set the GPIO directions
  gpio_set_dir(MOTOR_DIR_PIN1, GPIO_OUT);
  gpio_set_dir(MOTOR_DIR_PIN2, GPIO_OUT);

  // Set the GPIO function to PWM
  gpio_set_function(MOTOR_PWM_PIN, GPIO_FUNC_PWM);

  // Get the PWM slice number for the GPIO pin
  uint slice_num = pwm_gpio_to_slice_num(MOTOR_PWM_PIN);

  // Set the PWM wrap value and clock divider
  pwm_set_wrap(slice_num, 255);
  pwm_set_clkdiv(slice_num, 4.0f);

  // Enable the PWM output
  pwm_set_enabled(slice_num, true);
}

/**
 * motor_setup
 */
void motor_setup() {
  // Setup for FIRST MOTOR
  motor_initialize(MOTOR_1_DIR_PIN1, MOTOR_1_DIR_PIN2, MOTOR_1_PWM_PIN);

  // Setup for SECOND MOTOR
  motor_initialize(MOTOR_2_DIR_PIN1, MOTOR_2_DIR_PIN2, MOTOR_2_PWM_PIN);
}

/**
 * motor_control_helper
 */
void motor_control_helper(uint16_t speed, bool forward, uint MOTOR_DIR_PIN1,
                          uint MOTOR_DIR_PIN2, uint MOTOR_PWM_PIN) {
  // Cap the speed at 255
  speed = speed > 255 ? 255 : speed;

  if (forward) {
    gpio_put(MOTOR_DIR_PIN1, 1); // Forward direction pin
    gpio_put(MOTOR_DIR_PIN2, 0); // Forward direction pin
  } else if (speed > 0) {        // Reverse motor if speed > 0
    gpio_put(MOTOR_DIR_PIN1, 0); // Reverse direction pin
    gpio_put(MOTOR_DIR_PIN2, 1); // Reverse direction pin
  } else {                       // Stop motor if speed = 0
    gpio_put(MOTOR_DIR_PIN1, 0);
    gpio_put(MOTOR_DIR_PIN2, 0);
  }

  // Set the PWM duty cycle
  pwm_set_gpio_level(MOTOR_PWM_PIN, speed);
}

/**
 * motor_control
 */
void motor_control(uint16_t speed, bool forward, uint motor_id) {
  if (motor_id == 1) {
    motor_control_helper(speed, forward, MOTOR_1_DIR_PIN1, MOTOR_1_DIR_PIN2,
                         MOTOR_1_PWM_PIN);
  } else if (motor_id == 2) {
    motor_control_helper(speed, forward, MOTOR_2_DIR_PIN1, MOTOR_2_DIR_PIN2,
                         MOTOR_2_PWM_PIN);
  }
}

/**
 * motor_loop
 */
void motor_loop(void *ptr) {
  uint16_t *seconds = (uint16_t *)ptr;
  while (1) {
    const TickType_t xDelay = *seconds * 1000 / portTICK_PERIOD_MS;

    // Set the motor speed to 100% and direction to forward
    motor_control(255, 1, 1);
    motor_control(255, 1, 2);
    vTaskDelay(xDelay);

    // Set the motor speed to 0% and direction to forward
    motor_control(0, 0, 1);
    motor_control(0, 0, 2);
    vTaskDelay(xDelay);

    // Set the motor speed to 100% and direction to reverse
    motor_control(255, 0, 1);
    motor_control(255, 0, 2);
    vTaskDelay(xDelay);
  }
}

/**
 * run_for_seconds
 */
void run_for_seconds(void *ptr) {
  double *seconds = (double *)ptr;
  printf("IN INNER METHOD : Running for %lf seconds\n", *seconds);

  const TickType_t xDelay = *seconds * 1000 / portTICK_PERIOD_MS;

  // Set the two motors to 100% speed and forward direction
  motor_control(63.0, 1, 1);
  motor_control(63.0, 1, 2);
  vTaskDelay(xDelay);

  // Turn off the motors
  motor_control(0, 0, 1);
  motor_control(0, 0, 2);
}

/**
 * rotate car for seconds in direction
 */
void rotate_for_seconds(void *ptr) {
  void **args = (void **)ptr;
  double *seconds = (double *)args[0];
  int direction = (int)args[1];
  printf("IN INNER METHOD: Rotating for %lf seconds in direction %d\n",
         *seconds, direction);
  const TickType_t xDelay = *seconds * 1000 / portTICK_PERIOD_MS;

  // Set the two motors to 100% speed and forward direction
  motor_control(31.0, direction, 1);
  motor_control(0.0, !direction, 2);
  vTaskDelay(xDelay);

  // Turn off the motors
  motor_control(0, false, 1);
  motor_control(0, false, 2);
}

/**
 * Main loop
 */
void motor_main(void *ptr) {
  // ~~~ parse ~~~ //
  void **args = (void **)ptr;
  double *seconds_1 = (double *)args[0];
  double *seconds_2 = (double *)args[1];
  int direction = *(int *)args[2];
  void *rotation_args[2] = {(void *)seconds_2, (void *)&direction};

  // ~~~ Logging ~~~ //
  printf("=== Motor Control Logs ===\n");
  printf("Run Duration: %lf seconds\n", *seconds_1);
  printf("Rotation Duration: %lf seconds\n", *seconds_2);
  printf("Rotation Direction: %s\n",
         direction ? "Clockwise" : "Counter-Clockwise");
  printf("================================\n");

  // ~~~ rotate ~~~ //
  rotate_for_seconds(rotation_args);

  // ~~~ run ~~~ //
  run_for_seconds((void *)seconds_1);
}
