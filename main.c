#include "FreeRTOS.h"
#include "hardware/uart.h"
#include "pico/stdlib.h"
#include "task.h"

#include "src/actuators/led.c"
#include "src/actuators/motor.c"
#include "src/sensors/gyroscope.c"

int main() {
  // ~~~ SETUP PICO ~~~ //
  stdio_init_all();

  // ~~~ INITIALIZATION ~~~ //
  led_setup();
  motor_setup();

  // ~~~ TASKS ~~~ //
  xTaskCreate(led_loop, "LED_Task", 256, NULL, 1, NULL);
  xTaskCreate(motor_loop, "Motor_Task", 256, NULL, 1, NULL);

  // ~~~ START SCHEDULER ~~~ //
  vTaskStartScheduler();

  while (1) {
  };
}
