#pragma once
#ifndef _MY_DEVICE_H  // Put these two lines at the top of your file.
#define _MY_DEVICE_H  // (Use a suitable name, usually based on the file name.)


//https://www.cplusplus.com/reference/unordered_map/unordered_map/find/

// ÃÂ¤ https://www.w3schools.com/charsets/ref_utf_latin1_supplement.asp
// ÃÂ°   ÃÂ± ÃÂ² ~ ÃÂ ÃÂº  Ã¢ÂÂ¢  Ã¢ÂÂ - ÃÂ ÃÂ + -

#include <Arduino.h>

String printMac64(uint64_t mac);
String printMac64s(uint64_t mac);


#include <map>
std::map<uint64_t, int> mymap;
//std::map<uint64_t, int>::const_iterator itm;
std::map<uint64_t, int>::iterator itm = mymap.begin();



/*
esp8266     1   ~ESP8266: Feedback
esp8266     2   ~ESP8266: IOT balcony 
esp8266     3   ESP8266: Feedback2              BOT_TOKEN_InspectorBiblyka_bot          KNOWN_ROUTER_borovsa                          !
esp8266     4   ESP8266: cut black              BOT_TOKEN_biblika_bot                   KNOWN_ROUTER_Kyivstar_82B0  (ÃÂ½ÃÂ° ÃÂÃÂºÃÂ°ÃÂÃÂ)        !               
esp8266     5   ESP8266: deauth                 BOT_TOKEN_InspectorBiblyka_bot          KNOWN_ROUTER_borovsa
esp8266     6   ESP8266: cut color              BOT_TOKEN_FlintSmart_bot                KNOWN_ROUTER_TP_LINK_F186   (ÃÂ½ÃÂ° ÃÂÃÂºÃÂ°ÃÂÃÂ)        !

esp32       7   ESP32: IOT home                 BOT_TOKEN_FriendDetectorBiblyka_bot     KNOWN_ROUTER_Beeline_21
esp32       8   ESP32: second                   BOT_TOKEN_FriendDetectorBiblyka_bot     KNOWN_ROUTER_ZyXEL_FLINT    (ÃÂ½ÃÂ° ÃÂºÃÂ¾ÃÂ¼ÃÂ¾ÃÂ´ÃÂµ)       !       

esp32-cam   9   ESP32-CAM: doorbell             BOT_TOKEN_FlintDebug_bot                KNOWN_ROUTER_Richard        (ÃÂ½ÃÂ° ÃÂÃÂ¸ÃÂÃÂµ)         !
esp32-cam   10  ESP32-CAM: last problem         BOT_TOKEN_InspectorBiblyka_bot          KNOWN_ROUTER_ZyXEL_FLINT    (ÃÂ½ÃÂ° ÃÂ±ÃÂ°ÃÂ»ÃÂºÃÂ¾ÃÂ½ÃÂµ)      

esp32       11  ESP32: third                    BOT_TOKEN_astro_bot                     KNOWN_ROUTER_Nosik                            !       


8 - Chip is ESP32-D0WDQ6 (revision 1)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
Crystal is 40MHz
MAC: 08:3a:f2:a9:a4:a4

10 - Chip is ESP32-D0WDQ6 (revision 1)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
Crystal is 40MHz
MAC: 3c:61:05:16:f5:4c

*/



String BOARD_NAME = "noname";
static const char BOARD_1[] = "#1 ~ESP8266: Feedback";
static const char BOARD_2[] = "#2 ~ESP8266: IOT balcony";
static const char BOARD_3[] = "#3 ESP8266: Feedback2";
static const char BOARD_4[] = "#4 ESP8266: cut black";
static const char BOARD_5[] = "#5 ESP8266: deauth";
static const char BOARD_6[] = "#6 ESP8266: cut color";
static const char BOARD_7[] = "#7 ESP32: IOT home";
static const char BOARD_8[] = "#8 ESP32: second";
static const char BOARD_9[] = "#9 ESP32-CAM: doorbell";
static const char BOARD_10[] = "#10 ESP32-CAM: last problem";
static const char BOARD_11[] = "#11 ESP32-CAM: third";



String BOT_TOKEN = "";
static const char BOT_TOKEN_InspectorBiblyka_bot[] = "1796700435:AAG_RgjpPYOedk8iFzgN7DXZ0tYcwU39LvQ";       // @InspectorBiblyka_bot
static const char BOT_TOKEN_FlintSmart_bot[] = "1261633346:AAHC4ctXxjZ4hdATaP_Of0608Ju7lIn5sxE";             // @FlintSmart_bot
static const char BOT_TOKEN_biblika_bot[] = "1042106378:AAFrhuhaLOtcDEU4Jq11u8jgp41Ll_xzG8w";                // @biblika_bot
static const char BOT_TOKEN_FlintDebug_bot[] = "1207351455:AAH2SXGwOfkHRbzqr7ISJ25nm-N9QgOs3Vo";             // @FlintDebug_bot
static const char BOT_TOKEN_FriendDetectorBiblyka_bot[] = "1773146223:AAHiWcIJn-V5x_qgqOeKyCa1_dZK47vGwi8";  // @FriendDetectorBiblyka_bot
static const char BOT_TOKEN_astro_bot[] = "345369460:AAEjHUhRMdT-E44Xbd82YG_I2C5-uCjR8Wg";                   // @scsdvwervdbot
static const char BOT_TOKEN_SecurBiblyka_bot[] = "1793076872:AAHRaeOi_w6zMlPZfkw78sJSfb9rV8f44iQ";           // @SecurBiblyka_bot

static const char BOT_TOKEN_FlintRemote_bot[] = "929227377:AAEjyfJQ55LdiNL-xh8GxkMAtNPSXbVhUG8";  // @FlintRemote_bot
static const char BOT_TOKEN_PeppyRemote[] = "688584881:AAE7-m41a7y63yLsjpkUFXx0NAlVh4CMCVU";      // @PeppyRemote_bot
static const char BOT_TOKEN_StasRemote[] = "941571132:AAGSgE489zun31J2uE7__OuFpoikPCft0cQ";       // @StasRemote_bot

// String BOT_TOKEN_InspectorBiblyka_bot       = "1796700435:AAG_RgjpPYOedk8iFzgN7DXZ0tYcwU39LvQ";  // @InspectorBiblyka_bot
// String BOT_TOKEN_FlintSmart_bot             = "1261633346:AAHC4ctXxjZ4hdATaP_Of0608Ju7lIn5sxE";  // @FlintSmart_bot
// String BOT_TOKEN_biblika_bot                = "1042106378:AAFrhuhaLOtcDEU4Jq11u8jgp41Ll_xzG8w";  // @biblika_bot
// String BOT_TOKEN_FlintDebug_bot             = "1207351455:AAH2SXGwOfkHRbzqr7ISJ25nm-N9QgOs3Vo";  // @FlintDebug_bot
// String BOT_TOKEN_FriendDetectorBiblyka_bot  = "1773146223:AAHiWcIJn-V5x_qgqOeKyCa1_dZK47vGwi8";  // @FriendDetectorBiblyka_bot



uint8_t KNOWN_ROUTER = 0;
#define KNOWN_ROUTER_OOO_Plinfa 7    // router OOO Plinfa
#define KNOWN_ROUTER_Guest_PLINFA 8  // router Guest-PLINFA
#define KNOWN_ROUTER_ASUS_FLINT 9    // router ASUS-FLINT
#define KNOWN_ROUTER_ZyXEL_FLINT 10  // router ZyXEL-FLINT

#define KNOWN_ROUTER_Richard 11        // router Richard          @biblika_bot
#define KNOWN_ROUTER_TP_LINK_F186 12   // router TP-LINK_F186     @FriendDetectorBiblyka_bot
#define KNOWN_ROUTER_Kyivstar_82B0 13  // router Kyivstar_82B0    @InspectorBiblyka_bot
#define KNOWN_ROUTER_Nosik 14          // router Nosik            @FlintDebug_bot
#define KNOWN_ROUTER_HiddenSSID 15     // router HiddenSSID       @FlintSmart_bot
#define KNOWN_ROUTER_borovsa 16        // router borovsa          @FlintSmart_bot
#define KNOWN_ROUTER_TP_LINK_344A 17   // router bokei
#define KNOWN_ROUTER_Roza 18           // router Roza
#define KNOWN_ROUTER_Roza_1 19         // router Roza 1



void setup_config(uint32_t chip_id) {  // ÃÂ²ÃÂºÃÂ»ÃÂÃÂÃÂµÃÂ½ÃÂ¸ÃÂµ ÃÂºÃÂ¾ÃÂ½ÃÂÃÂ¸ÃÂ³ÃÂÃÂÃÂ°ÃÂÃÂ¸ÃÂ¸ ÃÂ² ÃÂ·ÃÂ°ÃÂ²ÃÂ¸ÃÂÃÂ¸ÃÂ¼ÃÂ¾ÃÂÃÂÃÂ¸ ÃÂ¾ÃÂ ÃÂ¼ÃÂ¾ÃÂ´ÃÂÃÂ»ÃÂ

  strDevs.printf_P(PSTR("\n=== Gonfiguration ===\n"));

  switch (chip_id) {
    case 0x0067DE7C:  // #3 ESP8266: Feedback2
      BOARD_NAME = BOARD_3;
      strDevs.println(BOARD_NAME);
      BOT_TOKEN = BOT_TOKEN_InspectorBiblyka_bot;
      strDevs.printf_P(PSTR("InspectorBiblyka_bot\n"));
      KNOWN_ROUTER = KNOWN_ROUTER_borovsa;
      strDevs.printf_P(PSTR("KNOWN_ROUTER_borovsa\n"));
      break;

    case 0x00C02AE8:  // #4 ESP8266: cut black
      BOARD_NAME = BOARD_4;
      strDevs.println(BOARD_NAME);
      BOT_TOKEN = BOT_TOKEN_biblika_bot;
      strDevs.printf_P(PSTR("BOT_TOKEN_biblika_bot\n"));
      KNOWN_ROUTER = KNOWN_ROUTER_Kyivstar_82B0;
      strDevs.printf_P(PSTR("KNOWN_ROUTER_Kyivstar_82B0\n"));
      break;

    case 0x0067DE79:  // #5 ESP8266: deauth ===================================== Plinfa
      BOARD_NAME = BOARD_5;
      strDevs.println(BOARD_NAME);
      BOT_TOKEN = BOT_TOKEN_InspectorBiblyka_bot;
      strDevs.printf_P(PSTR("BOT_TOKEN_InspectorBiblyka_bot\n"));
      KNOWN_ROUTER = KNOWN_ROUTER_borovsa;
      strDevs.printf_P(PSTR("KNOWN_ROUTER_borovsa\n"));  // KNOWN_ROUTER_OOO_Plinfa
      break;

    case 0x00B617B2:  // #6 ESP8266: cut color
      BOARD_NAME = BOARD_6;
      strDevs.println(BOARD_NAME);
      BOT_TOKEN = BOT_TOKEN_FlintSmart_bot;
      strDevs.printf_P(PSTR("BOT_TOKEN_FlintSmart_bot\n"));
      KNOWN_ROUTER = KNOWN_ROUTER_TP_LINK_F186;
      strDevs.printf_P(PSTR("KNOWN_ROUTER_TP_LINK_F186\n"));
      break;


    case 0xACFE3BCC:  // #7 ESP32: IoT_home ************************************** Bokei
      BOARD_NAME = BOARD_7;
      strDevs.println(BOARD_NAME);
      BOT_TOKEN = BOT_TOKEN_FriendDetectorBiblyka_bot;
      strDevs.printf_P(PSTR("BOT_TOKEN_FriendDetectorBiblyka_bot\n"));
      KNOWN_ROUTER = KNOWN_ROUTER_TP_LINK_344A;
      strDevs.printf_P(PSTR("KNOWN_ROUTER_TP_LINK_344A\n"));
      break;

    case 0xA9FBBEAC:  // #8 ESP32: second
      BOARD_NAME = BOARD_8;
      strDevs.println(BOARD_NAME);
      BOT_TOKEN = BOT_TOKEN_FriendDetectorBiblyka_bot;
      strDevs.printf_P(PSTR("BOT_TOKEN_FriendDetectorBiblyka_bot\n"));
      KNOWN_ROUTER = KNOWN_ROUTER_Guest_PLINFA;
      strDevs.printf_P(PSTR("KNOWN_ROUTER_Guest_PLINFA\n"));
      break;

    case 0xF2FFDEFC:  // #9   ESP32-CAM: doorbell 0xF2FFDEFC 0xF2BD9E7C
      BOARD_NAME = BOARD_9;
      // strDevs.println(BOARD_NAME);
      BOT_TOKEN = BOT_TOKEN_FlintDebug_bot;
      // strDevs.printf_P(PSTR("BOT_TOKEN_FlintDebug_bot\n"));
      KNOWN_ROUTER = KNOWN_ROUTER_Roza;
      // strDevs.printf_P(PSTR("KNOWN_ROUTER_Richard\n"));
      break;

    case 0x1605613C:  // Ã¢ÂÂ10  ESP32-CAM: last problem
      BOARD_NAME = BOARD_10;
      strDevs.println(BOARD_NAME);
      BOT_TOKEN = BOT_TOKEN_InspectorBiblyka_bot;
      strDevs.printf_P(PSTR("BOT_TOKEN_InspectorBiblyka_bot\n"));
      KNOWN_ROUTER = KNOWN_ROUTER_borovsa;
      strDevs.printf_P(PSTR("KNOWN_ROUTER_borovsa\n"));
      break;

    case 0xA9FBBE1C:  // #11 ESP32: third
      BOARD_NAME = BOARD_11;
      strDevs.println(BOARD_NAME);
      BOT_TOKEN = BOT_TOKEN_astro_bot;
      strDevs.printf_P(PSTR("BOT_TOKEN_astro_bot\n"));
      KNOWN_ROUTER = KNOWN_ROUTER_Nosik;
      strDevs.printf_P(PSTR("KNOWN_ROUTER_Nosik\n"));
      break;



    default:
      strDevs.println(BOARD_NAME);
      BOT_TOKEN = BOT_TOKEN_InspectorBiblyka_bot;
      strDevs.printf_P(PSTR("InspectorBiblyka_bot !!!!!!!!!!!!WRONG CONFIG!!!!!!!!\n"));
  }
}



uint8_t devider;
int CUR_SIZE = 0;



struct DeviceProp {
  uint64_t mac64;
  uint16_t perform;
  uint16_t timeMark;
  uint16_t lastTimeMark;  // 
  bool state_init;
  bool state_curr;
  bool state_last;
  bool come_in;
  bool come_out;
  uint8_t index_wanted;
};


struct WantedDevice {
  uint64_t mac64;
  String friendName;
  uint8_t time_inactivity;  // minutes
  uint8_t main_channel;     // wifi channel (for router mode)
};




#if defined(ARDUINO_ARCH_ESP8266)
#define LIST_SIZE 10
#define KNOWN_SIZE 50
#elif defined(ARDUINO_ARCH_ESP32)
#define LIST_SIZE 200
#define KNOWN_SIZE 50
#endif


DeviceProp device[LIST_SIZE] = {
  { 0xC6F4FB9FBDF2, 1, 0xFFFF, 0xFFFF, true, true, true, true, true, 0 },
};


const WantedDevice wanted[KNOWN_SIZE] = {
  // MAC(reversed) AP Name        InAct  Chan
  { 0xAAAAAAAAAAAA, "unknown      ", 30, 00 },  // 0  By default!
  { 0xFFFFFFFFFFFF, "Broadcast    ", 01, 00 },  // 1

  { 0xBC0B582EB7DC, "POCO-Flint   ", 10, 00 },  // 2
  { 0xBC0B582EB7DC, "DELL-DEV     ", 06, 00 },  // 3

  { 0x2D880FED9CA8, "Redmi7-Inna  ", 10, 00 },  // 4
  { 0xD85B159B2CB6, "iPhoneStanis ", 10, 00 },  // 5
  { 0x4601E6C3876A, "iPad-Stanisl ", 10, 00 },  // 6

  //******************************************************
  { 0x23F823BFC750, "OOO Plinfa   ", 10, 12 },  // 7     router OOO Plinfa
  { 0x7F6A0BF469B8, "Guest-PLINFA ", 10, 9 },   // 8     router Guest-PLINFA
  { 0x5825FD76BEB0, "ASUS-FLINT   ", 10, 2 },   // 9     router ASUS-FLINT
  { 0xfa5c7951a378, "ZyXEL-FLINT  ", 06, 11 },  // 10    router ZyXEL-FLINT
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++
  { 0x20DDB0E69504, "Richard      ", 30, 07 },  // 11    router Richard
  { 0x86F136EDFE10, "TP-LINK_F186 ", 30, 01 },  // 12    router TP-LINK_36F186
  { 0xb08298f91684, "Kyivstar_82B0", 30, 06 },  // 13    router Kyivstar_82B0
  { 0x1a3cf576beb0, "Nosik        ", 30, 11 },  // 14    router Nosik
  { 0x4dcc593247ea, "HiddenSSID   ", 30, 10 },  // 15    router HiddenSSID
  { 0x4dcc593247d8, "borovsa      ", 30, 10 },  // 16    router borovsa
  { 0x4a34da4a9a90, "TP-LINK_344A ", 30,  7 },  // 17    router TP-LINK_344A Bokei
  { 0x54e43b94e834, "Roza         ", 30, 11 },  // 18    router Roza
  //******************************************************

  { 0xb8103c94e834, "Roza 1       ", 30,  2 },  // 19    client Roza 1
  { 0xe07058ca8b7c, "TP-LINK_70E0 ", 03, 01 },  // 20    client Guest-PLINFA
  { 0x05a0c81efe86, "Tanja-Iphone ", 02, 01 },  // 21    client Guest-PLINFA

  { 0x4d231134e4c0, "AzureWave Tec", 02, 01 },     // 22    client OOO PLINFA
  { 0xc09d0fdbf5f4, "Xiaomi Zarhin", 02, 01 },     // 23    client OOO PLINFA
  { 0x53f8e967ab60, "Xiaomi Maxim?", 02, 01 },     // 24    client OOO PLINFA
  { 0xf2203c44b32e, "E????thing?  ", 02, 01 },   // 25
  { 0xd195c5e350cc, "Sasha?       ", 02, 01 },     // 26

  { 0x53f8e967ab60, "Xiaomi thing?", 02, 01 },  // 27
  { 0x53f8e967ab60, "Xiaomi thing?", 02, 01 },  // 28
  { 0x53f8e967ab60, "Xiaomi thing?", 02, 01 },  // 29
  { 0x53f8e967ab60, "Xiaomi thing?", 02, 01 },  // 30


  { 0x88498b64298e, "Yulia mob 167", 27, 01 },  // 31    client TP-LINK_F186
  { 0x9a91d1472d5e, "Nastia mob167", 28, 01 },  // 32    client TP-LINK_F186
  { 0x93b0f626bb18, "Meloman 167  ", 44, 01 },  // 33    client TP-LINK_F186
  { 0xb8e6e9815a9c, "Nastia tab?  ", 02, 01 },  // 34    client TP-LINK_F186


  { 0x80f2931672a6, "Tania mob 168", 30, 01 },  // 35    client Kyivstar_82B0 0
  { 0x1d111ab8b884, "human 2 lt nt", 30, 01 },  // 36    client Kyivstar_82B0 2
  { 0x8361a71c511a, "human 3      ", 30, 01 },  // 37    client Kyivstar_82B0 1

  { 0x6d41c858051e, "human 1      ", 30, 99 },  // 38    client Richard
  { 0x60f65f269494, "human lowact ", 35, 99 },  // 39    client Richard
  { 0xfe8a8bb0a77c, "human 2      ", 35, 99 },  // 40    client Richard

  { 0x7a2ba2d0a460, "Sasha wife   ", 30, 99 },  // 41    client borovsa
  { 0xac80739b72dc, "Sasha 4 floor", 30, 99 },  // 42    client borovsa


  { 0x2c1ea9c91ca6, "OPPO-Inna    ", 05, 99 },  // 43    client ZyXEL-FLINT, ASUS-FLINT
  { 0x68cd18a7df24, "BestCon SCB1E", 05, 99 },  // 44    client ZyXEL-FLINT
  { 0xa52a660e6146, "iPad-Stanisla", 05, 99 },  // 45    client ZyXEL-FLINT, ASUS-FLINT
  { 0xff6e9b8bcb44, "qca-ioeboard ", 05, 99 },  // 46    client ZyXEL-FLINT, ASUS-FLINT    ÃÂºÃÂ¾ÃÂ½ÃÂ´ÃÂµÃÂ

  { 0xfc5c7951a378, "ZyXEL-FLINTro", 05, 99 },  // 47


  //   { {0xdc, 0x53, 0x60, 0x77, 0xad, 0xe4}, "Laptev      ",  3}, // 5
  //   { {0xe0, 0x1f, 0x88, 0x9c, 0x5a, 0xa6}, "Redmi8-Redmi", 20}, // 6
  //   { {0xd0, 0xab, 0xd5, 0x38, 0xff, 0x13}, "DESKTOP-T4U2",  6}, // 12


};



bool insert_client(uint64_t mac64) {

  if (CUR_SIZE >= LIST_SIZE) return false;

  uint16_t now = millis() / 1000 / 60;  // minutes

  itm = mymap.find(mac64);

  const bool found = itm != mymap.end();
  if (found) {

    int i = itm->second;

    device[i].perform += 1;
    device[i].timeMark = now;

  } else {

    mymap[mac64] = CUR_SIZE;

    device[CUR_SIZE].perform = 1;

    device[CUR_SIZE].index_wanted = KNOWN_ROUTER;
    for (int w = 0; w < KNOWN_SIZE; w++) {
      if (mac64 == wanted[w].mac64) {
        device[CUR_SIZE].index_wanted = w;
        break;
      }
    }

    device[CUR_SIZE].timeMark = now;

    Serial.printf("\n[%d]-%s ... %s\n", CUR_SIZE, printMac64(mac64).c_str(),
                  wanted[device[CUR_SIZE].index_wanted].friendName.c_str());

    if (CUR_SIZE < LIST_SIZE) CUR_SIZE += 1;
  }

  return found;
}



void check_activity(bool add_header, bool add_body) {

  uint16_t now = millis() / 1000 / 60;  // minutes

  strHead.begin();
  if (add_header && !strDevs.length()) {

    strHead.printf("%2d] %s @ %s CH%d\n", CUR_SIZE, BOARD_NAME.c_str(),
                   wanted[KNOWN_ROUTER].friendName.c_str(),
                   wanted[KNOWN_ROUTER].main_channel);
#ifdef PUBLISH_DEBUG
    Serial.print(strHead); // SerialBT.print(strHead); 
#endif
  }

  strBody.begin();
  for (itm = mymap.begin(); itm != mymap.end(); ++itm) {

    uint64_t mac = itm->first;
    int i = itm->second;

    device[i].state_last = device[i].state_curr;  // save last state

    uint16_t curr_timeout = now - device[i].timeMark;                       // minutes
    uint16_t dev_timeout = wanted[device[i].index_wanted].time_inactivity;  // minutes

    if (curr_timeout >= dev_timeout) {
      device[i].state_curr = 0;
    } else {
      device[i].state_curr = 1;
    }

    // if state chages
    if (device[i].state_last == 0 && device[i].state_curr == 1) {
      device[i].come_in = 1;  // appeared back
      device[i].come_out = 0;
      curr_timeout = now - device[i].lastTimeMark;  // Restore last curr_timeout
    } else if (device[i].state_last == 1 && device[i].state_curr == 0) {
      device[i].come_out = 1;  // gone off
      device[i].come_in = 0;
      device[i].lastTimeMark = device[i].timeMark;  // ÃÂÃÂ¸ÃÂºÃÂÃÂ¸ÃÂÃÂÃÂµÃÂ¼ ÃÂ¼ÃÂµÃÂÃÂºÃÂ ÃÂ¸ÃÂÃÂÃÂµÃÂ·ÃÂ½ÃÂ¾ÃÂ²ÃÂµÃÂ½ÃÂ¸ ÃÂÃÂÃÂÃÂÃÂ¾ÃÂ¹ÃÂÃÂÃÂ²ÃÂ°
    }

    if (add_body) {

      strTemp.begin();
      strTemp.printf("%2d: %s", i, printMac64s(mac).c_str());

      strTemp.printf(" [%04d] %04d ",
                     device[i].perform,
                     now);

      String in_out = "*";
      if (device[i].come_in) in_out = ">0";  // in
      else if (device[i].come_out)
        in_out = "0>";  // out

      strTemp.printf("(%02d/%02d) %s %s",
                     curr_timeout,
                     dev_timeout,
                     in_out.c_str(),
                     wanted[device[i].index_wanted].friendName.c_str());

#ifdef PUBLISH_DEBUG
      Serial.print(strTemp); // SerialBT.print(strTemp); 
     
#endif
      strTemp += "\n";

      // Include only interesting activity
      if (device[i].come_in || device[i].come_out || (device[i].perform > 1000)) {

        // Reset after saving
        device[i].come_in = 0;
        device[i].come_out = 0;
        device[i].perform = 0;

        Serial.println(" " + in_out);
        strBody += strTemp;
      } else {
        Serial.println();
      }
    }
  }  // for

  if (strBody.length()) {  // reset string with summary while no activity

    strDevs += strHead;
    strDevs += strBody;
    Serial.printf("\n--------len/cap (%d/%d)\n", strDevs.length(), strDevs.capacity());
    // SerialBT.printf("***\n");
    
  }
}



void reset_activity() {

  for (itm = mymap.begin(); itm != mymap.end(); ++itm) {

    uint64_t mac = itm->first;
    int i = itm->second;

  //   uint16_t curr_timeout = millis() / 1000 / 60 - device[i].timeMark;      // minutes
  //   uint16_t dev_timeout = wanted[device[i].index_wanted].time_inactivity;  // minutes

  //   //if ( curr_timeout > dev_timeout ) {

    // reset counter and markers
    device[i].perform = 0;
  //   //}
  //   //else {

  //   //}

  //   //device[i].come_in = 0;
  //   //device[i].come_out = 0;
  }
}



void print_map(bool all, bool with_header) {  //

  strDevs.begin();
  bool do_print = false;

  uint16_t now = millis() / 1000 / 60;  // minutes

  /*
3] ESP_C02AE8 - EC:FA:BC:C0:2A:E8 @ 0005 by OOO Plinfa    CH12
  1: e2:0b:37:ba:b1:36 [00139] > 1|1 + (00/10) OOO Plinfa   
  0: f4:f5:db:0f:9d:c0 [00119] > 1|1 + (00/10) OOO Plinfa   
  2: cc:50:e3:c5:95:d1 [00310] > 1|1 + (00/10) OOO Plinfa
*/

  if (with_header) {

    // String hostname = "noname";

    // #if defined(ARDUINO_ARCH_ESP8266)
    //     hostname = WiFi.hostname() + " - " + WiFi.macAddress();
    // #elif defined(ARDUINO_ARCH_ESP32)
    //     hostname = WiFi.getHostname();
    // #endif

    // strDevs.printf("%2d] %s @ %04d by %s CH%d\n", CUR_SIZE, hostname.c_str(),
    //               millis() / 1000 / 60, wanted[KNOWN_ROUTER].friendName.c_str(),
    //               wanted[KNOWN_ROUTER].main_channel );
    strDevs.printf("%2d] %s %d, @ %s CH%d\n", CUR_SIZE, BOARD_NAME.c_str(), now,
                   wanted[KNOWN_ROUTER].friendName.c_str(),
                   wanted[KNOWN_ROUTER].main_channel);
  }

  for (itm = mymap.begin(); itm != mymap.end(); ++itm) {
    bool for_print = false;

    uint64_t mac = itm->first;
    int i = itm->second;

    if (not all) {
      if (device[i].come_in || device[i].come_out || (device[i].perform > 500)) {
        for_print = true;
        do_print = true;
      }
    } else {
      for_print = true;
      do_print = true;
    }

    if (for_print) {

      // strDevs.printf("%3d: %s", i, printMac64(mac).c_str());

      // String in_out = "*";   // in
      // if ( device[i].come_in ) {
      //   in_out = "+";
      // }
      // else if ( device[i].come_out ) {
      //   in_out = "-";
      // }
      // strDevs.printf(" [%04d] > %d|%d %s ",
      //               device[i].perform,
      //               device[i].state_last,
      //               device[i].state_curr,
      //               in_out.c_str()
      //               );

      // uint16_t curr_timeout = millis() / 1000 / 60 - device[i].timeMark;      // minutes
      // uint16_t dev_timeout = wanted[device[i].index_wanted].time_inactivity;  // minutes

      // strDevs.printf("(%02d/%02d) %s\n",
      //               curr_timeout,
      //               dev_timeout,
      //               wanted[device[i].index_wanted].friendName.c_str()
      //               );
      uint16_t curr_timeout = now - device[i].timeMark;                       // minutes
      uint16_t dev_timeout = wanted[device[i].index_wanted].time_inactivity;  // minutes


      strDevs.printf("%2d: %s", i, printMac64(mac).c_str());

      strDevs.printf(" [%04d] ",
                     device[i].perform);

      String in_out = "Ã¢ÂÂ¢";
      if (device[i].come_in) in_out = "+";  // in
      else if (device[i].come_out)
        in_out = "Ã¢ÂÂ";  // out

      strDevs.printf("(%02d/%02d) %s %s\n",
                     curr_timeout,
                     dev_timeout,
                     in_out.c_str(),
                     wanted[device[i].index_wanted].friendName.c_str());
    }
  }

  if (not do_print) strDevs.begin();  // reset string with summary while no activity
}



String printMac64(uint64_t mac) {

  char smac64[17 + 1];

  byte b1 = (mac)&0xFF;
  byte b2 = (mac >> 8) & 0xFF;
  byte b3 = (mac >> 16) & 0xFF;
  byte b4 = (mac >> 24) & 0xFF;
  byte b5 = (mac >> 32) & 0xFF;
  byte b6 = (mac >> 40) & 0xFF;
  snprintf(smac64, sizeof(smac64), "%02x:%02x:%02x:%02x:%02x:%02x", b1, b2, b3, b4, b5, b6);

  return String(smac64);
}



String printMac64s(uint64_t mac) {

  char smac64s[6 + 1];

  byte b1 = (mac)&0xFF;
  byte b6 = (mac >> 40) & 0xFF;
  snprintf(smac64s, sizeof(smac64s), "%02x..%02x", b1, b6);

  return String(smac64s);
}



#endif  // _MY_DEVICE_H    // Put this line at the end of your file.