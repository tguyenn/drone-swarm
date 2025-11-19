#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "hal/gpio_types.h"
#include "soc/gpio_num.h"

#include "driver/gpio.h"
#include "driver/ledc.h"

void configureBlinky(void);
void configurePWM(void);

void blinkyPWMTask(void*);
void blinkyTask(void*);

void startPWM(void);
void startBlinky(void);