#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"

#include "hardware/i2c.h"
#include "hardware/pwm.h"
#include "hardware/uart.h"
#include "pico/stdlib.h"

#include "src/actuators/led.c"
#include "src/actuators/motor.c"
#include "src/sensors/gyroscope.c"

typedef struct location {
  double latitude;
  double longitude;
} location_t;

typedef struct car_info {
  location_t *source;
  location_t *destination;
  double heading;
} car_info_t;

int main() {
  // ~~~ BETA ~~~ //
  car_info_t car_info = {
      .destination = &(location_t){30.05986111, 31.50975000},
      .source = &(location_t){30.0589287, 31.5075884},
      .heading = 0,
  };
  // ~~~ SETUP PICO ~~~ //
  stdio_init_all();

  // ~~~ INITIALIZATION ~~~ //
  motor_setup();

  // ~~~ TASKS ~~~ //
  xTaskCreate(motor_loop, "Motor Loop", 256, NULL, 1, NULL);

  // ~~~ START SCHEDULER ~~~ //
  vTaskStartScheduler();

  while (1) {
  };
}
