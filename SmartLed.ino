#define BLYNK_TEMPLATE_ID "TMPL2uGT0KiPO"
#define BLYNK_TEMPLATE_NAME "HAHA"
#define BLYNK_AUTH_TOKEN "UiypoN5PvyCfnfw0jfnS9nT6Ke4sL0e8"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Replace with your Wi-Fi credentials
char ssid[] = "Airtel Imagine";      // <-- put your Wi-Fi name here
char pass[] = "Menyibyaweee";  // <-- put your Wi-Fi password here

// LED connected to GPIO 2 (the small onboard LED pin for ESP32)
int ledPin = 2;

// BLYNK_WRITE function runs when you press the button widget in Blynk
BLYNK_WRITE(V0)
{
  int ledState = param.asInt(); // 0 = OFF, 1 = ON
  digitalWrite(ledPin, ledState);
}

void setup()
{
  // Start serial monitor
  Serial.begin(115200);

  // Set LED pin as output
  pinMode(ledPin, OUTPUT);

  // Connect to Wi-Fi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("Connected to Wi-Fi and Blynk Cloud!");
}

void loop()
{
  Blynk.run();
}
