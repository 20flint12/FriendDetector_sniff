// NTPClient - Version: 3.2.0
// #include <NTPClient.h>

/*
  fix for ArduinoJson library 
  https://arduinojson.org/v6/api/config/enable_progmem/

  https://github.com/platformio/platform-espressif32/blob/master/boards/esp32dev.json

*/

// #include <FS.h>
#include <Arduino.h>
// #include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

// // Wifi Manager
// #include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
// // Setup Wifi connection
// WiFiManager wifiManager;

// #define BLYNK_FIRMWARE_VERSION        "100.2.9"

#include <PString.h>  // https://github.com/boseji/PString-Arduino-lib


#include "BluetoothSerial.h"
BluetoothSerial SerialBT;



#include "HW_info.h"
#include "my_WiFiConn.h"
#include "my_Device.h"
#include "my_Sniff_32.h"


bool procMainSniff(void *);
bool procPrintSniff(void *);
#include "my_Timers.h"

#include "my_NTP.h"



bool init_pass = true;
bool single_pass = false;


uint16_t CUR_INDEX = 0;



bool procMainSniff(void *) {        // .

  if ( devider++ % 5 == 0 ) {
    Serial.print(".");
  }

  int i = wanted[KNOWN_ROUTER].main_channel;
  wifi_sniffer_set_channel(channel);
  // channel = (channel % WIFI_CHANNEL_MAX) + 1;
  channel = wanted[KNOWN_ROUTER].main_channel;

  recharge_taskMainSniff();
  return true; // repeat? true
}


bool procPrintSniff(void *) {       // :  (strList)

  Serial.println(":");

  init_pass = true;

  check_activity(true, true);        // void check_activity(bool do_print) {            // (strDevs)
  // Serial.println(String(strDevs));

  recharge_taskPrintSniff();
  return true; // repeat? true
}


void setup() {

  Serial.begin(115200);
  //  Serial.setDebugOutput(true);
  while (!Serial);
  delay (1000);

  SerialBT.begin("ESP32Flint"); //Bluetooth device name

  // // factoryReset();     // ÐºÐ¾Ð¼ÐµÐ½ÑÐ¸ÑÐ¾Ð²Ð°ÑÑ !!!
  // Serial.println("Resetting to factory settings");
  // wifiManager.resetSettings();
  // SPIFFS.format();
  // ESP.reset();
  // // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


  uint32_t chip_id = print_hw_info(String(__FILE__), true);
  
  setup_config(chip_id);   // Ð²ÐºÐ»ÑÑÐµÐ½Ð¸Ðµ ÐºÐ¾Ð½ÑÐ¸Ð³ÑÑÐ°ÑÐ¸Ð¸ Ð² Ð·Ð°Ð²Ð¸ÑÐ¸Ð¼Ð¾ÑÑÐ¸ Ð¾Ñ Ð¼Ð¾Ð´ÑÐ»Ñ
  
  wifi_station_init();


  Serial.println("\n\\|/");
  setup_wificonn();

  // String bot_str =  "Message sent to " + Flint_CHAT_ID + " " + 
  //                   String(__FILE__) + " | " + WiFi.macAddress() + " " + 
  //                   wanted[KNOWN_ROUTER].friendName + 
  //                   " CH" + String(wanted[KNOWN_ROUTER].main_channel);
  // bot_str += (String)strDevs;
  // setup_UTbot(bot_str);
  
  
  // strDevs_publish_clear(true, true);
  

  taskMainSniff = timerMainSniff.in(1, procMainSniff);
  taskPrintSniff = timerPrintSniff.in(PERIOD_PrintSniff, procPrintSniff);  

  wifi_sniffer_init();
  

}


void loop() {

  timerMainSniff.tick();
  timerPrintSniff.tick();
 
}