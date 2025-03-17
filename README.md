# Smart Doorbell with Visitor Notification Using ESP32  

## Overview  

The Smart Doorbell with Visitor Notification is an ESP32-based project designed to alert users about visitors through a push button and motion detection system. It sends real-time notifications via the Blynk app and uses LEDs and a buzzer for additional alerts.  

## Features  

- Push Button Doorbell: Alerts residents with a buzzer sound and sends a notification when pressed.  
- Motion Detection: Detects movement near the door and triggers a notification.  
- Blynk Integration: Uses the Blynk app to send instant alerts for both doorbell presses and motion detection.  
- LED Indicators:  
  - Red LED indicates motion detection.  
  - Green LED indicates the push button has been pressed.  
- Buzzer Alert: Produces a distinct two-tone sound to notify residents.  

## File Structure  

- Code: Contains the Arduino IDE code for ESP32.  
- Circuit_Diagram: Provides wiring details and connection schematics.  
- Mobile_App: Offers guidance on setting up the Blynk app.  

## How It Works  

1. Loading the System  
   - The ESP32 connects to Wi-Fi and initializes the Blynk platform.  
   - The system sets all components to an inactive state by default.  

2. Push Button Operation  
   - When the push button is pressed, the system:  
     - Activates the buzzer.  
     - Turns on the green LED.  
     - Sends a notification labeled "Doorbell Pressed!" through the Blynk app.  

3. Motion Detection Operation  
   - When the PIR sensor detects movement:  
     - The red LED turns on.  
     - A notification labeled "Motion Detected!" is sent through the Blynk app.  

4. Resetting the System  
   - The system resets LED indicators when no motion or button press is detected.  

## Usage  

1. Install the Blynk app and create a new template.  
2. Copy your Template ID, Template Name, and Auth Token into the code.  
3. Connect the ESP32 to Wi-Fi by updating the SSID and Password in the code.  
4. Wire the components as follows:  
   - PIR Sensor to D34  
   - Push Button to D14  
   - Buzzer to D27  
   - Red LED to D13  
   - Green LED to D26  
5. Upload the code to the ESP32 using Arduino IDE.  
6. Open the Blynk app to receive real-time alerts.  

Thank you:)
