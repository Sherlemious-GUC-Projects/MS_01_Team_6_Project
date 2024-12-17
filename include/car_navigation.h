#ifndef CAR_NAVIGATION_H
#define CAR_NAVIGATION_H

#include <math.h>

/**
 * @file car_navigation.h
 * @brief Utility functions for car navigation calculations, including
 * distances, bearings, rotation times, and directions.
 */

/**
 * @brief Struct to hold GPS location coordinates (latitude, longitude).
 */
typedef struct location {
  double latitude;  /**< Latitude in degrees */
  double longitude; /**< Longitude in degrees */
} location_t;

/**
 * @brief Struct to hold car information including current and destination
 * positions.
 */
typedef struct car_info {
  location_t *source;      /**< Pointer to the current location */
  location_t *destination; /**< Pointer to the destination location */
  double heading;          /**< Current heading angle in degrees */
} car_info_t;

/**
 * @brief Calculate the Euclidean distance (in meters) between two GPS
 * coordinates.
 *
 * This function approximates the distance between two points on Earth's surface
 * assuming a flat plane, converting latitude and longitude differences to
 * meters.
 *
 * @param point1 Pointer to the first location.
 * @param point2 Pointer to the second location.
 * @return Distance in meters.
 */
double euclidean_distance(location_t *point1, location_t *point2);

/**
 * @brief Calculate the bearing angle (in degrees) from the first point to the
 * second.
 *
 * The angle is measured clockwise from the north direction (0 degrees).
 *
 * @param point1 Pointer to the starting location.
 * @param point2 Pointer to the target location.
 * @return Bearing angle in degrees [0, 360).
 */
double calculate_bearing(location_t *point1, location_t *point2);

/**
 * @brief Calculate the time to reach a destination based on the distance and
 * average speed.
 *
 * @param distance Distance to the destination in meters.
 * @return Time in seconds.
 */
double calculate_time_to_destination(double distance);

/**
 * @brief Determine the optimal rotation direction to align the car with a
 * target bearing.
 *
 * Returns -1 for counter-clockwise rotation and 1 for clockwise rotation.
 *
 * @param bearing Target bearing angle in degrees.
 * @param heading Current heading angle in degrees.
 * @return Rotation direction: -1 (counter-clockwise) or 1 (clockwise).
 */
int calculate_rotation_direction(double bearing, double heading);

/**
 * @brief Calculate the time needed to rotate the car to align with a target
 * bearing.
 *
 * The function considers the shortest rotation path and the average angular
 * speed.
 *
 * @param bearing Target bearing angle in degrees.
 * @param heading Current heading angle in degrees.
 * @return Time to rotate in seconds.
 */
double calculate_time_to_rotate(double bearing, double heading);

#endif // CAR_NAVIGATION_H
