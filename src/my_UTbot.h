#pragma once
#ifndef _MY_UTBOT_H    // Put these two lines at the top of your file.
#define _MY_UTBOT_H    // (Use a suitable name, usually based on the file name.)

//unmark following line to enable debug mode
//#define _debug


#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);


String Flint_CHAT_ID = "442763659";  



void setup_UTbot(String strBot)
{
  // UniversalTelegramBot 
  bot.updateToken(BOT_TOKEN);

  Serial.println("Init Universal TelegramBot...");
 
  #if defined(ARDUINO_ARCH_ESP8266)
    X509List cert(TELEGRAM_CERTIFICATE_ROOT);
    secured_client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  #elif defined(ARDUINO_ARCH_ESP32)
    secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  #endif
  
  //const uint8_t fingerprint[20] = { 0xBB, 0xDC, 0x45, 0x2A, 0x07, 0xE3, 0x4A, 0x71, 0x33, 0x40, 0x32, 0xDA, 0xBE, 0x81, 0xF7, 0x72, 0x6F, 0x4A, 0x2B, 0x6B };
  //secured_client.setFingerprint(fingerprint);

  secured_client.setInsecure();

  Serial.println(bot.sendMessage(Flint_CHAT_ID, strBot) );
}


// String kbdStatus = "[ [\"/status\", \"/list\"], [\"/sniff\", \"/UTbot\"], [\"/sensors\", \"/blablabla\"] ]";
static const char kbdStatus[] PROGMEM  = "[ [\"/status\", \"/list\"], [\"/sniff\", \"/UTbot\"], [\"/sensors\", \"/blablabla\"] ]";

String kbdSensors = "[ [\"/initSensors\", \"/getSensors\"], [\"/back\", \"/opt\"] ]";
String kbdOpt = "[[\"/list\", \"/UTbot\"], [\"/sniff\"] ]";

//String keyboardJson = "[[{ \"text\" : \"Go to Google\", \"url\" : \"https://www.google.com\" }],[{ \"text\" : \"Send\", \"callback_data\" : \"This was sent by inline\" }]]";
String keyboardJson = "[[{ \"text\" : \"/initSensors\", \"callback_data\" : \"/initSensors\" }],[{ \"text\" : \"/getSensors\", \"callback_data\" : \"/getSensors\" }]]";







#endif // _MY_UTBOT_H    // Put this line at the end of your file.
