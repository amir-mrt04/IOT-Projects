
# Sensing Temperature and Humidity on the Local Network

This project focuses on sensing temperature and humidity using a DHT11 sensor and a NodeMCU microcontroller in a local network. The collected data is then displayed using the Processing software, providing a real-time visualization of environmental conditions.

## Overview

In this project, we use a DHT11 sensor to measure temperature and humidity, and a NodeMCU microcontroller to transmit the data over a local network. The data is then visualized using the Processing software, allowing users to monitor environmental conditions in real-time.

### Project Objectives

- To learn about IoT sensors and their integration with microcontrollers.
- To develop a system for monitoring temperature and humidity over a local network.
- To visualize the collected data using Processing software.

## Hardware and Software Requirements

### Hardware

- **NodeMCU (ESP8266)**: A microcontroller used to interface with the DHT11 sensor and transmit data over the network.
- **DHT11 Sensor**: A sensor used for measuring temperature and humidity.
- **Breadboard and Jumper Wires**: For making connections between the NodeMCU and the DHT11 sensor.
- **USB Cable**: To connect the NodeMCU to the computer for programming and power.

### Software

- **Arduino IDE**: For programming the NodeMCU microcontroller.
- **Processing**: A software used to visualize the temperature and humidity data.

## Installation and Setup

### Step 1: Setting up the Hardware

1. **Connect the DHT11 Sensor to NodeMCU**:
   - Connect the VCC pin of the DHT11 sensor to the 3.3V pin of the NodeMCU.
   - Connect the GND pin of the DHT11 sensor to the GND pin of the NodeMCU.
   - Connect the DATA pin of the DHT11 sensor to the D4 pin (GPIO2) of the NodeMCU.

### Step 2: Programming the NodeMCU

1. **Install the Arduino IDE**:
   - Download and install the Arduino IDE from [Arduino’s official website](https://www.arduino.cc/en/software).

2. **Add ESP8266 Board to Arduino IDE**:
   - Open the Arduino IDE.
   - Go to `File > Preferences` and add the following URL to the **Additional Boards Manager URLs**:
     ```
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```
   - Go to `Tools > Board > Boards Manager` and search for "ESP8266".
   - Install the **ESP8266 by ESP8266 Community** package.

3. **Install the DHT Library**:
   - Go to `Sketch > Include Library > Manage Libraries`.
   - Search for "DHT sensor library" by Adafruit and install it.

4. **Upload the Code to NodeMCU**:
   - Copy the following code and paste it into the Arduino IDE:

###Step 3: Setting up the Processing Software
1.**Download and Install Processing:

Download and install Processing from Processing's official website.
2.**Create a New Processing Sketch:

Open Processing and create a new sketch.

3. **Upload the Code:
   - Copy the following code and paste it into the Processing:


##Conclusion
By completing this project, you have successfully set up a system for sensing temperature and humidity using a DHT11 sensor and a NodeMCU, and visualized the data using Processing. This project helps to understand the basics of IoT sensor integration, data transmission over a local network, and real-time data visualization.     
