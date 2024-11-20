#ifndef LED_H
#define LED_H

#include <stdint.h>

// Define LED pins
#define RED_LED_PIN    25  // D2
#define GREEN_LED_PIN  15  // D3
#define BLUE_LED_PIN   16  // D4

// Function prototypes
void LED_Init(void);
void LED_On(uint8_t led_pin);
void LED_Off(uint8_t led_pin);

#endif // LED_H