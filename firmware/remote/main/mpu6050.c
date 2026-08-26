// provide i2c driver abstraction layer to continuously stream acceleromter data values to ESP32
#include "mpu6050.h"


// 1101000 = 0x68
#define MPU_ADDY 0x68
#define SCL_FREQ 100000
#define DATA_BUF_LEN 16
i2c_master_dev_handle_t initMPU() {
    i2c_master_bus_handle_t busHandle = initI2C();
    i2c_master_dev_handle_t devHandle = addI2CDevice(MPU_ADDY, SCL_FREQ, busHandle); // mpu addy: 1101000 = 0x68
    return devHandle;
}

uint16_t getData(i2c_master_dev_handle_t devHandle) {
    uint8_t data[DATA_BUF_LEN];
    
    i2c_master_receive(devHandle, data, DATA_BUF_LEN, -1);
    
    printf("new data buffer: ");
    for(int i = 0; i < DATA_BUF_LEN; i++) {
        printf("%d, ", data[i]);
    }
    printf("\n");

    return 1; // TODO fix this lol

}

void readAccel(i2c_master_dev_handle_t devHandle) {
    i2c_master_bus_handle_t busHandle;
    i2c_master_get_bus_handle(0, &busHandle);
    int registers[] = {0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40};
    // accelerometer registers 0x3B - 0x40
    // x high
    // x low
    // ...
    getData(devHandle);
    // int xHigh 
    // int xLow
    // read high
    // read low
    // (high << 8) | (low)
    // store into variable

    printf("lol\n");
}