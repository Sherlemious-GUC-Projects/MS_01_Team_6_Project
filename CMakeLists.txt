### ~~~ MAIN CMAKE FILE ~~~ ###
cmake_minimum_required(VERSION 3.12)

### Name project ###
SET(ProjectName main)

### Set any variables required for importing libraries ###
SET(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/FreeRTOS-Kernel)

### Import those libraries ###
include(pico_sdk_import.cmake)
include(${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

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
    FreeRTOS-Kernel-Heap4 
    )

### Enable UF2 generation ###
pico_add_extra_outputs(${ProjectName})
