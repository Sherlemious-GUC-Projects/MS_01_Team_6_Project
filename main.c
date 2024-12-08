#include "FreeRTOS.h"
#include "pico/stdlib.h"
#include "task.h"

#include "src/actuators/led.c"

int main() {
  // ~~~ SETUP PICO ~~~ //
  stdio_init_all();

  // ~~~ INITIALIZATION ~~~ //
  led_setup();

  xTaskCreate(led_loop, "LED_Task", 256, NULL, 1, NULL);
  vTaskStartScheduler();

  while (1) {
  };
}
