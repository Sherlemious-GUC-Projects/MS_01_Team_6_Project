#include "led.h"
#include "pico/stdlib.h"
#include <stdio.h>

// Initialize LED pins
void LED_Init(void) {
  // Set RED and GREEN LEDs as output (Positive logic)
  gpio_init(RED_LED_PIN);
  gpio_set_dir(RED_LED_PIN, GPIO_OUT);
  gpio_init(GREEN_LED_PIN);
  gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

  // Set BLUE LED as output (Negative logic)
  gpio_init(BLUE_LED_PIN);
  gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

  // Turn off all LEDs initially
  LED_Off(RED_LED_PIN);
  LED_Off(GREEN_LED_PIN);
  LED_Off(BLUE_LED_PIN);
}

// Turn on the specified LED
void LED_On(uint8_t led_pin) {
  if (led_pin == BLUE_LED_PIN) {
    // Negative logic for BLUE LED
    gpio_put(led_pin, 0);
  } else {
    // Positive logic for RED and GREEN LEDs
    gpio_put(led_pin, 1);
  }
}

// Turn off the specified LED
void LED_Off(uint8_t led_pin) {
  if (led_pin == BLUE_LED_PIN) {
    // Negative logic for BLUE LED
    gpio_put(led_pin, 1);
  } else {
    // Positive logic for RED and GREEN LEDs
    gpio_put(led_pin, 0);
  }
}

int main(void) {
  // Initialize stdio and LEDs
  stdio_init_all();
  LED_Init();

  // Initial delay of 5 seconds

  while (1) {
    // sleep_ms(5000);
    // Red LED on for 1 second
    LED_On(RED_LED_PIN);
    sleep_ms(1000);
    LED_Off(RED_LED_PIN);

    // Green LED on for 1 second
    LED_On(GREEN_LED_PIN);
    sleep_ms(1000);
    LED_Off(GREEN_LED_PIN);

    // Blue LED on for 1 second
    LED_Off(BLUE_LED_PIN);
    sleep_ms(1000);
    LED_On(BLUE_LED_PIN);

    // All LEDs on for 2 seconds
    LED_On(RED_LED_PIN);
    LED_On(GREEN_LED_PIN);
    LED_Off(BLUE_LED_PIN);
    sleep_ms(2000);
    LED_Off(RED_LED_PIN);
    LED_Off(GREEN_LED_PIN);
    LED_On(BLUE_LED_PIN);
  }

  return 0;
}
