
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
#include "freertos/projdefs.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
// #include "esp_log.h"
#include "hal/gpio_types.h"
#include "soc/gpio_num.h"

#define ONBOARD_LED 2

void configureBlinky(void) {
	gpio_reset_pin(ONBOARD_LED);
	gpio_set_direction(ONBOARD_LED, GPIO_MODE_OUTPUT);
}

void blinkyTask(void* arg) {
	while (1) {
			gpio_set_level(ONBOARD_LED, 1);
			vTaskDelay(pdMS_TO_TICKS(500)); 
			gpio_set_level(ONBOARD_LED, 0); 
			vTaskDelay(pdMS_TO_TICKS(500)); 	
	}
}

static void configurePWM(void) {

    ledc_timer_config_t ledTimerConf = {
        .speed_mode       = LEDC_LOW_SPEED_MODE,
        .duty_resolution  = LEDC_TIMER_13_BIT,
        .timer_num        = LEDC_TIMER_0,
        .freq_hz          = (4000),  // Set output frequency at 4 kHz
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_channel_config_t ledChanConf = {
        .speed_mode     = LEDC_LOW_SPEED_MODE,
        .channel        = LEDC_CHANNEL_0,
        .timer_sel      = LEDC_TIMER_0,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = (2),
        .duty           = 4096,
        .hpoint         = 0
    };

    ledc_timer_config(&ledTimerConf);
    ledc_channel_config(&ledChanConf);
    ledc_fade_func_install(0);
}

void blinkyPWMTask(void* arg) {
    int duty = 0;
	while (1) {
        vTaskDelay(1);
        duty++;
        if(duty > 8191) duty = 0;
        ledc_set_duty_and_update(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty, 0);
    }
}

void startPWM() {
    xTaskCreate(
		blinkyPWMTask,                 // Task Function
		"PWM",    // Task name (for debugging)
		2048, 			// Stack size (in words)
		NULL,                  // Task input args
		1,                    // Prioritity
		NULL                 // Task Handle
	);
}

void startBlinky() {
    xTaskCreate(
		blinkyTask,                 // Task Function
		"Blinky",    // Task name (for debugging)
		2048, 			// Stack size (in words)
		NULL,                  // Task input args
		1,                    // Prioritity
		NULL                 // Task Handle
	);
}

void app_main(void) {
    configurePWM();
    startPWM();
    // configureBlinky();
    // startBlinky();
}