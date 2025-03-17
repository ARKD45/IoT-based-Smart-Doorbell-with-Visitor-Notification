#define BLYNK_TEMPLATE_ID "TMPL3bi2CbDtf"
#define BLYNK_TEMPLATE_NAME "Smart doorbell with visitor notification"
#define BLYNK_AUTH_TOKEN "DFm8Lcd0TbNbsQ5sJNSUVNlx1EIy5rdm"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "DFm8Lcd0TbNbsQ5sJNSUVNlx1EIy5rdm";  // Blynk Auth Token
char ssid[] = "moto g60";   // WiFi SSID
char pass[] = "11111111";   // WiFi Password

// Pin assignments
int pirPin = 34;           // PIR sensor pin (D34)
int buttonPin = 14;        // Push button pin (D14)
int buzzerPin = 27;        // Buzzer pin (D27)
int redLedPin = 13;        // Red LED for motion detection (D13)
int greenLedPin = 26;      // Green LED for button press (D26)

bool motionDetected = false; // Track motion detection state
bool buttonPressed = false;  // Track button press state

unsigned long lastMotionTime = 0; // Track last motion detection time
const unsigned long debounceDelay = 2000; // Debounce delay (2 seconds)

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Setup Blynk
  Blynk.begin(auth, ssid, pass);

  // Setup pin modes
  pinMode(pirPin, INPUT);        // PIR sensor
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up for push button
  pinMode(buzzerPin, OUTPUT);    // Buzzer
  pinMode(redLedPin, OUTPUT);    // Red LED for motion detection
  pinMode(greenLedPin, OUTPUT);  // Green LED for button press

  // Set buzzer and LEDs off initially
  digitalWrite(buzzerPin, LOW);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
}

// Function to produce "Someone is calling you" tone for 1 second
void callingTone(int pin, int duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    tone(pin, 1200);    // High-pitch sound (e.g., 1200 Hz)
    delay(250);         // Hold for 250ms
    tone(pin, 800);     // Low-pitch sound (e.g., 800 Hz)
    delay(250);         // Hold for 250ms
  }
  noTone(pin);  // Stop tone after duration
}

void loop() {
  // Check PIR Sensor Motion Detection
  int pirState = digitalRead(pirPin);

  if (pirState == HIGH && millis() - lastMotionTime > debounceDelay) {
    // Motion detected
    if (!motionDetected) {
      motionDetected = true;
      digitalWrite(redLedPin, HIGH);  // Turn on Red LED when motion is detected
      Blynk.logEvent("motion_detected", "Motion detected at the door!");
      lastMotionTime = millis();     // Update last motion detection time
    }
  } else if (pirState == LOW) {
    // No motion detected
    if (motionDetected) {
      motionDetected = false;
      digitalWrite(redLedPin, LOW);  // Turn off Red LED when motion stops
    }
  }

  // Check Doorbell Push Button Detection (with debounce)
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && !buttonPressed) {
    // If the button is pressed for the first time (LOW means pressed due to PULLUP)
    buttonPressed = true;
    digitalWrite(greenLedPin, HIGH);  // Turn on Green LED
    Blynk.logEvent("doorbell_pressed", "Doorbell pressed!");
    callingTone(buzzerPin, 1000);     // Play calling tone for 1 second
    delay(1000);                      // Hold for 1 second
    digitalWrite(greenLedPin, LOW);   // Turn off Green LED
  } else if (buttonState == HIGH) {
    // Reset button press state when released
    buttonPressed = false;
  }

  Blynk.run();  // Keep Blynk connection alive
}
