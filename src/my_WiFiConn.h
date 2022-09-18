#pragma once
#ifndef _WIFICONN_H    // Put these two lines at the top of your file.
#define _WIFICONN_H    // (Use a suitable name, usually based on the file name.)

#if defined(ARDUINO_ARCH_ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ARDUINO_ARCH_ESP32)
#include <WiFi.h>
#endif


// #define WIFI_SSID "Guest-PLINFA"
// #define WIFI_PASSWORD "77777778"

// #define WIFI_SSID "ZyXEL-FLINT"
// #define WIFI_PASSWORD "6393363933"

// #define WIFI_SSID "ASUS-FLINT"
// #define WIFI_PASSWORD "8845064068"

//#define WIFI_SSID "POCO Flint"
//#define WIFI_PASSWORD "88888878"

#define WIFI_SSID "Roza"
#define WIFI_PASSWORD "87775561177"

// #define WIFI_SSID "WebHMI_Dryer"
// #define WIFI_PASSWORD "bokeiDryer"



void setup_wificonn()
{  

  // attempt to connect to Wifi network:
  Serial.print("Connecting to WiFi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  Serial.print(" ");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  
  String hostname = "noname";
#if defined(ARDUINO_ARCH_ESP8266)
  hostname = WiFi.hostname(); // + " - " + WiFi.macAddress();
#elif defined(ARDUINO_ARCH_ESP32)
  hostname = WiFi.getHostname();
#endif

  
  String conn_res = " connected!\n";
  conn_res += "WiFi client: " + hostname + " ip_addr: " + WiFi.localIP().toString() + "\n";
  conn_res += String(WiFi.SSID()) + " [" + String(WiFi.BSSIDstr()) + "] RSSI: " + String(WiFi.RSSI()) + "dBm\n\n";
  Serial.print(conn_res);

}


#endif // _WIFICONN_H    // Put this line at the end of your file.
