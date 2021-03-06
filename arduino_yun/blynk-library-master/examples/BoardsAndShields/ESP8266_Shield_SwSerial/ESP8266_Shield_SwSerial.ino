/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 *
 * This example shows how to use ESP8266 Shield
 * via SoftwareSerial to connect your project to Blynk.
 *
 * For this example you need a modified ITEAD WeeESP8266 library:
 *   https://github.com/vshymanskyy/ITEADLIB_Arduino_WeeESP8266
 *
 * Please adjust the settings in the ESP8266.h:
 *   Set ESP8266_USE_SOFTWARE_SERIAL, if needed
 *   Set USER_SEL_VERSION to the version of your module
 *
 * Note: Ensure a stable serial connection to ESP8266!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 * Feel free to apply it to any other example. It's simple!
 *
 **************************************************************/
//#define BLYNK_DEBUG
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266.h>
#include <BlynkSimpleShieldEsp8266.h>

#include <SoftwareSerial.h>
SoftwareSerial SwSerial(2, 3); // RX, TX
ESP8266 wifi(SwSerial);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

void setup()
{
  Serial.begin(9600);   // Set console baud rate
  while (!Serial) {}

  SwSerial.begin(9600);  // Set ESP8266 baud rate
  while (!SwSerial) {}

  Blynk.begin(auth, wifi, "ssid", "pass");
}

void loop()
{
  Blynk.run();
}

