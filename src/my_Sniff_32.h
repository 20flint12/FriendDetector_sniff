#pragma once
#ifndef _MY_SNIFF_32_H    // Put these two lines at the top of your file.
#define _MY_SNIFF_32_H    // (Use a suitable name, usually based on the file name.)


//https://github.com/espressif/esp-idf/blob/c13afea/components/esp_wifi/include/esp_wifi_types.h
// https://www.oreilly.com/library/view/80211-wireless-networks/0596100523/ch04.html



#include "esp_wifi.h"
#include "esp_wifi_types.h"
#include "esp_system.h"
#include "esp_event.h"
// #include "esp_event_loop.h"
// #include "esp_event.h"

#include "nvs_flash.h"


#define WIFI_CHANNEL_SWITCH_INTERVAL  (500)
#define WIFI_CHANNEL_MAX               (13)

uint8_t level = 0, channel = 1;

static wifi_country_t wifi_country = {.cc="CN", .schan = 1, .nchan = 13}; //Most recent esp32 library struct

typedef struct {
  unsigned frame_ctrl:16;
  unsigned duration_id:16;
  uint8_t addr1[6]; /* receiver address */
  uint8_t addr2[6]; /* sender address */
  uint8_t addr3[6]; /* filtering address */
  unsigned sequence_ctrl:16;
  uint8_t addr4[6]; /* optional */
} wifi_ieee80211_mac_hdr_t;

typedef struct {
  wifi_ieee80211_mac_hdr_t hdr;
  uint8_t payload[0]; /* network data ended with 4 bytes csum (CRC32) */
} wifi_ieee80211_packet_t;

static esp_err_t event_handler(void *ctx, system_event_t *event);
static void wifi_sniffer_init(void);
static void wifi_station_init(void);
static void wifi_sniffer_set_channel(uint8_t channel);
static const char *wifi_sniffer_packet_type2str(wifi_promiscuous_pkt_type_t type);
static void wifi_sniffer_packet_handler(void *buff, wifi_promiscuous_pkt_type_t type);


esp_err_t event_handler(void *ctx, system_event_t *event) {
  
  return ESP_OK;
}


void wifi_sniffer_init(void) {

  esp_wifi_disconnect();
  esp_wifi_set_mode(WIFI_MODE_STA);
  esp_wifi_set_promiscuous(false);
  
  esp_wifi_disconnect();  
  esp_wifi_set_promiscuous_rx_cb(&wifi_sniffer_packet_handler);
  esp_wifi_set_promiscuous(true);
  
}


void wifi_station_init(void) {

  esp_wifi_disconnect();
  esp_wifi_set_promiscuous(false);

  esp_wifi_disconnect();  
  esp_wifi_set_mode(WIFI_MODE_STA);

}


void wifi_sniffer_set_channel(uint8_t channel) {
  
  esp_wifi_set_channel(channel, WIFI_SECOND_CHAN_NONE);
}


const char * wifi_sniffer_packet_type2str(wifi_promiscuous_pkt_type_t type) {
  
  switch(type) {
    case WIFI_PKT_MGMT: return "MGMT";
    case WIFI_PKT_DATA: return "DATA";
    case WIFI_PKT_CTRL: return "CTRL";
  default:  
    case WIFI_PKT_MISC: return "MISC";
  }
}


void wifi_sniffer_packet_handler(void* buff, wifi_promiscuous_pkt_type_t type) {
  

//  if (type != WIFI_PKT_MGMT)
//    return;


  const wifi_promiscuous_pkt_t *ppkt = (wifi_promiscuous_pkt_t *)buff;
  const wifi_ieee80211_packet_t *ipkt = (wifi_ieee80211_packet_t *)ppkt->payload;
  const wifi_ieee80211_mac_hdr_t *hdr = &ipkt->hdr;

  // Serial.print("+");

  
  uint64_t mac64_1 = 0;
  uint64_t mac64_2 = 0;
  uint64_t mac64_3 = 0;
  memcpy(&mac64_1, (uint64_t*)hdr->addr1, 6);
  memcpy(&mac64_2, (uint64_t*)hdr->addr2, 6);
  memcpy(&mac64_3, (uint64_t*)hdr->addr3, 6);
  
  uint64_t mac64_want = wanted[KNOWN_ROUTER].mac64;

  bool from_DS = bitRead(hdr->frame_ctrl, 6);
  bool to_DS = bitRead(hdr->frame_ctrl, 7);

  // if ( from_DS && (mac64_2 == mac64_want) ) {

  //   Serial.print(mac64_1, 16);
  //   insert_device((uint8_t*)hdr->addr1, (char*)"addr1", 5, false);
  // }

  if ( !from_DS && to_DS && (mac64_1 == mac64_want) ) {   

    digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)


#ifdef PUBLISH_DEBUG
    Serial.printf("%02x", mac64_2 & 0xFF);
#endif
    insert_client(mac64_2);
    
    // byte b1 = (mac64_2    )&0xFF;
    // byte b2 = (mac64_2>> 8)&0xFF;
    // byte b3 = (mac64_2>>16)&0xFF;
    // byte b4 = (mac64_2>>24)&0xFF;
    // byte b5 = (mac64_2>>32)&0xFF;
    // byte b6 = (mac64_2>>40)&0xFF;
    // Serial.printf(">>> %02x:%02x:%02x:%02x:%02x:%02x - %03d\n", b1, b2, b3, b4, b5, b6, CUR_SIZE);
  }

  //myset.insert (ppkt->rx_ctrl.channel);  
  
  
  // for (it=myset.begin(); it!=myset.end(); ++it) {

  //   Serial.print("+");
  //   Serial.print(*it);
  // }

 

  // if ( (mac64_1 == mac64_want) || (mac64_2 == mac64_want) || (mac64_3 == mac64_want) || false ) {
  // if ( !from_DS && to_DS && (mac64_1 == mac64_want)  ) {
  if ( false ) {

    // printf(" %s | %02d | %02d |"
    //   " %04x:%d:%d | %03d |"
    //   " %05d-%d |"
    //   " %02x:%02x:%02x:%02x:%02x:%02x,"
    //   " %02x:%02x:%02x:%02x:%02x:%02x,"
    //   " %02x:%02x:%02x:%02x:%02x:%02x\n",
    //   wifi_sniffer_packet_type2str(type), ppkt->rx_ctrl.channel,ppkt->rx_ctrl.rssi,
      
    //   hdr->frame_ctrl, to_DS, from_DS,  hdr->duration_id,
    
    //   hdr->sequence_ctrl>>4, hdr->sequence_ctrl&0xF,
      
    //   /* ADDR1 */
    //   hdr->addr1[0],hdr->addr1[1],hdr->addr1[2],
    //   hdr->addr1[3],hdr->addr1[4],hdr->addr1[5],
    //   /* ADDR2 */
    //   hdr->addr2[0],hdr->addr2[1],hdr->addr2[2],
    //   hdr->addr2[3],hdr->addr2[4],hdr->addr2[5],
    //   /* ADDR3 */
    //   hdr->addr3[0],hdr->addr3[1],hdr->addr3[2],
    //   hdr->addr3[3],hdr->addr3[4],hdr->addr3[5]
    // );
    
    printf(" %s | %02d | %02d |"
      "%d:%d |"
      " %02x:%02x:%02x:%02x:%02x:%02x,"
      " %02x:%02x:%02x:%02x:%02x:%02x,"
      " %02x:%02x:%02x:%02x:%02x:%02x\n",
      wifi_sniffer_packet_type2str(type), ppkt->rx_ctrl.channel,ppkt->rx_ctrl.rssi,
      
      from_DS, to_DS,
    
      /* ADDR1 */
      hdr->addr1[0],hdr->addr1[1],hdr->addr1[2],
      hdr->addr1[3],hdr->addr1[4],hdr->addr1[5],
      /* ADDR2 */
      hdr->addr2[0],hdr->addr2[1],hdr->addr2[2],
      hdr->addr2[3],hdr->addr2[4],hdr->addr2[5],
      /* ADDR3 */
      hdr->addr3[0],hdr->addr3[1],hdr->addr3[2],
      hdr->addr3[3],hdr->addr3[4],hdr->addr3[5]
    );

    

//    insert_device((uint8_t*)hdr->addr1, (char*)"addr1", 5, false);
//    insert_device((uint8_t*)hdr->addr2, (char*)"addr2", 5, false);
//    insert_device((uint8_t*)hdr->addr3, (char*)"addr3", 5, false);

  }

  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by ma

}



#endif // _MY_SNIFF_32_H    // Put this line at the end of your file.
