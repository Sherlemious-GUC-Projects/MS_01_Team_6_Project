#include "../../include/actuators/led.h"

void led_setup() {
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
}

void led_loop() {
  while (1) {
    gpio_put(LED_PIN, 1);
    vTaskDelay(pdMS_TO_TICKS(200));
    gpio_put(LED_PIN, 0);
    vTaskDelay(pdMS_TO_TICKS(200));
    sleep_ms(200);
  }
}
