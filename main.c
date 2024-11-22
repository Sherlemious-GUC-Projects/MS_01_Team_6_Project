#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <stdio.h>

#include "hardware/uart.h"
#include <string.h>
#include <stdlib.h>

#define BAUD_RATE 9600
#define UART_TX_PIN 0 // D12
#define UART_RX_PIN 1 // D10
#define MAX_NMEA_LENGTH 256
#define UART_ID uart0

typedef struct
{
  float latitude;  // Latitude in decimal degrees
  float longitude; // Longitude in decimal degrees
  bool is_valid;   // Whether GPS data is valid
} GPSData;

void uart_gps_init()
{
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

void send_gps_command(const char *command)
{
  uart_puts(UART_ID, command);
  uart_puts(UART_ID, "\r\n");
}

void configure_gps()
{
  // Enable $GPGGA (Global Positioning System Fix Data)
  send_gps_command("$PUBX,40,GGA,1,1,1,1,1,1*1D");
  sleep_ms(250);

  // Enable $GPRMC (Recommended Minimum Specific GPS/Transit Data)
  send_gps_command("$PUBX,40,RMC,1,1,1,1,1,1*1D");
  sleep_ms(250);
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

  printf("UART Readable: %d\n", uart_is_readable(UART_ID));

  char nmea_buffer[MAX_NMEA_LENGTH];
  int chars_read = 0;

  while (uart_is_readable(UART_ID) && chars_read < MAX_NMEA_LENGTH - 1)
  {
    // printf("IF 1");

    char c = uart_getc(UART_ID);
    nmea_buffer[chars_read] = c;

    // printf("IF 1.5");
    printf("%c, %d\n", c, c);

    if ((int)c == 10)
    {
      // printf("%c", nmea_buffer[chars_read]);
      nmea_buffer[chars_read + 1] = '\0';

      if (parse_nmea_gps(nmea_buffer, gps_data))
      {
        // printf("IF 3");
        // Optional: Add logging or further processing
        printf("Valid GPS Data Received\n");
      }

      chars_read = 0;
      break;
    }
    else
    {
      chars_read++;
    }
  }
}

int main()
{
  const uint led_pin = 6;
  // Initialize GPIO pin 15 for PWM
  gpio_set_function(SERVO_PWM_PIN, GPIO_FUNC_PWM);

  // Initialize chosen serial port
  stdio_init_all();
  sleep_ms(500);

  // Initialize LED pin
  gpio_init(led_pin);
  gpio_set_dir(led_pin, GPIO_OUT);

  // Initialize IMU
  uart_gps_init();
  sleep_ms(7 * 60 * 1000);
  configure_gps();

  GPSData gps_data = {0};
  int readings = 0;

  // Loop forever
  while (true)
  {
    printf("READING\n %d", readings++);
    process_gps_data(&gps_data);

    if (gps_data.is_valid)
    {
      printf("GPS Location:\n");
      printf("Latitude: %.6f\n", gps_data.latitude);
      printf("Longitude: %.6f\n", gps_data.longitude);
      gps_data.is_valid = false;
    }

    printf("*******************************************************************\n");
    sleep_ms(30 * 1000);
  }

  return 0;
}

int motor_main() {
  // Initialize the motor driver
  motor_init();

  // infinite loop
  while (true) {
    // Set the motor speed to 50% and direction to forward
    motor_control(127, true);
    sleep_ms(2000); // Wait for 2 seconds

    // Set the motor speed to 50% and direction to reverse
    motor_control(127, false);
    sleep_ms(2000); // Wait for 2 seconds

    // Set the motor to MAX speed and direction to forward
    motor_control(255, true);
  }
  return 0;
}

int main() {
  motor_main();
  return 0;
}
