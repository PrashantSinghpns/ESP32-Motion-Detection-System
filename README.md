# ESP32-Motion-Detection-System
ESP32-based motion detection system using PIR sensor, GPIO interrupts, FreeRTOS, MQTT, and LED/Buzzer alerts.

## Overview

An ESP32-based motion detection system using a PIR sensor, GPIO interrupts, FreeRTOS task scheduling, MQTT messaging, and LED/Buzzer alerts.

## Features

- PIR Motion Detection
- GPIO Interrupts
- FreeRTOS Task Handling
- MQTT Alerts
- LED Notification
- Buzzer Notification
- WiFi Connectivity

## Hardware

- ESP32
- PIR Sensor (HC-SR501)
- LED
- Buzzer

##Architecture

PIR Sensor
    │
    ▼
GPIO Interrupt
    │
    ▼
ISR (pirISR)
    │
    ▼
motionDetected = true
    │
    ▼
FreeRTOS Motion Task
    │
    ├── LED ON
    ├── Buzzer ON
    └── MQTT Publish
             │
             ▼
      MQTT Broker
             │
             ▼
      Mobile App / Dashboard

## Future Improvements

- Motion Counter
- Watchdog Timer
- Deep Sleep
- Cloud Dashboard
