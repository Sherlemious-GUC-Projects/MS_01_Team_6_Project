#include <math.h>
#include <stdio.h>

// Constants for conversions
#define METERS_PER_DEGREE_LAT 111320.0 // Approximate meters per degree latitude

// Structure to represent a GPS location
typedef struct location {
  double latitude;
  double longitude;
} location_t;

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

int main() {
  // Example coordinates: Point 1 (source) and Point 2 (destination)
  location_t source = {30.0589287, 31.5075884};
  location_t destination = {30.05986111, 31.50975000};
  // Calculate distance and bearing
  double distance = euclidean_distance(&source, &destination);
  double bearing = calculate_bearing(&source, &destination);

  // Print results
  printf("Euclidean Distance between the two points: %.2f meters\n", distance);
  printf("Bearing angle (theta) from North: %.2f degrees\n", bearing);

  return 0;
}
