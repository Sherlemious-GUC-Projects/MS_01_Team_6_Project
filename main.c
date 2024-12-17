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

#include "src/car_navigation.c"

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
  double distance = euclidean_distance(car_info.source, car_info.destination);
  /* uint16_t run_time = (uint16_t)calculate_time_to_destination(distance); */
  uint16_t run_time = 3; // BETA CODE!!!
  motor_setup();

  // ~~~ TASKS ~~~ //
  xTaskCreate(run_for_seconds, "Run Motor", 256, (void *)&run_time, 1, NULL);

  // ~~~ START SCHEDULER ~~~ //
  vTaskStartScheduler();

  while (1) {
  };
}
