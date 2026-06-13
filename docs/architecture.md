## Event Flow

PIR detects motion
↓
GPIO Interrupt
↓
ISR executes
↓
Motion flag set
↓
FreeRTOS Task wakes
↓
MQTT alert sent
↓
LED and Buzzer activated
