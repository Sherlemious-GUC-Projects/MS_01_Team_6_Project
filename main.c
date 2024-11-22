#include "gps-neo6m.h"
#include "hardware/pwm.h"
#include "gps-neo6m.h"

int main()
{
  const uint led_pin = 6;

  // Initialize LED pin
  gpio_init(led_pin);
  gpio_set_dir(led_pin, GPIO_OUT);

  // Initialize chosen serial port
  stdio_init_all();
  sleep_ms(5000);

  // Initialize IMU
  /* imu_init(); */
  uart_gps_init();
  sleep_ms(120 * 1000);

  GPSData gps_data = {0};
  int readings = 0;

  // Loop forever
  while (true)
  {
    printf("READING\n %d", readings++);
    process_gps_data(&gps_data);

    if (gps_data.is_valid)
    {
      printf("GPS Location:\n");
      printf("Latitude: %.6f\n", gps_data.latitude);
      printf("Longitude: %.6f\n", gps_data.longitude);
      gps_data.is_valid = false;
    }

    sleep_ms(20000);
  }
}
