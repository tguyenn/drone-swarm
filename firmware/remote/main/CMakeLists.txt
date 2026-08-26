set(srcs "main.c"
         "led.c"
         "mpu6050.c"
         "my_i2c.c")
idf_component_register(SRCS ${srcs}
                    INCLUDE_DIRS "."
                    REQUIRES driver
                    REQUIRES esp_driver_ledc
                    PRIV_REQUIRES console esp_timer)
