
/*
for the moment, need to build infrastructure for more complicated functionalities of the controller

BASIC CONTROLLER FUNCTIONALITIES TO INCLUDE:
- Have task to poll data from peripheral ESP32
- Have peripheral ESP32 task to read I2C data from IMU and transmit to master ESP32 via ESPNOW
- Have basic PWM control task to gradually turn the onboard LED on and off
- Have task to update the LCD via SPI
*/ 


// TODO
// blinky :D
// PWM blinky
// SPI display
// understand how to RTOS
// understand how to ESPNOW

#include <stdint.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
// #include "freertos/projdefs.h"
// #include "esp_log.h"

#include "led.h"
#include "mpu6050.c"

// pin ESPNOW task to core 1
    // xTaskCreatePinnedToCore()
        // xCoreID = core number (0 or 1)
        // in this case we want core 0 or the PRO CPU



void app_main(void) {
    // configurePWM();
    // startPWM();
    // configureBlinky();
    // startBlinky();

    // uint16_t xAccel = 0;
    // uint16_t yAccel = 0;
    // uint16_t zAccel = 0;
    // printf("X: %d, Y: %d, Z: %d\n", xAccel, yAccel, zAccel);
    
    i2c_master_dev_handle_t MPUHandle = initMPU();
    readAccel(MPUHandle);
    

}