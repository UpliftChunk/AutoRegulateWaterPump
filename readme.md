# Automatic Regulation of Water Based on Soil Moisture and Temperature

## Overview
This project aims to optimize water usage in agricultural fields using machine learning and IoT technologies. The system, built with an ESP32 microcontroller, soil moisture, and temperature sensors, automates water regulation based on real-time data.

## System Components
- **ESP32 WROOM Microcontroller**: Connects to soil moisture and temperature sensors.
- **Capacitive Soil Moisture Sensor**: Monitors soil moisture levels.
- **Temperature Sensor (DHT11/DHT22)**: Measures ambient temperature.
- **MOSFET (IRFZ44 N channel) & Relay**: Control irrigation hardware.

## Features
Automated water regulation using machine learning.
- **Data Collection**: The ESP32 collects data from the sensors and sends it to a server.
- **Machine Learning Models**:
  - Linear Regression: Determines the amount of water needed.
  - Multi-Linear Regression: Predicts when soil moisture will drop below a threshold.

Real-time data processing.
- Water Regulation: Based on predictions, the ESP32 activates irrigation hardware.

## Usage
1. Install the sensors and ESP32 as per the circuit design.
2. Connect the ESP32 to the Wi-Fi network.

[![Circuit.png](https://i.postimg.cc/pL5cwx34/Circuit.png)](https://postimg.cc/K1F5LXGD)

# Setup proccess in ESP32 micro controller 

build and upload firmware/sketch to an ESP32 using PlatformIO.

## Prerequisites

- Python (latest version)
- [PlatformIO Core (CLI)](https://platformio.org/install)
- ESP32 Hardware

### 1. Locate to this working Repository
```
cd AutoRegulateWaterPump/esp32_Arduino_IDE
```

### 2. Install Python Dependencies
```
pip install -r requirements.txt
```

### 3. Build the Project
```
platformio run
```

### 4. Upload Sketch/Firmware to ESP32
```
platformio run --target upload
```
if you this does not work, manually specify the port at which your esp32 is connected with the following command: `platformio run --target upload --upload-port COM8`
`# Replace with your port`
more info to find your com: https://www.taltech.com/support/identify-com-port/

### 5. Monitor Serial Output
```
platformio device monitor
```
# Setup Server
## Prerequisites

Make sure you have the following installed:

- Python (version 3.6 or higher)
- Jupyter Notebook


### 1. Locate to this working Repository
   ```
   cd AutoRegulateWaterPump/server
   ```

### 2. Install Python Dependencies
```
pip install -r requirements.txt
```

### 3. Start the Jupyter Notebook Server:
```
jupyter notebook
```

### 4. Locate file and run ipynb
- Access the Notebook: Open your web browser and go to the URL provided in the terminal (usually http://localhost:8888).
- Locate and click on the Server.ipynb file in the Jupyter interface to open it. Click cell>Run All to run the server 

