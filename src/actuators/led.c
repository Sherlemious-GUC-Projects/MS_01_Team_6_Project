#include "../../include/actuators/led.h"
#include "pico/stdlib.h"

void led_setup() {
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
}

void led_loop() {
  gpio_put(LED_PIN, 1);
  sleep_ms(2000);
  gpio_put(LED_PIN, 0);
  sleep_ms(200);
}
