#include "../../include/actuators/led.h"
#include "pico/stdlib.h"
#include <FreeRTOS.h>

void led_setup() {
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
}

void led_loop(void *ptr) {
  /* ptr has an integer which is the delay and a TickType_t which is the time */
  void **pte = (void **)ptr;
  int *x_ptr = (int *)pte[0];
  TickType_t *y = (TickType_t *)pte[1];

  TickType_t xPeriod = pdMS_TO_TICKS(*x_ptr);
  TickType_t xLastWakeTime = *y;
  while (1) {
    gpio_put(LED_PIN, true);
    vTaskDelayUntil(&xLastWakeTime, xPeriod);
    gpio_put(LED_PIN, false);
    vTaskDelayUntil(&xLastWakeTime, xPeriod);
  }
}
