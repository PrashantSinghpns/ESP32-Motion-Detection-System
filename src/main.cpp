#include <WiFi.h> // Include the WiFi library
#include <PubSubClient.h> // Include the PubSubClient library for MQTT

#define PIR_PIN 27
#define LED_PIN 2
#define BUZZER_PIN 4

// shared variable between the ISR and the main loop

volatile bool motionDetected = false; // Flag to indicate motion detection

// ISR Function to handle motion detection
void IRAM_ATTR pirISR(){
    motionDetected = true; // Set the motion detected flag to true
}

// motion detection function
void motionTask(void *pvParameters){

    while(1){
        if(motionDetected){
            motionDetected = false; // Reset the motion detected flag

            digitalWrite(LED_PIN, HIGH); // Turn on the LED
            digitalWrite(BUZZER_PIN, HIGH); // Turn on the buzzer
            Serial.println("motion detected!"); // Print motion detected message

            //MQTT Alert
            client.publish("home/motion", "Motion Detected!"
            ); // Publish motion detected message to MQTT topic

            vTaskDelay(
                pdMS_TO_TICKS(5000)
            ); // Wait for 5 seconds

            digitalWrite(LED_PIN, LOW); // Turn off the LED
            digitalWrite(BUZZER_PIN, LOW); // Turn off the buzzer

        }

        vTaskDelay(
            pdMS_TO_TICKS(100)
    ); // Short delay to prevent task hogging CPU

    }
}

//setup GPIO pins and Serial communication
void setup(){
    Serial.begin(115200); // Start the Serial communication buad rate at 115200

    pinMode(PIR_PIN, INPUT); // Set PIR pin as input
    pinMode(LED_PIN, OUTPUT); // Set LED pin as output
    pinMode(BUZZER_PIN, OUTPUT); // Set Buzzer pin as output
}


//Attach Interrupt to the PIR sensor pin

attachInterrupt(
    digitalPinToInterrupt(PIR_PIN), // Attach interrupt to the PIR pin
    pirISR, // Specify the ISR function to call when motion is detected
    RISING // Trigger the interrupt when signal goes from LOW to HIGH (motion detected)
)

// FreeRTOS task creation for motion detection
xTaskCreate(
    motionTask // Specify the function to run as a task
    "MotionTask", // Name of the task
    2048, // Stack size for the task
    1, // Priority of the task
    NULL // Task handle (not used in this case)
)
