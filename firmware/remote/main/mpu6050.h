
#include <stdio.h>
#include "my_i2c.h"

i2c_master_dev_handle_t initMPU();
uint16_t getData(i2c_master_dev_handle_t devHandle);
void readAccel(i2c_master_dev_handle_t devHandle);
