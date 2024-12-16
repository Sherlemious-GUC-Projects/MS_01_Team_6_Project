#include "hardware/pwm.h"
#include "hardware/uart.h"

#include "pico/stdlib.h"

// #include "include/wifi.h"
#include "include/actuators/motor.h"
#include "include/actuators/servo.h"
#include "include/constants.h"

#include "include/sensors/gps.h"
#include "include/sensors/gyroscope.h"

// #include "lib/cJSON.h"

typedef struct location
{
    double latitude;
    double longitude;
} location_t;

typedef struct car_info
{
    location_t *source;
    location_t *destination;
    double heading;
} car_info_t;

int main()
{
  stdio_init_all();

//   car_info_t *car_info = malloc(sizeof(car_info_t));
//   car_info->source = malloc(sizeof(location_t));
//   car_info->destination = malloc(sizeof(location_t));

//   if (wifi_setup())
//   {
//       return 1;
//   }

//   run_tcp_server_test();

//   parse_request(car_info);

//   printf("Car Info: \n\n");
//   printf("\tHeading: %f\n", car_info->heading);
//   printf("\tSource: \n");
//   printf("\t\tLatitude: %f\n", car_info->source->latitude);
//   printf("\t\tLongitude: %f\n", car_info->source->longitude);
//   printf("\tDestination: \n");
//   printf("\t\tLatitude: %f\n", car_info->destination->latitude);
//   printf("\t\tLongitude: %f\n", car_info->destination->longitude);

  // servo_setup();
  // imu_setup();
  // motor_setup();

  // uart_gps_init();
  // sleep_ms(7 * 60 * 1000);

  // GPSData gps_data = {0};
  // int readings = 0;

  // absolute_time_t last_time = get_absolute_time();

  while (true)
  {
    // led_loop();
    // servo_loop();
    // print_gyro(last_time);
    // motor_loop();

    // printf("READING\n %d", readings++);
    // process_gps_data(&gps_data);

    // if (gps_data.is_valid)
    // {
    //   printf("GPS Location:\n");
    //   printf("Latitude: %.6f\n", gps_data.latitude);
    //   printf("Longitude: %.6f\n", gps_data.longitude);
    //   gps_data.is_valid = false;
    // }

    // printf(MAGENTA, "*******************************************************************\n");
    // sleep_ms(30 * 1000);
  }

//   cyw43_arch_deinit();

  return 0;
}
