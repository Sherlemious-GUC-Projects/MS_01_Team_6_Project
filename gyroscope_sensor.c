#include "gyroscope_sensor.h"
#include "hardware/i2c.h"
#include "pico/stdlib.h"
#include <stdio.h>

data_t imu_init(void) {
  // Initialize I2C
  i2c_init(i2c0, 400000); // 400 kHz
  gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
  gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
  gpio_pull_up(I2C_SDA);
  gpio_pull_up(I2C_SCL);

  // Configure Accelerometer (ODR 104 Hz, ±2g scale)
  uint8_t config[2] = {CTRL1_XL, 0x40};
  int result = i2c_write_blocking(i2c0, LSM6DSL_ADDR, config, 2, false);
  if (result < 0) {
    printf("Failed to configure accelerometer\n");
  }

  // Configure Gyroscope (ODR 104 Hz, ±250 dps)
  uint8_t gyro_config[2] = {CTRL2_G, 0x40};
  result = i2c_write_blocking(i2c0, LSM6DSL_ADDR, gyro_config, 2, false);
  if (result < 0) {
    printf("Failed to configure gyroscope\n");
  }

  // Check device identification
  uint8_t who_am_i = 0;
  uint8_t reg = WHO_AM_I;
  i2c_write_blocking(i2c0, LSM6DSL_ADDR, &reg, 1, true);
  i2c_read_blocking(i2c0, LSM6DSL_ADDR, &who_am_i, 1, false);

  // init the strucs
  data_t *data = (data_t *)malloc(sizeof(data_t));

  // zero out the vectors
  data->acc = (vector_t *)malloc(sizeof(vector_t));
  data->acc->x = 0;
  data->acc->y = 0;
  data->acc->z = 0;

  data->gyro_vel = (vector_t *)malloc(sizeof(vector_t));
  data->gyro_vel->x = 0;
  data->gyro_vel->y = 0;
  data->gyro_vel->z = 0;

  data->gyro_ang = (vector_t *)malloc(sizeof(vector_t));
  data->gyro_ang->x = 0;
  data->gyro_ang->y = 0;
  data->gyro_ang->z = 0;

  return data;
}

void read_accelerometer(data_t *data) {
  uint8_t buffer[6];

  // Read 6 bytes of accelerometer data
  uint8_t reg = OUTX_L_A;
  i2c_write_blocking(i2c0, LSM6DSL_ADDR, &reg, 1, true);
  i2c_read_blocking(i2c0, LSM6DSL_ADDR, buffer, 6, false);

  // Convert raw data to g
  // For ±2g range, sensitivity is 0.061 mg/LSB
  data->acc->x = ((int16_t)((buffer[1] << 8) | buffer[0])) * 0.061 / 1000.0;
  data->acc->y = ((int16_t)((buffer[3] << 8) | buffer[2])) * 0.061 / 1000.0;
  data->acc->z = ((int16_t)((buffer[5] << 8) | buffer[4])) * 0.061 / 1000.0;
}

void read_gyroscope(data_t *data) {
  uint8_t buffer[6];

  // Read 6 bytes of gyroscope data
  uint8_t reg = OUTX_L_G;
  i2c_write_blocking(i2c0, LSM6DSL_ADDR, &reg, 1, true);
  i2c_read_blocking(i2c0, LSM6DSL_ADDR, buffer, 6, false);

  // Print raw data for debugging
  printf("Raw gyroscope data: %02x %02x %02x %02x %02x %02x\n", buffer[0],
         buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);

  // Convert raw data to dps
  // For ±250 dps range, sensitivity is 8.75 mdps/LSB
  data->gyro_vel->x = ((int16_t)((buffer[1] << 8) | buffer[0])) * 8.75 / 1000.0;
  data->gyro_vel->y = ((int16_t)((buffer[3] << 8) | buffer[2])) * 8.75 / 1000.0;
  data->gyro_vel->z = ((int16_t)((buffer[5] << 8) | buffer[4])) * 8.75 / 1000.0;
}

void get_angular_displacement(absolute_time_t last_time,
                                              data_t *data) {
  read_accelerometer(data);
  read_gyroscope(data);

  absolute_time_t current_time = get_absolute_time();
  float dt = absolute_time_diff_us(last_time, current_time) / 1000000.0f;
  last_time = current_time;

  calculate_angular_displacement(dt);
}

void calculate_angular_displacement(float dt, data_t *data) {
  // integrate the gyro velocity to get the gyro angles
  data->gyro_ang->x += data->gyro_ang->x * dt;
  data->gyro_ang->y += data->gyro_ang->y * dt;
  data->gyro_ang->z += data->gyro_ang->z * dt;
}

void print_sensor_contents() {
  // init the imu
  data_t *data = imu_init();
  /* printf("Acceleration (g): X = %.3f, Y = %.3f, Z = %.3f\r\n", acc.x, acc.y,
   */
  /*        acc.z); */
  /* printf("Gyroscope (dps): X = %.3f, Y = %.3f, Z = %.3f\r\n",
   * gyro_velocity.x, */
  /*        gyro_velocity.y, gyro_velocity.z); */
  /* printf("Angular Displacement (degrees): X = %.3f, Y = %.3f, Z = %.3f\r\n",
   */
  /*        gyro_angles.angle_x, gyro_angles.angle_y, gyro_angles.angle_z); */
}
