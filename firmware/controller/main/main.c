
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

#include "LED.h"

void app_main(void) {
    // configurePWM();
    // startPWM();
    configureBlinky();
    startBlinky();
}