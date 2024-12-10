#include "pico/stdlib.h"
#include "../../include/actuators/led.h"

void led_setup() {
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
}

void led_loop() {
  gpio_put(LED_PIN, true);
  sleep_ms(200);
  gpio_put(LED_PIN, false);
  sleep_ms(200);
}