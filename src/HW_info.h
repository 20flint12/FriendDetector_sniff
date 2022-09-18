#pragma once
#ifndef _HW_INFO_H    // Put these two lines at the top of your file.
#define _HW_INFO_H    // (Use a suitable name, usually based on the file name.)


#define PUBLISH_DEBUG






char charDevs[1100] = "";
PString strDevs(charDevs, sizeof(charDevs));

char charHead[100] = "";
PString strHead(charHead, sizeof(charHead));

char charTemp[100] = "";
PString strTemp(charTemp, sizeof(charTemp));

char charBody[1000] = "";
PString strBody(charBody, sizeof(charBody));



#if defined(ARDUINO_ARCH_ESP8266)

//...

#elif defined(ARDUINO_ARCH_ESP32)

#include <rom/rtc.h>

void print_reset_reason(RESET_REASON reason) {
  
  switch ( reason)
  {
    case 1  : strDevs.printf_P(PSTR("POWERON_RESET"));break;          /**<1, Vbat power on reset*/
    case 3  : strDevs.printf_P(PSTR("SW_RESET"));break;               /**<3, Software reset digital core*/
    case 4  : strDevs.printf_P(PSTR("OWDT_RESET"));break;             /**<4, Legacy watch dog reset digital core*/
    case 5  : strDevs.printf_P(PSTR("DEEPSLEEP_RESET"));break;        /**<5, Deep Sleep reset digital core*/
    case 6  : strDevs.printf_P(PSTR("SDIO_RESET"));break;             /**<6, Reset by SLC module, reset digital core*/
    case 7  : strDevs.printf_P(PSTR("TG0WDT_SYS_RESET"));break;       /**<7, Timer Group0 Watch dog reset digital core*/
    case 8  : strDevs.printf_P(PSTR("TG1WDT_SYS_RESET"));break;       /**<8, Timer Group1 Watch dog reset digital core*/
    case 9  : strDevs.printf_P(PSTR("RTCWDT_SYS_RESET"));break;       /**<9, RTC Watch dog Reset digital core*/
    case 10 : strDevs.printf_P(PSTR("INTRUSION_RESET"));break;       /**<10, Instrusion tested to reset CPU*/
    case 11 : strDevs.printf_P(PSTR("TGWDT_CPU_RESET"));break;       /**<11, Time Group reset CPU*/
    case 12 : strDevs.printf_P(PSTR("SW_CPU_RESET"));break;          /**<12, Software reset CPU*/
    case 13 : strDevs.printf_P(PSTR("RTCWDT_CPU_RESET"));break;      /**<13, RTC Watch dog Reset CPU*/
    case 14 : strDevs.printf_P(PSTR("EXT_CPU_RESET"));break;         /**<14, for APP CPU, reseted by PRO CPU*/
    case 15 : strDevs.printf_P(PSTR("RTCWDT_BROWN_OUT_RESET"));break;/**<15, Reset when the vdd voltage is not stable*/
    case 16 : strDevs.printf_P(PSTR("RTCWDT_RTC_RESET"));break;      /**<16, RTC Watch dog reset digital core and rtc module*/
    default : strDevs.printf_P(PSTR("NO_MEAN"));
  }
}

#endif




uint32_t print_hw_info(String file_name, bool full) {
  
  uint32_t chip_id = 0xFFFFFFFF;
  
  strDevs.begin();

  strDevs.print("\n\n=== " + file_name + " ===\n");

#if defined(ARDUINO_ARCH_ESP8266)
/*
*/

// https://arduino-esp8266.readthedocs.io/en/latest/libraries.html#softwareserial
/*
=== /tmp/751300499/FriendDetector32/FriendDetector32.ino ===
CPU reset reason:  External System

=== Hardware info ===
CoreVersion: 2_5_0; SdkVersion: 3.0.0-dev(c0f7b44)
ChipId: 0xC02AE8, FlashChipId: 0x164020
4/4MB by chipId size 0 flash
ESP.getBootMode(): 1
ESP.getBootVersion(): 31
ESP.getFreeHeap() 31736
*/
  strDevs.printf("CPU reset reason:  %s\n", ESP.getResetReason().c_str());  


  strDevs.printf_P(PSTR("\n=== Hardware info ===\n"));
  strDevs.printf_P(PSTR("CoreVersion: %s; SdkVersion: %s\n"), ESP.getCoreVersion().c_str(), ESP.getSdkVersion());   
  chip_id = ESP.getChipId();
  strDevs.printf_P(PSTR("Chip Id: 0x%X, FlashChipId: 0x%X\n"), chip_id, ESP.getFlashChipId());   
  strDevs.printf_P(PSTR("%d/%dMB by chipId size %d flash\n"), ESP.getFlashChipSize()/(1024*1024), 
                                                      ESP.getFlashChipRealSize()/(1024*1024),
                                                      ESP.getFlashChipSizeByChipId()/(1024*1024) );
  
  /*
7 SDIO HighSpeed V2 IO Uart1 Booting
6 SDIO LowSpeed V1 IO Uart1 Booting
5 SDIO HighSpeed V1 IO Uart1 Booting
4 SDIO LowSpeed V2 IO Uart1 Booting
3 FLASH BOOT
2 Jump Boot
1 UART Boot
0 Remapping
*/
  strDevs.print("ESP.getBootMode(): ");
  strDevs.println(ESP.getBootMode());
  strDevs.print("ESP.getBootVersion(): ");
  strDevs.println(ESP.getBootVersion());
  strDevs.print("ESP.getFreeHeap() ");
  strDevs.println(ESP.getFreeHeap());
  // heap = ESP.getFreeHeap();


#elif defined(ARDUINO_ARCH_ESP32)
// https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/system.html?highlight=esp_chip_info_t#app-version
/*
=== /tmp/332180717/FriendDetector32/FriendDetector32.ino ===
CPU0 reset reason: POWERON_RESET
CPU1 reset reason: EXT_CPU_RESET

=== Hardware info ===
2 cores Wifi /BT/BLE
Silicon revision: 1
4MB external flash
Chip id: A9F23A08

::: 

*/
  strDevs.printf_P(PSTR("\nCPU0 reset reason: "));
  print_reset_reason(rtc_get_reset_reason(0));

  strDevs.printf_P(PSTR("\nCPU1 reset reason: "));
  print_reset_reason(rtc_get_reset_reason(1));



  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
   
  strDevs.println("\n=== Hardware info ===");
  strDevs.printf("%d cores Wifi %s%s\n", chip_info.cores, (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
  (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
  strDevs.printf("Silicon revision: %d\n", chip_info.revision);
  strDevs.printf("%dMB %s flash\n", spi_flash_get_chip_size()/(1024*1024),
  (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embeded" : "external");

  chip_id = ESP.getEfuseMac();  //get chip id
  strDevs.printf("~Chip Id: %X\n", chip_id);


  for(int i=0; i<17; i=i+8) {
	  chip_id |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
  }
	strDevs.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
	strDevs.printf("This chip has %d cores\n", ESP.getChipCores());
  strDevs.print("Chip ID: "); strDevs.println(chip_id, 16);
  



#endif


  //       strBot.printf("pulseRnd = %d\n", int(pulseRnd));
  //       strBot.printf("pulseBot = %d\n", int(pulseBot));
  //       strBot.printf("notifyRnd = %d\n", int(notifyRnd));
  //       strBot.printf("P %s; \t\t", publishSinglePulse());
  //       strBot.printf("R %s\n", publishPulseMode());



  return chip_id;
}


void publish_strDevs_clear(void) {

    Serial.printf("\nlen/cap (%d/%d)\n", strDevs.length(), strDevs.capacity() );
    Serial.println(String(strDevs));
    strDevs.begin();
}


void strDevs_publish_clear(bool publish, bool clear) {

    if ( publish ) {
      
      Serial.printf("\nlen/cap (%d/%d)\n", strDevs.length(), strDevs.capacity() );
      Serial.println(String(strDevs));
    }
    
    if ( clear ) {
    
      strDevs.begin();
    }
    
}



#endif // _HW_INFO_H    // Put this line at the end of your file.
