#include "motorTest.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"


void motor_init(){
    
    gpio_init(MOTOR1_DIR_PIN1);
    gpio_init(MOTOR1_DIR_PIN2);
    gpio_set_dir(MOTOR1_DIR_PIN1, GPIO_OUT);
    gpio_set_dir(MOTOR1_DIR_PIN2, GPIO_OUT);

    gpio_set_function(MOTOR1_PWM_PIN, GPIO_FUNC_PWM);

    uint slice_num = pwm_gpio_to_slice_num(MOTOR1_PWM_PIN);

    pwm_set_wrap(slice_num, 255);  //8-bit resolution
    pwm_set_clkdiv(slice_num, 4.0f); //set clock divider to 4
    pwm_set_gpio_level(MOTOR1_PWM_PIN, 0); // Set PWM to 0% duty cycle

    pwm_set_enabled(slice_num, true);
}

void motor_control(uint16_t speed, bool direction){
    if (speed > 255){
        speed = 255;
    }
    
    if (direction){
        gpio_put(MOTOR1_DIR_PIN1, 1);
        gpio_put(MOTOR1_DIR_PIN2, 0);
    } else {
        gpio_put(MOTOR1_DIR_PIN1, 0);
        gpio_put(MOTOR1_DIR_PIN2, 1);
    }
    pwm_set_gpio_level(MOTOR1_PWM_PIN, speed);
}

