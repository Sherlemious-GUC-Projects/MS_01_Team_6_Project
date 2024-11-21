#include "gps-neo6m.h"
#include "gyroscope_sensor.h"
#include "hardware/pwm.h"
#include "motor_driver.h"
// #include "servo_driver.h"
#define SERVO_PWM_PIN 15 // GPIO pin for servo PWM signal

int main()
{
  const uint led_pin = 6;
  // Initialize GPIO pin 15 for PWM
  gpio_set_function(SERVO_PWM_PIN, GPIO_FUNC_PWM);

  // Get the PWM slice number for the pin
  uint slice_num = pwm_gpio_to_slice_num(SERVO_PWM_PIN);

  // Set PWM frequency for servo (50Hz, 20ms period)
  pwm_set_wrap(slice_num, 39062);   // Wrap value for 50Hz (20ms period)
  pwm_set_clkdiv(slice_num, 64.0f); // Clock divisor for 50Hz

  // Enable PWM
  pwm_set_enabled(slice_num, true);

  // Set a 1.5ms pulse width (duty cycle for 90°)

  while (true)
  {
    uint16_t pulse_width = 1000;                         // 1.5ms
    uint16_t duty_cycle = (pulse_width * 39062) / 20000; // Scale to the PWM period (50Hz)
    pwm_set_gpio_level(SERVO_PWM_PIN, duty_cycle);       // Apply the duty cycle (1.5ms pulse)
    sleep_ms(2000);                                      // Wait 1 second
    pulse_width = 2500;                                  // 1.5ms
    duty_cycle = (pulse_width * 39062) / 20000;          // Scale to the PWM period (50Hz)
                                                         // Blink LED
    pwm_set_gpio_level(SERVO_PWM_PIN, duty_cycle);       // Apply the duty cycle (1.5ms pulse)
    sleep_ms(1750);                                      // Wait 1 second

    gpio_put(led_pin, true);
    sleep_ms(250);
    gpio_put(led_pin, false);
  }
}
