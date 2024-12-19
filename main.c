#include "hardware/pwm.h"
#include "hardware/uart.h"

#include "pico/stdlib.h"

#include "include/actuators/motor.h"
#include "include/actuators/servo.h"
#include "include/car_navigation.h"
#include "include/constants.h"
#include "include/wifi.h"

#include "include/sensors/gps.h"
#include "include/sensors/gyroscope.h"

#include "lib/cJSON.h"

void parse_request(car_info_t *car_info) {
  char *body_start = strstr(request_body, "\r\n\r\n");

  if (!body_start) {
    printf("Error: No body found in request\n");
    return;
  }

  body_start += 4;

  cJSON *json = cJSON_Parse(body_start);
  if (!json) {
    printf("Error parsing JSON\n");
    return;
  } else {
    cJSON *heading = cJSON_GetObjectItem(json, "heading");
    if (cJSON_IsNumber(heading)) {
      car_info->heading = heading->valuedouble;
    }

    cJSON *car = cJSON_GetObjectItem(json, "car");
    if (cJSON_IsObject(car)) {
      cJSON *lat = cJSON_GetObjectItem(car, "latitude");

      if (cJSON_IsNumber(lat)) {
        car_info->source->latitude = lat->valuedouble;
      }

      cJSON *lng = cJSON_GetObjectItem(car, "longitude");

      if (cJSON_IsNumber(lng)) {
        car_info->source->longitude = lng->valuedouble;
      }
    }

    cJSON *destination = cJSON_GetObjectItem(json, "destination");
    if (cJSON_IsObject(destination)) {
      cJSON *lat = cJSON_GetObjectItem(destination, "latitude");
      if (cJSON_IsNumber(lat)) {
        car_info->destination->latitude = lat->valuedouble;
      }

      cJSON *lng = cJSON_GetObjectItem(destination, "longitude");

      if (cJSON_IsNumber(lng)) {
        car_info->destination->longitude = lng->valuedouble;
      }
    }
  }
  cJSON_Delete(json);
}

void log_custom(car_info_t *car_info) {
  printf("Car Info: \n\n");
  printf("\tHeading: %f\n", car_info->heading);
  printf("\tSource: \n");
  printf("\t\tLatitude: %f\n", car_info->source->latitude);
  printf("\t\tLongitude: %f\n", car_info->source->longitude);
  printf("\tDestination: \n");
  printf("\t\tLatitude: %f\n", car_info->destination->latitude);
  printf("\t\tLongitude: %f\n", car_info->destination->longitude);
}

int main() {
  // ~~~ SETUP PICO ~~~ //
  stdio_init_all();

  // ~~~ SETUP structs ~~~ //
  car_info_t *car_info = malloc(sizeof(car_info_t));
  car_info->source = malloc(sizeof(location_t));
  car_info->destination = malloc(sizeof(location_t));

  // ~~~ SETUP WIFI to connect to the internet ~~~ //
  sleep_ms(2000);
  if (wifi_setup()) {
    return 1;
  }

  // ~~ SETUP TCP SERVER to receive requests ~~~ //
  run_tcp_server_test();

  // ~~~ PARSE REQUEST ~~~ //
  parse_request(car_info);

  // ~~~ NORMALIZE HEADING ~~~ //
  car_info->heading = fmax(0, fmin(360, car_info->heading));

  // ~~~ LOG CAR INFO ~~~ //
  log_custom(car_info);

  // ~~~ CALCULATE DETAILS ~~~ //
  double distance = euclidean_distance(car_info->source, car_info->destination);
  double run_time = calculate_time_to_destination(distance);
  double bearing = calculate_bearing(car_info->source, car_info->destination);
  double rotation_time = calculate_time_to_rotate(bearing, car_info->heading);
  int rotation_direction =
      calculate_rotation_direction(bearing, car_info->heading);
  void *args[3] = {(void *)&run_time, (void *)&rotation_time,
                   (void *)&rotation_direction};

  // ~~~ MORE LOGGING ~~~ //
  printf("=== Sensor and Control Logs ===\n");
  printf("Bearing: %lf degrees\n", bearing);
  printf("Distance Traveled: %lf meters\n", distance);
  printf("Run Time: %lf s\n", run_time);
  printf("Rotation: %lf seconds (%s)\n", rotation_time,
         rotation_direction == 1 ? "Clockwise" : "Counter-Clockwise");
  printf("================================\n");

  // ~~~ SETUP MOTOR ~~~ //
  motor_setup();

  // ~~~ TASKS ~~~ //
  xTaskCreate(motor_main, "motor_main", 1024, args, 1, NULL);

  // ~~~ START SCHEDULER ~~~ //
  vTaskStartScheduler();

  while (1) {
  };

  cyw43_arch_deinit();

  return 0;
}
