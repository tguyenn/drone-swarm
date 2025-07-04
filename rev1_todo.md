# Revision 1 Targets


## Drone
- Drone designed without modules (no ESP32 module!)
    - USB/battery power
        - Recharge without having to ever unplug battery?
    - Wireless connectivity (i.e. antenna)
    - IMU
    - Barometer
    - Magnetometer
    - Minimize PCB area for weight reduction
- 3D printed chassis (Onshape)
- Brushless DC motors
- Remote control through ESP32 based controller
- Touchscreen controller for telemetry

- PID motor control
- FreeRTOS (no Arduino!)
- Self made drivers

## Controller
- 2 layer board
- Capacitive touch screen
- 2 joysticks
- 4 buttons
- ESP32 wireless connectivity
- Reset button
- Boot button
- Power led
- Multicolor Runtime led
- External flash for graphics?
- USBC / LiPo battery charging and power
    - Physical board switch
- Support two operational modes:
    - Determine by switch position
    - On (drone control software config and control)
    - Off (allow battery to be charged) 
- Shitty speaker with DMA capability
- Gyroscope