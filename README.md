# IoT-based-Smart-Doorbell-with-Visitor-Notification

This project is a Smart Doorbell System designed using an ESP32, featuring a PIR sensor, push button, and IoT integration via Blynk to send real-time visitor notifications.

Features
Push Button Doorbell: Pressing the button rings a buzzer and sends a notification to the user's phone.
Motion Detection: Detects movement near the door and alerts the user.
Blynk Integration: Uses the Blynk app to send instant alerts when the doorbell is pressed or motion is detected.
LED Indicators:
Red LED turns on for motion detection.
Green LED turns on when the push button is pressed.
Buzzer Alert: Produces a “Someone is calling you” tone for added awareness.
Components Required
ESP32
PIR Sensor (for motion detection)
Push Button (for manual doorbell trigger)
Buzzer (for sound alert)
Red and Green LEDs (for visual status)
Blynk App (for mobile notifications)
How It Works
Push Button Alert: When the push button is pressed, the system:

Activates the buzzer.
Turns on the green LED.
Sends a "Doorbell Pressed!" notification to the Blynk app.
Motion Detection Alert: When motion is detected by the PIR sensor:

The red LED turns on.
A "Motion Detected!" notification is sent to the Blynk app.
The system resets the LED status when no motion or button press is detected.

Setup Instructions
Install the Blynk app and create a new template.
Copy your Template ID, Template Name, and Auth Token into the code.
Connect the ESP32 to Wi-Fi by entering your SSID and Password in the code.
Wire the components as follows:
PIR Sensor → D34
Push Button → D14
Buzzer → D27
Red LED → D13
Green LED → D26
Upload the code to your ESP32 using Arduino IDE.
Open the Blynk app to monitor alerts in real-time.
Code Highlights
The code ensures noise-free signals using a debounce delay for accurate motion and button detection.
The callingTone() function generates a distinct two-tone buzzer alert.
Efficient power management is implemented to reduce energy consumption.
