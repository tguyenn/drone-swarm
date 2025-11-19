set(srcs "main.c"
    "lol.c")
idf_component_register(SRCS ${srcs}
                    INCLUDE_DIRS "."
                    REQUIRES driver
                    REQUIRES esp_driver_ledc
                    PRIV_REQUIRES console esp_timer)
