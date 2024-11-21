#ifndef GPS_NEO6M_H
#define GPS_NEO6M_H

#include <stdbool.h>

// GPS Data Structure
typedef struct {
    float latitude;     // Latitude in decimal degrees
    float longitude;    // Longitude in decimal degrees
    float altitude;     // Altitude in meters
    float speed;        // Ground speed in km/h
    int satellites;     // Number of satellites used
    bool is_valid;      // Whether GPS data is valid
    char time[20];      // UTC time 
} GPSData;

// Initialization function
void uart_gps_init();

// GPS data parsing function
bool parse_nmea_gps(char* nmea_string, GPSData* gps_data);

// Process and extract GPS data
void process_gps_data(GPSData* gps_data);

// Additional utility functions
void convert_nmea_to_decimal(char* nmea_coord, float* decimal_coord);
bool validate_nmea_checksum(char* nmea_string);

#endif // GPS_NEO6M_H
