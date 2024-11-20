#include "gyroscope_sensor.h"

int main() {
  const uint led_pin = 6;

  // Initialize LED pin
  gpio_init(led_pin);
  gpio_set_dir(led_pin, GPIO_OUT);

  // Initialize chosen serial port
  stdio_init_all();

  // Initialize IMU
  imu_init();

  absolute_time_t last_time = get_absolute_time();

  // Loop forever
  while (true) {
    print_sensor_contents(last_time);
    // Blink LED
    // gpio_put(led_pin, true);
    sleep_ms(1000);
    // gpio_put(led_pin, false);
    // sleep_ms(500);
  }
}
