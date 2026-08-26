#include "driver/i2c_master.h"

i2c_master_bus_handle_t initI2C();
i2c_master_dev_handle_t addI2CDevice(int deviceAddy, int SCLfreq, i2c_master_bus_handle_t bus_handle);
