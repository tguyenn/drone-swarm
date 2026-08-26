#include "led.h"
#define ONBOARD_LED 2

void configureBlinky(void) {
	gpio_reset_pin(ONBOARD_LED);
	gpio_set_direction(ONBOARD_LED, GPIO_MODE_OUTPUT);
}

void configurePWM(void) {

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

void blinkyTask(void *args) {
	while (1) {
			gpio_set_level(ONBOARD_LED, 1);
			vTaskDelay(pdMS_TO_TICKS(500)); 
			gpio_set_level(ONBOARD_LED, 0); 
			vTaskDelay(pdMS_TO_TICKS(500)); 	
	}
}

void blinkyPWMTask(void *args) {
    int duty = 0;
	while (1) {
        vTaskDelay(1);
        duty++;
        if(duty > 8191) duty = 0;
        ledc_set_duty_and_update(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty, 0);
    }
}

void startPWM(void) {
    xTaskCreate(
		blinkyPWMTask,                 // Task Function
		"Blinky PWM",    // Task name (for debugging)
		2048, 			// Stack size (in words)
		NULL,                  // Task input args
		1,                    // Prioritity
		NULL                 // Task Handle
	);
}

void startBlinky(void) {
    xTaskCreate(
		blinkyTask,                 // Task Function
		"Blinky",    // Task name (for debugging)
		2048, 			// Stack size (in words)
		NULL,                  // Task input args
		1,                    // Prioritity
		NULL                 // Task Handle
	);
}