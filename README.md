# Uber Smart Car Navigation System

![Smart Car System](https://img.shields.io/badge/Smart%20Car-Navigation-blue)
![Raspberry Pi Pico W](https://img.shields.io/badge/Raspberry%20Pi-Pico%20W-c51a4a)
![React](https://img.shields.io/badge/Frontend-React-61DAFB)

A complete navigation and control system for small-scale smart cars using a Raspberry Pi Pico W microcontroller and a React web application interface. This project enables precise GPS-based navigation, real-time tracking, and remote control via WiFi.

## 📌 System Overview

This system consists of two main components:

1. **Hardware (Pico W)**: A microcontroller setup running embedded C code to control motors, read sensors, and communicate wirelessly
2. **Web Application**: A React-based dashboard for tracking and controlling the car with an interactive map interface

The system enables a small car to navigate autonomously between GPS coordinates with accurate rotation calculations and real-time position updates.

## 🛠️ Hardware Setup

### Components Required
- Raspberry Pi Pico W microcontroller
- Servo motor (for steering)
- DC motors (2x) for drive
- Motor driver board
- GPS module (NEO-6M)
- Gyroscope/IMU (LSM6DSL)
- Battery pack
- Car chassis

### Pin Connections

#### LED
- Internal GPIO 6

#### Servo Motor
- Connect red wire to 3.3V
- Connect brown wire to GND
- Connect orange wire to D3 (GPIO 15)

#### DC Motors
- Motor 1:
  - PWM Pin: GPIO 16
  - Direction Pin 1: GPIO 19
  - Direction Pin 2: GPIO 18
- Motor 2:
  - PWM Pin: GPIO 13
  - Direction Pin 1: GPIO 11
  - Direction Pin 2: GPIO 12

#### GPS Module
- UART RX: GPIO 5
- UART TX: GPIO 4

#### Gyroscope/IMU
- I2C SDA: GPIO 12
- I2C SCL: GPIO 13

## 💻 Software Components

### 1. Pico W Firmware
The microcontroller runs C code with FreeRTOS for concurrent task management:
- Navigation calculations (bearing, distance, rotation)
- Motor control
- GPS and IMU data processing
- WiFi server for communication

### 2. Web Application
A modern React application with:
- Interactive Google Maps integration
- Real-time car position tracking
- Destination selection via map clicks
- Compass integration (on supported devices)
- Dark/light mode theme support

## 🚀 Getting Started

### Setting Up the Pico W

1. Install the Pico SDK:
```bash
git clone https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init
export PICO_SDK_PATH=`pwd`
```

2. Clone the repository and build the firmware:
```bash
git clone https://github.com/yourusername/uber-smart-car.git
cd uber-smart-car
mkdir build && cd build
cmake ..
make
```

3. Connect the Pico W to your computer while holding the BOOTSEL button
4. Copy the `uber_car.uf2` file to the mounted RPI-RP2 drive

### Setting Up the Web Application

1. Navigate to the web app directory:
```bash
cd uber-car-webapp
```

2. Install dependencies:
```bash
npm install
```

3. Create a `.env` file with your Google Maps API key:
```
VITE_GOOGLE_MAPS_API_KEY=your_google_maps_api_key
```

4. Start the development server:
```bash
npm run dev
```

## 📡 How It Works

### Car Navigation
1. The web app sends destination coordinates to the Pico W via HTTP
2. The car calculates:
   - Distance to destination
   - Bearing angle
   - Required rotation
   - Estimated time to reach destination
3. The car executes:
   - Initial rotation to face destination
   - Forward movement for calculated time
   - Continuous adjustments based on gyroscope data

### Communication Protocol
The Pico W hosts a simple HTTP server that accepts JSON payloads with:
- Current location (latitude, longitude)
- Destination (latitude, longitude)
- Heading (compass direction)

The server responds with a confirmation message once the navigation command is processed.

## 🔮 Future Improvements

- Obstacle avoidance using ultrasonic sensors
- Path planning with waypoints
- Battery level monitoring
- Enhanced error handling
- Real-time position updates
- Multi-car tracking on the same interface

## 📚 Technical Details

### Navigation Algorithm
The system uses Euclidean distance calculations to determine the straight-line path between points and calculates bearing using trigonometric functions. The car rotation is managed through differential drive control of the motors.

### Constants and Parameters
- `METERS_PER_DEGREE_LAT`: 111320.0 (approximate meters per degree latitude)
- `APPROX_AVG_SPEED`: 1.1498 (meters per second)
- `APPROX_AVG_ANGULAR_SPEED`: 234.0 (degrees per second)

## 📝 License

This project is open-source and available under the MIT License.

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the issues page for open tasks or submit your own ideas.

## 🙏 Acknowledgments

- Raspberry Pi Foundation for the Pico W
- Google Maps Platform for location services
- All contributors who helped build this system
