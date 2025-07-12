# drone_swarm

This project is going to be a fully DIY drone swarm project based around ESP32 connectivity! There will be a master contorller powered by ESP32 that will connect to ESP32 drones over ESPNOW.

# System Function Requirements
- Swarm behavior
    - 3+ drones
    - All drones must be able to follow a certain formation (flock, disperse, follow leader, etc.)
    - No collisions!
- Static
    - Freeze drones in place
- Auto-land in place if battery is low
- Power LED with ability to disable via jumper
- Want to draw out a path on a grid on controller and have the drone follow that path 
- Normal drone control
- Pairing behavior (i.e. select which drone to manually control / set as leader)

# Drone Hardware Requirements
- Drone designed without modules (no ESP32 module!)
    - USB/battery power
        - Recharge without having to ever unplug battery
    - Wireless connectivity (i.e. antenna)
    - IMU
    - Barometer
    - Magnetometer
    - Minimize PCB area for weight reduction
- 3D printed chassis (Onshape)
- Brushless DC motors ?
- Remote control through ESP32 based controller
    - Or do I want to do a web based GUI on the phone?
- Weight must be under 250g

# Controller Hardware Requirements
- ESP32 with antenna
- Touchscreen
- Joysticks
- Buttons
- Large enough to display the data of 4 drones?
- Does not require fast refresh rate
    - The most intensive thing might be a real time (small) model of a drone
    - or maybe a trace


# Firmware Requirements
- PID motor control
- FreeRTOS (no Arduino!)
- Write own drivers
- OTA flashing

# Drone Hardware Component List
- ESP32
- Flash
- RAM?
- Crystal?
- USB-UART
- USB Micro Jack
- DC/DC converter vs LDO
- Motor driver(s)?
- IMU
- Barometer
- Buttons
- Some kind of switch for power ORring (not just diodes?)
    - Disconnect battery when not in use
- ON/OFF switch
- 

# Miscellaenous Requirements
- Keep budget per drone under $50 each?

