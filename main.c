#include "gps-neo6m.h"
#include "gyroscope_sensor.h"
#include "hardware/pwm.h"
#include "motor_driver.h"
#include "servo_driver.h"
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
  sleep_ms(60 * 1000);
  // configure_gps();
  /* servo_init(); */
  // motor_init();

  GPSData gps_data = {0};
  int readings = 0;

  // absolute_time_t last_time = get_absolute_time();

  // Loop forever
  while (true)
  {
    // print_sensor_contents(last_time);
    printf("READING\n %d", readings++);
    process_gps_data(&gps_data);

    // Check if GPS data is valid and print
    // if (uart_is_readable(UART_ID))
    // {
    //   char c = uart_getc(UART_ID);
    //   printf("TESTING%c", c); // Print received character
    // }
    if (gps_data.is_valid)
    {
      printf("GPS Location:\n");
      printf("Latitude: %.6f\n", gps_data.latitude);
      printf("Longitude: %.6f\n", gps_data.longitude);
      gps_data.is_valid = false;
    }

    // motor_control(255, true);
    sleep_ms(20000);
    // motor_control(0, true);
    // sleep_ms(1000);
    // motor_control(255, false);
    // sleep_ms(1000);
    // motor_control(0, false);
    // sleep_ms(1000);
    /* set_servo_angle(90); // Set servo to 90 degrees */
    // sleep_ms(1000);

    // Blink LED
    // gpio_put(led_pin, true);
    // sleep_ms(1000);
    // gpio_put(led_pin, false);
  }
}
