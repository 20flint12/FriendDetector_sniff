// NTPClient - Version: 3.2.0
// #include <NTPClient.h>

/*
  fix for ArduinoJson library 
  https://arduinojson.org/v6/api/config/enable_progmem/

  https://github.com/platformio/platform-espressif32/blob/master/boards/esp32dev.json
*/


// #define BLYNK_FIRMWARE_VERSION        "100.2.9"


// #define AZ_DeliveryDevKitC_V4_BOARD
#define AI_Thinker_BOARD



#include <Arduino.h>
#include <math.h>
#include <PString.h>  // https://github.com/boseji/PString-Arduino-lib



bool procMainSniff(void *);
bool procPrintSniff(void *);
bool procBleReceived(void *);
#include "my_Timers.h"


String BLE_message = "";
String str_BLE_received = "";
#include "main_BLE_multi.h"


#include "HW_info.h"
#include "my_WiFiConn.h"
#include "my_Device.h"
#include "my_Sniff_32.h"
#include "my_NTP.h"


static char JSON[20];

uint32_t chip_id = 1111111;
// bool init_pass = true;
bool single_pass = false;
uint32_t txValue;
uint16_t CUR_INDEX = 0;



bool procMainSniff(void *) {        //

  if ( devider++ % 5 == 0 ) {
    Serial.print(".");
  }

  wifi_sniffer_set_channel(channel);
  // channel = (channel % WIFI_CHANNEL_MAX) + 1;
  channel = wanted[KNOWN_ROUTER].main_channel;

  recharge_taskMainSniff();
  return true; // repeat? true
}


bool procPrintSniff(void *) {       //

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
  
  // char JSON[20];
  snprintf(JSON, sizeof(JSON), "{\"n\":\"%s\"}", wanted[KNOWN_ROUTER].friendName);
  send2Ble(String(JSON)); 

  
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


bool procBleReceived(void *) {       //

  // Serial.print("value received = ");
  // Serial.println(str_BLE_received);

  // char JSON[20];
  snprintf(JSON, sizeof(JSON), "{\"d\":\"%s\"}", str_BLE_received);
  send2Ble(String(JSON)); 


  // Set param (channel, ...)
  if (str_BLE_received.startsWith("c ")) {  // if the received message starts with "c "...

      const char *buf = str_BLE_received.c_str();
      uint8_t n = sscanf(buf, "c %d", &channel);
  }

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
  //taskBleReceived = timerBleReceived.in(100, procBleReceived); 


  // initialize digital pin LEDs as an output.
  pinMode(FLASH_GPIO_NUM, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  for (size_t i = 0; i < 10; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(10);                       
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by ma
    delay(100);                       
  }

  for (size_t i = 0; i < 10; i++)
  {
    digitalWrite(FLASH_GPIO_NUM, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(10);                       
    digitalWrite(FLASH_GPIO_NUM, LOW);    // turn the LED off by ma
    delay(100);                       
  }

}


void loop() {

  txValue++;

  timerMainSniff.tick();
  timerPrintSniff.tick();
  timerBleReceived.tick();

}