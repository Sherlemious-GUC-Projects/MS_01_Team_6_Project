#include "include/constants.h"
#include <math.h>
#include <stdio.h>

typedef struct location {
  double latitude;
  double longitude;
} location_t;

typedef struct car_info {
  location_t *source;
  location_t *destination;
  double heading;
} car_info_t;

// Function to calculate the Euclidean distance between two GPS coordinates
double euclidean_distance(location_t *point1, location_t *point2) {
  // Convert latitude and longitude differences to meters
  double delta_lat_meters =
      (point2->latitude - point1->latitude) * METERS_PER_DEGREE_LAT;
  double avg_lat_rad =
      (point1->latitude + point2->latitude) / 2.0 * (M_PI / 180.0);
  double meters_per_degree_lon = METERS_PER_DEGREE_LAT * cos(avg_lat_rad);
  double delta_lon_meters =
      (point2->longitude - point1->longitude) * meters_per_degree_lon;

  // Use Pythagorean theorem to compute the distance
  return sqrt(delta_lat_meters * delta_lat_meters +
              delta_lon_meters * delta_lon_meters);
}

// Function to calculate the bearing angle (theta) starting from North
double calculate_bearing(location_t *point1, location_t *point2) {
  double delta_lon = point2->longitude - point1->longitude;
  double delta_lat = point2->latitude - point1->latitude;

  double theta_rad = atan2(delta_lon, delta_lat);
  double theta_deg =
      fmod((theta_rad * (180.0 / M_PI) + 360.0), 360.0); // Normalize to 0-360

  return theta_deg;
}

// function to calculate the time to reach the destination given in seconds
double calculate_time_to_destination(double distance) {
  return distance / APPROX_AVG_SPEED;
}

int calculate_rotation_direction(double bearing, double heading) {
  /*
   * Calculate the absolute difference between bearing and heading If the
   * difference exceeds 180 degrees, rotate counter-clockwise (-1), else rotate
   * clockwise (1)
   */
  return fabs(bearing - heading) > 180.0 ? -1 : 1;
}

// Calculate rotation time (in seconds) to align car's heading with the
// destination bearing
double calculate_time_to_rotate(double bearing, double heading) {
  // Normalize the heading difference to the shortest rotation path
  double delta_heading =
      fmin(fabs(bearing - heading), 360.0 - fabs(bearing - heading));

  // Return the rotation time based on the average angular speed
  return delta_heading / APPROX_AVG_ANGULAR_SPEED;
}

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
