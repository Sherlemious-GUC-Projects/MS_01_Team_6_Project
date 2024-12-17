#include "hardware/pwm.h"
#include "hardware/uart.h"

#include "pico/stdlib.h"

#include "include/wifi.h"
#include "include/actuators/motor.h"
#include "include/actuators/servo.h"
#include "include/constants.h"

#include "include/sensors/gps.h"
#include "include/sensors/gyroscope.h"

#include "lib/cJSON.h"

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

void parse_request(car_info_t *car_info){
    char *body_start = strstr(request_body, "\r\n\r\n");
    
    if (!body_start)
    {
        printf("Error: No body found in request\n");
        return;
    }

    body_start += 4;

    cJSON *json = cJSON_Parse(body_start);
    if (!json)
    {
        printf("Error parsing JSON\n");
        return;
    }
    else
    {
        cJSON *heading = cJSON_GetObjectItem(json, "heading");
        if (cJSON_IsNumber(heading))
        {
            car_info->heading = heading->valuedouble;
        }

        cJSON *car = cJSON_GetObjectItem(json, "car");
        if (cJSON_IsObject(car))
        {
            cJSON *lat = cJSON_GetObjectItem(car, "latitude");
            
            if (cJSON_IsNumber(lat))
            {
                car_info->source->latitude = lat->valuedouble;
            }

            cJSON *lng = cJSON_GetObjectItem(car, "longitude");
            
            if (cJSON_IsNumber(lng))
            {
                car_info->source->longitude = lng->valuedouble;
            }
        }
        
        cJSON *destination = cJSON_GetObjectItem(json, "destination");
        if (cJSON_IsObject(destination))
        {
            cJSON *lat = cJSON_GetObjectItem(destination, "latitude");
            if (cJSON_IsNumber(lat))
            {
                car_info->destination->latitude = lat->valuedouble;
            }
            
            cJSON *lng = cJSON_GetObjectItem(destination, "longitude");
            
            if (cJSON_IsNumber(lng))
            {
                car_info->destination->longitude = lng->valuedouble;
            }
        }
    }
    cJSON_Delete(json);
}

int main()
{
  stdio_init_all();

  car_info_t *car_info = malloc(sizeof(car_info_t));
  car_info->source = malloc(sizeof(location_t));
  car_info->destination = malloc(sizeof(location_t));

  if (wifi_setup())
  {
      return 1;
  }

  run_tcp_server_test();

  parse_request(car_info);

  printf("Car Info: \n\n");
  printf("\tHeading: %f\n", car_info->heading);
  printf("\tSource: \n");
  printf("\t\tLatitude: %f\n", car_info->source->latitude);
  printf("\t\tLongitude: %f\n", car_info->source->longitude);
  printf("\tDestination: \n");
  printf("\t\tLatitude: %f\n", car_info->destination->latitude);
  printf("\t\tLongitude: %f\n", car_info->destination->longitude);

  // servo_setup();
  // imu_setup();
  // motor_setup();

  while (true)
  {
    // led_loop();
    // servo_loop();
    // print_gyro(last_time);
    // motor_loop();
  }

  cyw43_arch_deinit();

  return 0;
}
