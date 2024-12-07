#include "hardware/pwm.h"
#include "hardware/uart.h"

#include "pico/stdlib.h"

#include "include/actuators/led.h"
#include "include/actuators/motor.h"
#include "include/actuators/servo.h"
#include "include/constants.h"

#include "include/sensors/gps.h"
#include "include/sensors/gyroscope.h"

int main()
{
  stdio_init_all();
  // sleep_ms(500);

  led_setup();
  // servo_setup();
  // imu_setup();
  // motor_setup();

  uart_gps_init();
  sleep_ms(7 * 60 * 1000);

  GPSData gps_data = {0};
  int readings = 0;

  absolute_time_t last_time = get_absolute_time();

  while (true)
  {
    led_loop();
    // servo_loop();
    // print_gyro(last_time);
    // motor_loop();

    printf("READING\n %d", readings++);
    process_gps_data(&gps_data);

    if (gps_data.is_valid)
    {
      printf("GPS Location:\n");
      printf("Latitude: %.6f\n", gps_data.latitude);
      printf("Longitude: %.6f\n", gps_data.longitude);
      gps_data.is_valid = false;
    }

    printf(MAGENTA, "*******************************************************************\n");
    sleep_ms(30 * 1000);
  }

  return 0;
}
