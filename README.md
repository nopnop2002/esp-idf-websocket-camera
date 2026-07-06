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

<img width="662" height="756" alt="Image" src="https://github.com/user-attachments/assets/0ea75536-a679-4e52-ab4b-7dbce678bd19" />

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
ESP-IDF V5.0 or later.   
ESP-IDF V4.4 release branch reached EOL in July 2024.   

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
<img width="659" height="486" alt="Image" src="https://github.com/user-attachments/assets/0a36ad6c-39e1-4445-9532-7c28a1cf2b62" />
<img width="659" height="486" alt="Image" src="https://github.com/user-attachments/assets/bb9cad98-8bd5-456f-be80-7451fd8f5def" />

## Wifi Setting
Set the information of your access point.   
![config-wifi-1](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/4c23bb09-8d84-4c40-8bda-648ddc5c810f)

You can connect using the mDNS hostname instead of the IP address.   
![config-wifi-2](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/faa17c9c-548b-4c81-8202-da74d9772bc8)

You can use static IP.   
![config-wifi-3](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/c44f1e38-99ec-4de9-9792-a56314700021)

## Select Board
![config-board](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/3f3f4d61-7baf-4672-8dd1-2ebb8dcedf38)

## Select Frame Size
Large frame sizes take longer to take a picture.   
<img width="659" height="486" alt="Image" src="https://github.com/user-attachments/assets/c263d0e9-3362-4fe8-a743-c6e6fc914058" />

## Flash Light
ESP32-CAM by AI-Thinker has a flash light on GPIO4.   
![config-light](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/3acabf5a-2c4d-4855-9799-4a17257388fd)

## PSRAM
When you use ESP32S3-WROVER CAM, you need to set the PSRAM type.   

![config-psram](https://github.com/nopnop2002/esp-idf-websocket-camera/assets/6020549/ba04f088-c628-46ac-bc5b-2968032753e0)

# Take pictures using Browser
ESP32 acts as a WebSocket server.   
Enter the following in the address bar of your web browser.   
```
http:://{IP of ESP32}/
or
http://esp32-server.local/
```
<img width="662" height="756" alt="Image" src="https://github.com/user-attachments/assets/e7e3cddb-be9e-4d10-8abb-3191eed8fe4f" />
<img width="662" height="756" alt="Image" src="https://github.com/user-attachments/assets/e16e5e01-a929-48e7-904b-2de13fb3c96c" />

Push take picture button.   
<img width="662" height="756" alt="Image" src="https://github.com/user-attachments/assets/c57f2b95-df34-4dff-a162-5fc41a52fb63" />
<img width="826" height="878" alt="Image" src="https://github.com/user-attachments/assets/aa96b9eb-54ca-44a7-8ae4-5d6e3fa2173b" />
