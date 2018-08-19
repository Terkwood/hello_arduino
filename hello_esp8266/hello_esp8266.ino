#include <ConfigManager.h>          // Wifi connection and configuration manager for ESP8266 and ESP32.
                                    // https://github.com/nrwiersma/ConfigManager

ConfigManager configManager;        // initialize global instance of the lib

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on by making the voltage LOW
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000);                      // Wait for two seconds
}


