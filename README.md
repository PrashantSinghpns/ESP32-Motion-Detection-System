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

## Architecture

PIR Sensor
↓
GPIO Interrupt
↓
ISR
↓
Motion Flag
↓
FreeRTOS Task
↓
MQTT Alert
↓
LED + Buzzer

## Future Improvements

- Motion Counter
- Watchdog Timer
- Deep Sleep
- Cloud Dashboard
