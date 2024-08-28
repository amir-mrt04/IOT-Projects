# Sensing Temperature and Humidity Over the Internet (Node-Red)

This project demonstrates how to integrate a NodeMCU microcontroller with Node-RED to monitor temperature and humidity using a DHT11 sensor. The collected data is transmitted to a Node-RED server over the internet, where it is visualized in real-time.

## Overview

In this project, a DHT11 sensor is used to measure temperature and humidity. The NodeMCU microcontroller sends this data to a Node-RED server via HTTP POST requests. Node-RED processes and visualizes the data using its dashboard features, allowing for real-time monitoring from anywhere.

## Project Objectives

- Learn about integrating IoT sensors with Node-RED.
- Develop a system to transmit and visualize temperature and humidity data over the internet.
- Configure and utilize Node-RED for real-time data visualization.

## Hardware and Software Requirements

### Hardware

- **NodeMCU (ESP8266)**: A microcontroller for interfacing with the DHT11 sensor and sending data.
- **DHT11 Sensor**: Measures temperature and humidity.
- **Breadboard and Jumper Wires**: For making connections.
- **USB Cable**: To connect and power the NodeMCU.

### Software

- **Arduino IDE**: For programming the NodeMCU.
- **Node-RED**: For processing and visualizing the data.
- **Node-RED Dashboard**: For creating visualizations.

## Installation and Setup

### Step 1: Setting up the Hardware

1. **Connect the DHT11 Sensor to NodeMCU:**
   - **VCC** to **3.3V** on NodeMCU.
   - **GND** to **GND** on NodeMCU.
   - **DATA** to **D4 (GPIO2)** on NodeMCU.

### Step 2: Programming the NodeMCU

1. **Install the Arduino IDE:**
   - Download from [Arduino’s official website](https://www.arduino.cc/en/software).

2. **Add ESP8266 Board to Arduino IDE:**
   - Open **File > Preferences** and add:
     ```
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```
   - Go to **Tools > Board > Boards Manager**, search for "ESP8266", and install it.

3. **Install the DHT Library:**
   - Go to **Sketch > Include Library > Manage Libraries**, search for "DHT sensor library" by Adafruit, and install it.

4. **Upload the Code to NodeMCU:**
   - Configure your NodeMCU with the provided code to connect to your WiFi and send data to Node-RED. Customize the code with your WiFi credentials and Node-RED server URL.

   **[NodeMCU Arduino Code](https://github.com/your-username/your-repository/blob/main/NodeMCU_Code.ino)**

### Step 3: Setting up Node-RED

1. **Install Node-RED:**
   - Follow installation instructions from [Node-RED official website](https://nodered.org/docs/getting-started/).

2. **Configure Node-RED Flow:**
   - Create a flow with an **HTTP In** node, **Function** node, and **HTTP Response** node to receive data at a specified endpoint (e.g., `/dht11`).

3. **Set Up Node-RED Dashboard:**
   - Install `node-red-dashboard` via **Manage palette**.
   - Add visualization nodes like **ui_gauge** or **ui_chart** to display data on the dashboard.

## Usage

- Start Node-RED and open the dashboard at `http://localhost:1880/ui`.
- Ensure NodeMCU is powered and connected to your WiFi network.
- The NodeMCU will send data to Node-RED, and you should see real-time visualizations of temperature and humidity on the dashboard.

## Conclusion

This project successfully demonstrates how to integrate a NodeMCU with Node-RED for real-time temperature and humidity monitoring. You have configured the NodeMCU to send data over the internet and set up Node-RED to process and visualize this data.


