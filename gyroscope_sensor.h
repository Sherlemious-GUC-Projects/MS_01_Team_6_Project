#ifndef GYROSCOPE_H
#define GYROSCOPE_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

// LSM6DSL I2C Address
#define LSM6DSL_ADDR 0x6A

// LSM6DSL Register Addresses
#define CTRL1_XL 0x10 // Accelerometer control register
#define CTRL2_G 0x11  // Gyroscope control register
#define WHO_AM_I 0x0F // Device identification register

#define OUTX_L_A 0x28 // Accelerometer X-axis low byte
#define OUTX_H_A 0x29 // Accelerometer X-axis high byte
#define OUTY_L_A 0x2A // Accelerometer Y-axis low byte
#define OUTY_H_A 0x2B // Accelerometer Y-axis high byte
#define OUTZ_L_A 0x2C // Accelerometer Z-axis low byte
#define OUTZ_H_A 0x2D // Accelerometer Z-axis high byte

#define OUTX_L_G 0x22 // Gyroscope X-axis low byte
#define OUTX_H_G 0x23 // Gyroscope X-axis high byte
#define OUTY_L_G 0x24 // Gyroscope Y-axis low byte
#define OUTY_H_G 0x25 // Gyroscope Y-axis high byte
#define OUTZ_L_G 0x26 // Gyroscope Z-axis low byte
#define OUTZ_H_G 0x27 // Gyroscope Z-axis high byte

// I2C Pins for Nano RP2040
#define I2C_SDA 12 // A4/D18
#define I2C_SCL 13 // A5/D19

typedef struct gyro_angles_t
{
    float angle_x;
    float angle_y;
    float angle_z;
} gyro_angles_t;

typedef struct acc_t
{
    float x;
    float y;
    float z;
} acc_t;

typedef struct gyro_velocity_t
{
    float x;
    float y;
    float z;
} gyro_velocity_t;

void imu_init();
void read_accelerometer();
void read_gyroscope();
struct gyro_angles_t get_angular_displacement(absolute_time_t last_time);
struct gyro_angles_t calculate_angular_displacement(float dt);
void print_sensor_contents();

#endif