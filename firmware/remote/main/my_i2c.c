
// implement i2c driver

// must be able to instantiate an i2c connection with a specified
    // pin
    // frequency
    // slave address
    // 
    
// refer to page 33 of https://product.tdk.com/system/files/dam/doc/product/sensor/mortion-inertial/imu/data_sheet/mpu-6000-datasheet1.pdf
#include "my_i2c.h"

#define I2C_MASTER_SCL_IO 22   
#define I2C_MASTER_SDA_IO 21

i2c_master_bus_handle_t initI2C() {
    i2c_master_bus_handle_t bus_handle;
    i2c_master_bus_config_t i2c_mst_config = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .i2c_port = 0,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };

    i2c_new_master_bus(&i2c_mst_config, &bus_handle);
    return bus_handle;
}

i2c_master_dev_handle_t addI2CDevice(int deviceAddy, int SCLfreq, i2c_master_bus_handle_t bus_handle) {
    i2c_master_dev_handle_t dev_handle;
    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = deviceAddy,
        .scl_speed_hz = SCLfreq,
    };
    i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle);

    // vTaskDelay(100);

    // ESP_ERROR_CHECK(i2c_master_probe(bus_handle, deviceAddy, -1));// verify connection

    return dev_handle;

    // TODO add error checking if there are no more I2C bus slots remaining
    // if fail (i.e. esperror or something), then print message or esplog
}    
