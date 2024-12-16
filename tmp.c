#include "include/constants.h"
#include "src/car_navigation.c"
#include <math.h>
#include <stdio.h>

int main() {
  // init
  car_info_t car_info = {
      .destination = &(location_t){30.05986111, 31.50975000},
      .source = &(location_t){30.0589287, 31.5075884},
      .heading = 0,
  };

  // calculate distance
  double distance = euclidean_distance(car_info.source, car_info.destination);
  double time_to_destination = calculate_time_to_destination(distance);

  // calculate bearing
  double bearing = calculate_bearing(car_info.source, car_info.destination);
  double time_to_rotate = calculate_time_to_rotate(bearing, car_info.heading);
  int rotation_direction =
      calculate_rotation_direction(bearing, car_info.heading);

  // print
  printf("Distance: %f meters, Time to destination: %f seconds\n", distance,
         time_to_destination);
  printf("Bearing: %f degrees, Time to rotate: %f seconds in direction %s\n",
         bearing, time_to_rotate,
         rotation_direction == 1 ? "clockwise" : "counter-clockwise");

  return 0;
}
