### ~~~ MAIN CMAKE FILE ~~~ ###
cmake_minimum_required(VERSION 3.12)

### Name project ###
SET(ProjectName main)

### Import those libraries ###
include(pico_sdk_import.cmake)

### Define project ###
project(${ProjectName})

### Initialize the Raspberry Pi Pico SDK ###
pico_sdk_init()

### Add the executable ###
add_executable(${ProjectName}
    main.c
)

### Include directories ###
target_include_directories(${ProjectName} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

### Link libraries ###
target_link_libraries(${ProjectName} 
    pico_stdlib 
    hardware_pwm
    hardware_i2c
    )

### Enable UF2 generation ###
pico_add_extra_outputs(${ProjectName})
