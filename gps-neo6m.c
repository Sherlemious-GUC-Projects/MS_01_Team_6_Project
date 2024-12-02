#include "gps-neo6m.h"
#include "hardware/uart.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BAUD_RATE 9600
#define UART_TX_PIN 0 // D12
#define UART_RX_PIN 1 // D10
#define MAX_NMEA_LENGTH 100

void uart_gps_init() {
  // Initialize UART with more robust configuration
  uart_init(UART_ID, BAUD_RATE);

  // gpio_set_function(UART_TX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_TX_PIN));
  // gpio_set_function(UART_RX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_RX_PIN));

  gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
  gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

  uart_set_format(UART_ID, 8, 1, UART_PARITY_NONE);
  uart_set_fifo_enabled(UART_ID, true);

  uart_set_hw_flow(UART_ID, false, false);
  uart_set_irq_enables(UART_ID, true, false);
}

void send_gps_command(const char *command) {
  uart_puts(UART_ID, command);
  uart_puts(UART_ID, "\r\n");
}

void configure_gps() {
  // Enable $GPGGA (Global Positioning System Fix Data)
  send_gps_command("$PUBX,40,GGA,1,1,1,1,1,1*1D");
  sleep_ms(250);

  // Enable $GPRMC (Recommended Minimum Specific GPS/Transit Data)
  send_gps_command("$PUBX,40,RMC,1,1,1,1,1,1*1D");
  sleep_ms(250);

  // Enable $GPGSA (GPS DOP and Active Satellites)
  send_gps_command("$PUBX,40,GSA,1,1,1,1,1,1*1E");
  sleep_ms(250);

  // Enable $GPGSV (GPS Satellites in View)
  send_gps_command("$PUBX,40,GSV,1,1,1,1,1,1*1F");
  sleep_ms(250);
}

bool validate_nmea_checksum(char *nmea_string) {

  int len = strlen(nmea_string);
  if (len < 7)
    return false; // Minimum valid NMEA sentence length

  char *checksum_ptr = strchr(nmea_string, '*');
  if (!checksum_ptr)
    return false;

  uint8_t calculated_checksum = 0;
  for (char *p = nmea_string + 1; p < checksum_ptr; p++) {
    calculated_checksum ^= *p;
  }

  char hex_checksum[3];
  snprintf(hex_checksum, sizeof(hex_checksum), "%02X", calculated_checksum);
  return strncmp(hex_checksum, checksum_ptr + 1, 2) == 0;
}

void convert_nmea_to_decimal(char *nmea_coord, float *decimal_coord) {
  // Convert NMEA coordinate to decimal degrees
  float degrees = atof(nmea_coord) / 100.0;
  int int_degrees = (int)degrees;
  float minutes = (degrees - int_degrees) * 100.0;

  *decimal_coord = int_degrees + (minutes / 60.0);
}

bool parse_nmea_gps(char *nmea_string, GPSData *gps_data) {
  printf("Entered Parsing\n ");
  // Validate NMEA checksum
  if (!validate_nmea_checksum(nmea_string)) {
    printf("Invalid NMEA Checksum\n");
    return false;
  }

  printf("NMEA String: %s\n", nmea_string);

  if (strncmp(nmea_string, "$GPRMC", 6) == 0) {
    char *token;
    char *tokens[12] = {0};
    int token_count = 0;

    // Tokenize the string
    token = strtok(nmea_string, ",");
    while (token != NULL && token_count < 12) {
      tokens[token_count++] = token;

      printf("Token %d: %s\n", token_count, token);

      token = strtok(NULL, ",");
    }

    // Check if we have enough tokens and data is valid
    if (token_count >= 12 && strcmp(tokens[2], "A") == 0) {
      // Latitude
      if (strlen(tokens[3]) > 0) {
        convert_nmea_to_decimal(tokens[3], &gps_data->latitude);
        if (tokens[4][0] == 'S')
          gps_data->latitude = -gps_data->latitude;
      }

      // Longitude
      if (strlen(tokens[5]) > 0) {
        convert_nmea_to_decimal(tokens[5], &gps_data->longitude);
        if (tokens[6][0] == 'W')
          gps_data->longitude = -gps_data->longitude;
      }

      gps_data->is_valid = true;
      return true;
    }
  }

  return false;
}

void process_gps_data(GPSData *gps_data) {
  printf("UART Readable: %d\n", uart_is_readable(UART_ID));

  char nmea_buffer[MAX_NMEA_LENGTH];
  int chars_read = 0;

  while (uart_is_readable(UART_ID) && chars_read < MAX_NMEA_LENGTH - 1) {
    // printf("IF 1");

    char c = uart_getc(UART_ID);
    nmea_buffer[chars_read] = c;

    // printf("IF 1.5");
    // printf("%c, %d\n", c, c);

    if ((int)c == 10) {
      printf("IF 2");
      // printf("%c", nmea_buffer[chars_read]);
      nmea_buffer[chars_read + 1] = '\0';

      if (parse_nmea_gps(nmea_buffer, gps_data)) {
        // printf("IF 3");
        // Optional: Add logging or further processing
        printf("Valid GPS Data Received\n");
      }

      chars_read = 0;

      break;
    } else {
      chars_read++;
    }
  }
}
