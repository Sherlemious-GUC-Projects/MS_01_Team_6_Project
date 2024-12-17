### ~~~ MAIN CMAKE FILE ~~~ ###
cmake_minimum_required(VERSION 3.12)

### Name project ###
SET(ProjectName main)

### Set any variables required for importing libraries ###
# Set name of project (as PROJECT_NAME) and C/C   standards
project(uber_car C CXX ASM)
set(PICO_BOARD pico_w)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/FreeRTOS-Kernel)

### Import those libraries ###
include(pico_sdk_import.cmake)
include(${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

### Define project ###
project(${ProjectName})

### Initialize the Raspberry Pi Pico SDK ###
pico_sdk_init()

# Tell CMake where to find the executable source file
add_executable(${PROJECT_NAME} 
    main.c
    src/wifi.c
    src/sensors/gyroscope.c
    src/sensors/gps.c
    src/actuators/motor.c
    src/actuators/servo.c
    lib/cJson.c
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(${PROJECT_NAME} 
    pico_cyw43_arch_lwip_threadsafe_background
    pico_lwip_http
    hardware_i2c
    hardware_uart
    hardware_pwm
    pico_stdlib
)

### Include directories ###
target_include_directories(${ProjectName} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ./lib
)

### Link libraries ###
target_link_libraries(${ProjectName}
    pico_stdlib 
    hardware_pwm
    hardware_i2c
    FreeRTOS-Kernel-Heap4 
)

### Enable UF2 generation ###
pico_add_extra_outputs(${ProjectName})
