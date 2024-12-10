#include "hardware/uart.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/sensors/gps.h"

void send_gps_command(const char *cmd)
{
  uart_puts(UART_ID, cmd);
  sleep_ms(100); // Wait for command to process
}

void uart_gps_init()
{
  // Initialize UART with more robust configuration
  uart_init(UART_ID, BAUD_RATE);

  // gpio_set_function(UART_TX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_TX_PIN));
  // gpio_set_function(UART_RX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_RX_PIN));

  gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
  gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

  sleep_ms(1000);
  send_gps_command("$PMTK220,1000*1F\r\n"); 

  uart_set_hw_flow(UART_ID, false, false);
  uart_set_format(UART_ID, 8, 1, UART_PARITY_NONE);
  // uart_set_irq_enables(UART_ID, true, false);
  uart_set_fifo_enabled(UART_ID, true);
}

bool validate_nmea_checksum(char *nmea_string)
{
  int len = strlen(nmea_string);
  printf("Checksum Validation - String Length: %d\n", len);
  printf("Full NMEA String: %s", nmea_string);

  if (len < 7)
  {
    printf("Invalid: Too short (< 7 chars)\n");
    return false;
  }

  char *checksum_ptr = strchr(nmea_string, '*');
  if (!checksum_ptr)
  {
    printf("Invalid: No checksum marker (*) found\n");
    return false;
  }

  uint8_t calculated_checksum = 0;
  for (char *p = nmea_string + 1; p < checksum_ptr; p++)
  {
    calculated_checksum ^= *p;
  }

  char hex_checksum[3];
  snprintf(hex_checksum, sizeof(hex_checksum), "%02X", calculated_checksum);

  printf("Calculated Checksum: %s\n", hex_checksum);
  printf("Received Checksum: %s\n", checksum_ptr + 1);

  bool is_valid = strncmp(hex_checksum, checksum_ptr + 1, 2) == 0;
  printf("Checksum Validation: %s\n", is_valid ? "VALID" : "INVALID");

  return is_valid;
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

  // printf("Entered Parsing\n ");
  // Validate NMEA checksum
  if (!validate_nmea_checksum(nmea_string))
  {
    printf("Invalid NMEA Checksum\n");
    return false;
  }

  // printf("NMEA String: %s\n", nmea_string);

  if (strncmp(nmea_string, "$GPRMC", 6) == 0)
  {
    char *token;
    char *tokens[12] = {0};
    int token_count = 0;

    // Tokenize the string
    token = strtok(nmea_string, ",");
    while (token != NULL && token_count < 12)
    {
      tokens[token_count++] = token;

      // printf("Token %d: %s\n", token_count, token);

      token = strtok(NULL, ",");
    }

    // Check if we have enough tokens and data is valid
    if (token_count >= 12 && strcmp(tokens[2], "A") == 0)
    {
      // Latitude
      if (strlen(tokens[3]) > 0)
      {
        convert_nmea_to_decimal(tokens[3], &gps_data->latitude);
        if (tokens[4][0] == 'S')
          gps_data->latitude = -gps_data->latitude;
      }

      // Longitude
      if (strlen(tokens[5]) > 0)
      {
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

void process_gps_data(GPSData *gps_data)
{
  bool found_gprmc = false;

  char *temp_sentence = (char *)calloc(MAX_NMEA_LENGTH, sizeof(char));

  int temp_index = 0;

  while (uart_is_readable(UART_ID) && !found_gprmc)
  {
    char c = uart_getc(UART_ID);
    printf(CYAN "%c", c);

    if (c == '\n')
    {
      temp_sentence[temp_index] = '\0';
      if (strncmp(temp_sentence, "$GPRMC", 6) == 0)
      {
        found_gprmc = true;
        printf(YELLOW "\nGPRMC sentence detected during reading: %s\n", temp_sentence);
      }

      temp_index = 0;
    }
    else if (temp_index < MAX_NMEA_LENGTH - 1)
    {
      temp_sentence[temp_index++] = c;
    }
  }
}
