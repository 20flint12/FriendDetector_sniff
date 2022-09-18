// NTPClient - Version: 3.2.0
// #include <NTPClient.h>

/*
  fix for ArduinoJson library 
  https://arduinojson.org/v6/api/config/enable_progmem/

  https://github.com/platformio/platform-espressif32/blob/master/boards/esp32dev.json
*/



// #define AZ_DeliveryDevKitC_V4_BOARD
#define AI_Thinker_BOARD





// #include <FS.h>
#include <Arduino.h>
#include <math.h>
// #include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

// // Wifi Manager
// #include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
// // Setup Wifi connection
// WiFiManager wifiManager;

// #define BLYNK_FIRMWARE_VERSION        "100.2.9"

#include <PString.h>  // https://github.com/boseji/PString-Arduino-lib

#include "main_BLE_multi.h"

#include "HW_info.h"
#include "my_WiFiConn.h"
#include "my_Device.h"
#include "my_Sniff_32.h"






bool procMainSniff(void *);
bool procPrintSniff(void *);
#include "my_Timers.h"

#include "my_NTP.h"



uint32_t chip_id = 1111111;
// bool init_pass = true;
bool single_pass = false;
uint32_t txValue;
uint16_t CUR_INDEX = 0;

String BLE_message = "";


bool procMainSniff(void *) {        // .

  if ( devider++ % 5 == 0 ) {
    Serial.print(".");

    if (deviceConnected) {
    //     //pTxCharacteristic->setValue(&txValue, 1);
    //     pTxCharacteristic->setValue((uint8_t*)charTemp, strTemp.length());
    //     pTxCharacteristic->notify();
    //     txValue++;
    }
    // send2Ble(".");  
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

  // send2Ble(":"); 
  // send2Ble(String(txValue)); 
  // send2Ble(String(__FILE__)); 
  // send2Ble(WiFi.macAddress()); 
  // send2Ble(String(chip_id)); 
  // send2Ble(String(KNOWN_ROUTER)); 

  // DynamicJsonDocument doc1(20);

  // String data = String(wanted[KNOWN_ROUTER].friendName) + String(deviceConnected); 
  // doc1["n"] = "data";

  // JsonObject obj1 = doc1.as<JsonObject>();
  // BLE_message = "";
  // serializeJson(obj1, BLE_message);
  // send2Ble(BLE_message); 
  
  char JSON[20];
  snprintf(JSON, sizeof(JSON), "{\"n\":\"%s\"}", wanted[KNOWN_ROUTER].friendName);

  send2Ble(String(JSON)); 


  // init_pass = true;

  // check_activity(true, true);        // void check_activity(bool do_print) {            // (strDevs)
  // Serial.println(String(strDevs));

  // loop_BLE_multi();
  if (deviceConnected) {
    digitalWrite(FLASH_GPIO_NUM, HIGH);   // turn the LED on (HIGH is the voltage level)

    for (itm = mymap.begin(); itm != mymap.end(); ++itm) {
  
      DynamicJsonDocument doc(20);

      uint64_t mac = itm->first;
      int i = itm->second;
      
      // doc["AABBCCDDEE"] = measurement; //millis()/1000;
      // String field = "AABBCCDDEE"; //printMac64s(mac);
      // Serial.println(printMac64s(mac));
      // doc["AABBCCDDEE"] = device[i].perform;
      // doc["n1"] = printMac64s(mac);


      uint prfrm = device[i].perform; 
      uint perform = prfrm;
      if ( prfrm > 1 ) {
        double res = log(prfrm) * 10.0;
        perform = res;
      }
      // uint perform = device[i].perform; 

      switch (i)
      {
      case 0: doc["p0"] = perform; break;
      case 1: doc["p1"] = perform; break;
      case 2: doc["p2"] = perform; break;
      case 3: doc["p3"] = perform; break;
      case 4: doc["p4"] = perform; break;
      case 5: doc["p5"] = perform; break;
      case 6: doc["p6"] = perform; break;
      case 7: doc["p7"] = perform; break;
      case 8: doc["p8"] = perform; break;
      case 9: doc["p9"] = perform; break;
      
      default: doc["pX"] = perform; break;
      }

      doc["n"] = 8;

      JsonObject obj = doc.as<JsonObject>();
      BLE_message = "";
      serializeJson(obj, BLE_message);

      send2Ble(BLE_message);  
    }
  }
  // disconnecting
  if (!deviceConnected && oldDeviceConnected) {
      // delay(500); // give the bluetooth stack the chance to get things ready
      pServer->startAdvertising(); // restart advertising
      Serial.println("start advertising");
      oldDeviceConnected = deviceConnected;
  }
  // connecting
  if (deviceConnected && !oldDeviceConnected) {
      // do stuff here on connecting
      oldDeviceConnected = deviceConnected;
  }
  
  reset_activity();
  recharge_taskPrintSniff();

  digitalWrite(FLASH_GPIO_NUM, LOW);    // turn the LED off by ma
  return true; // repeat? true
}


void setup() {

  Serial.begin(115200);
  //  Serial.setDebugOutput(true);
  while (!Serial);
  delay (1000);

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


  chip_id = print_hw_info(String(__FILE__), true);
  
  setup_config(chip_id);   // 
  
  wifi_station_init();

  // Serial.println("\n\\|/");
  setup_wificonn();
  delay (1000);

  // String bot_str =  "Message sent to " + Flint_CHAT_ID + " " + 
  //                   String(__FILE__) + " | " + WiFi.macAddress() + " " + 
  //                   wanted[KNOWN_ROUTER].friendName + 
  //                   " CH" + String(wanted[KNOWN_ROUTER].main_channel);
  // bot_str += (String)strDevs;
  // setup_UTbot(bot_str);
  
  // strDevs_publish_clear(true, true);

  wifi_sniffer_init();
  delay (1000);


  setup_BLE_multi();
  delay (3000);


  taskMainSniff = timerMainSniff.in(1, procMainSniff);
  taskPrintSniff = timerPrintSniff.in(PERIOD_PrintSniff, procPrintSniff);  


  // initialize digital pin LEDs as an output.
  pinMode(FLASH_GPIO_NUM, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by ma
  delay(10000);                       

  digitalWrite(FLASH_GPIO_NUM, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       
  digitalWrite(FLASH_GPIO_NUM, LOW);    // turn the LED off by ma
  delay(100);                       


}


void loop() {

  txValue++;

  timerMainSniff.tick();
  timerPrintSniff.tick();
 
}