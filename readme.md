# Setup ESP32

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

### 4. 5. Monitor Serial Output
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

