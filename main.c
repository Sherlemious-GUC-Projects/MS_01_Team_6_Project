#include <FreeRTOS.h>

#include "hardware/pwm.h"
#include "hardware/uart.h"

#include "pico/stdlib.h"

#include "include/actuators/led.h"
#include "include/actuators/motor.h"
#include "include/actuators/servo.h"

#include "include/sensors/gps.h"
#include "include/sensors/gyroscope.h"

int main() {
  // set up the stdio for the RP2040
  stdio_init_all();
  TickType_t xLastWakeTime = xTaskGetTickCount();

  // ~~~ Setup ~~~ //
  led_setup();
  // servo_setup();
  // imu_setup();
  // motor_setup();

  // ~~~ Loop ~~~ //
  int led_delay = 1000;
  void *arr[2] = {&led_delay, &xLastWakeTime};
  xTaskCreate(led_loop, "led_loop", 256, (void *)arr, 1, NULL);

  // ~~~ SCHEUDLER ~~~ //
  vTaskStartScheduler();

  // ~~~ Main Loop ~~~ //
  while (1) {
  };

  return 0;
}
