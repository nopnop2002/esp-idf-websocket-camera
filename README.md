# esp-idf-websocket-camera
Take a picture and Publish it via WebSocket.   
This project use [ESP32 Camera Driver](https://components.espressif.com/components/espressif/esp32-camera).   

ESP32 works as a WebSocket server.   
Use your browser as a WebSocket client.   
```
+----------+               +----------+               +----------+
|          |               |          |<-----Get------|          |
|  Camera  |<---Capture--->|  ESP32   |               |  Browser |
|          |               |          |----Picture--->|          |
+----------+               +----------+               +----------+
```

![browser-3](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/7fbca7e9-bc30-40b4-9ad2-5091ed6c88fd)

# Hardware requirements
ESP32 development board with OV2640 camera.   
If you use other camera, edit sdkconfig.default.   
From the left:   
- Aithinker ESP32-CAM   
- Freenove ESP32-WROVER CAM   
- UICPAL ESPS3 CAM   
- Freenove ESP32S3-WROVER CAM (Clone)   

![es32-camera](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/38dbef9a-ed85-4df2-8d22-499b2b497278)


# Software requirements
esp-idf v4.4/v5.X.   

# Installation
For AiThinker ESP32-CAM, You have to use a USB-TTL converter.   

|ESP-32|USB-TTL|
|:-:|:-:|
|U0TXD|RXD|
|U0RXD|TXD|
|GPIO0|GND|
|5V|5V|
|GND|GND|


```
git clone https://github.com/nopnop2002/esp-idf-websocket-camera
cd esp-idf-websocket-camera
idf.py set-target {esp32/esp32s3}
idf.py menuconfig
idf.py flash monitor
```

# Start firmware
For AiThinker ESP32-CAM, Change GPIO0 to open and press the RESET button.

# Configuration
Set the following items using menuconfig.

![config-top](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/20901930-dfc9-45e2-86bf-674ee352214c)
![config-app](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/5e6a4cf8-ac2c-47a5-a2c0-59dc42a15fde)

## Wifi Setting

![config-wifi-1](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/4c23bb09-8d84-4c40-8bda-648ddc5c810f)

You can connect using the mDNS hostname instead of the IP address.   
![config-wifi-2](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/faa17c9c-548b-4c81-8202-da74d9772bc8)

You can use static IP.   
![config-wifi-3](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/c44f1e38-99ec-4de9-9792-a56314700021)

## Using mDNS hostname
You can connect using the mDNS hostname instead of the IP address.   
- esp-idf V4.4  
 If you set CONFIG_MDNS_STRICT_MODE = y in sdkconfig.defaults, the firmware will be built with MDNS_STRICT_MODE.   
 __If MDNS_STRICT_MODE is not set, mDNS name resolution will not be possible after long-term operation.__   
- esp-idf V4.4.1   
 mDNS component has been updated.   
 If you set CONFIG_MDNS_STRICT_MODE = y in sdkconfig.defaults, the firmware will be built with MDNS_STRICT_MODE.   
 __Even if MDNS_STRICT_MODE is set, mDNS name resolution will not be possible after long-term operation.__   
- esp-idf V5.0 or later   
 mDNS component has been updated.   
 Long-term operation is possible without setting MDNS_STRICT_MODE.   
 The following lines in sdkconfig.defaults should be removed before menuconfig.   
 ```CONFIG_MDNS_STRICT_MODE=y```

## Select Board
![config-board](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/3f3f4d61-7baf-4672-8dd1-2ebb8dcedf38)



## Flash Light   
ESP32-CAM by AI-Thinker has a flash light on GPIO4.

![config-light](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/3acabf5a-2c4d-4855-9799-4a17257388fd)

## PSRAM   
When you use ESP32S3-WROVER CAM, you need to set the PSRAM type.   

![config-psram](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/ba04f088-c628-46ac-bc5b-2968032753e0)

# Take pictures using Browser
ESP32 acts as a WebSocket server.   
Open index.html included in this project.   
Push connect server button.   
![browser-1](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/2e73c585-a1d4-42a2-a158-38cf424169f9)

Push take picture button.   
![browser-2](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/ec4e671f-3cd0-4bcc-a4aa-184fe669d238)

![browser-3](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/7fbca7e9-bc30-40b4-9ad2-5091ed6c88fd)


