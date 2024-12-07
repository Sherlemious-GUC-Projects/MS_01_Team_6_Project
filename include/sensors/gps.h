#pragma once

#include "../../include/circularBuffer.h"
#include "../../include/constants.h"

#define UART_ID uart1
#define BAUD_RATE 9600
#define UART_TX_PIN 4 // D12
#define UART_RX_PIN 5 // D10
#define MAX_NMEA_LENGTH 256

typedef struct
{
  float latitude;  // Latitude in decimal degrees
  float longitude; // Longitude in decimal degrees
  bool is_valid;   // Whether GPS data is valid
} GPSData;

// Initialization function
void uart_gps_init();

// GPS data parsing function
bool parse_nmea_gps(char *nmea_string, GPSData *gps_data);

// Process and extract GPS data
void process_gps_data(GPSData *gps_data, CircularBuffer *cb);

// Additional utility functions
void convert_nmea_to_decimal(char *nmea_coord, float *decimal_coord);
bool validate_nmea_checksum(char *nmea_string);
