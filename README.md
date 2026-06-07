# ESP32 IoT Soil Moisture Monitor

A real-time IoT soil moisture monitoring system with a live 
Node-RED dashboard.

## Description
ESP32 reads soil moisture levels and transmits data via MQTT 
to a Node-RED dashboard displaying a live gauge and historical 
chart. Alerts trigger when moisture is too dry or too wet.

## Features
- Real-time moisture readings every 2 seconds
- Live gauge and historical chart on Node-RED dashboard
- MQTT communication via HiveMQ public broker
- Dry/Normal/Wet status classification
- LCD display showing local readings on the circuit

## Components
- ESP32
- Potentiometer (simulates soil moisture sensor)
- LCD 16x2 I2C display

## How It Works
1. ESP32 reads analog moisture value (0-4095)
2. Converts to percentage (0-100%)
3. Publishes to MQTT topic via WiFi
4. Node-RED receives and displays on dashboard

## Simulation
Run the live simulation here: [Open in Wokwi](PASTE WOKWI LINK HERE)

## Dashboard
Built with Node-RED + node-red-dashboard
- Gauge: live moisture reading
- Chart: moisture history over time

## Tools Used
- Arduino IDE / Wokwi simulator
- Embedded C
- Python (paho-mqtt)
- Node-RED
- MQTT (HiveMQ broker)
