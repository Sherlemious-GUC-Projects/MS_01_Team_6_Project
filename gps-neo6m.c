#include "gps-neo6m.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define UART_ID uart0
#define BAUD_RATE 9600
#define UART_TX_PIN 0
#define UART_RX_PIN 1
#define MAX_NMEA_LENGTH 100

void uart_gps_init()
{
    // Initialize UART with more robust configuration
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_set_format(UART_ID, 8, 1, UART_PARITY_NONE);
    uart_set_fifo_enabled(UART_ID, true);
}

bool validate_nmea_checksum(char *nmea_string)
{
    // Basic NMEA checksum validation
    int len = strlen(nmea_string);
    if (len < 4)
        return false;

    char *checksum_ptr = strchr(nmea_string, '*');
    if (!checksum_ptr)
        return false;

    // Calculate checksum
    uint8_t checksum = 0;
    for (int i = 1; nmea_string[i] != '*'; i++)
    {
        checksum ^= nmea_string[i];
    }

    // Compare calculated with provided
    char calc_checksum[3];
    snprintf(calc_checksum, sizeof(calc_checksum), "%02X", checksum);
    return strncmp(calc_checksum, checksum_ptr + 1, 2) == 0;
}

void convert_nmea_to_decimal(char *nmea_coord, float *decimal_coord)
{
    // Convert NMEA coordinate to decimal degrees
    float degrees = atof(nmea_coord) / 100.0;
    int int_degrees = (int)degrees;
    float minutes = (degrees - int_degrees) * 100.0;

    *decimal_coord = int_degrees + (minutes / 60.0);
}

bool parse_nmea_gps(char *nmea_string, GPSData *gps_data)
{
    // More comprehensive NMEA parsing
    if (!validate_nmea_checksum(nmea_string))
    {
        return false;
    }

    if (strncmp(nmea_string, "$GPGGA", 6) == 0)
    {
        char *tokens[15];
        int token_count = 0;
        char *token = strtok(nmea_string, ",");

        while (token != NULL && token_count < 15)
        {
            tokens[token_count++] = token;
        }

        if (token_count >= 10)
        {
            // Time
            strncpy(gps_data->time, tokens[1], sizeof(gps_data->time) - 1);

            // Latitude
            if (strlen(tokens[2]) > 0)
            {
                convert_nmea_to_decimal(tokens[2], &gps_data->latitude);
                if (tokens[3][0] == 'S')
                    gps_data->latitude = -gps_data->latitude;
            }

            // Longitude
            if (strlen(tokens[4]) > 0)
            {
                convert_nmea_to_decimal(tokens[4], &gps_data->longitude);
                if (tokens[5][0] == 'W')
                    gps_data->longitude = -gps_data->longitude;
            }

            // Altitude
            gps_data->altitude = atof(tokens[9]);

            // Satellites
            gps_data->satellites = atoi(tokens[7]);

            gps_data->is_valid = true;
            return true;
        }
    }

    return false;
}

void process_gps_data(GPSData *gps_data)
{
    char nmea_buffer[MAX_NMEA_LENGTH];
    int chars_read = 0;

    while (uart_is_readable(UART_ID) && chars_read < MAX_NMEA_LENGTH - 1)
    {
        nmea_buffer[chars_read] = uart_getc(UART_ID);

        if (nmea_buffer[chars_read] == '\n')
        {
            nmea_buffer[chars_read + 1] = '\0';

            if (parse_nmea_gps(nmea_buffer, gps_data))
            {
                // Optional: Add logging or further processing
                printf("Valid GPS Data Received\n");
            }

            chars_read = 0;
        }
        else
        {
            chars_read++;
        }
    }
}
