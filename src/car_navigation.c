#include "../include/car_navigation.h"

/**
 * @brief Calculate the Euclidean distance (in meters) between two GPS
 * coordinates.
 */
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

/**
 * @brief Calculate the bearing angle (in degrees) from the first point to the
 * second.
 */
double calculate_bearing(location_t *point1, location_t *point2) {
  double delta_lon = point2->longitude - point1->longitude;
  double delta_lat = point2->latitude - point1->latitude;

  double theta_rad = atan2(delta_lon, delta_lat);
  return fmod((theta_rad * (180.0 / M_PI) + 360.0),
              360.0); // Normalize to 0-360
}

/**
 * @brief Calculate the time to reach a destination based on the distance and
 * average speed.
 */
double calculate_time_to_destination(double distance) {
  return distance / APPROX_AVG_SPEED;
}

/**
 * @brief Determine the optimal rotation direction to align the car with a
 * target bearing.
 */
int calculate_rotation_direction(double bearing, double heading) {
  return fabs(bearing - heading) > 180.0 ? -1 : 1;
}

/**
 * @brief Calculate the time needed to rotate the car to align with a target
 * bearing.
 */
double calculate_time_to_rotate(double bearing, double heading) {
  double delta_heading =
      fmin(fabs(bearing - heading), 360.0 - fabs(bearing - heading));
  printf("=== Rotation Details ===\n");
  printf("Bearing: %f\n", bearing);
  printf("Heading: %f\n", heading);
  printf("Delta heading: %f\n", delta_heading);
  printf("Time to rotate: %f\n", delta_heading / APPROX_AVG_ANGULAR_SPEED);
  printf("================================\n");
  return delta_heading / APPROX_AVG_ANGULAR_SPEED;
}
