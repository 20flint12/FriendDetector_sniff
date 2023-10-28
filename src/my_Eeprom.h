struct ConfigStore {
  uint32_t  magic;
  // uint8_t   flags;

  char      wifiSSID[34];
  char      wifiPass[64];

  uint8_t   channel_sniff;
  uint64_t  router_mac;

  // char      cloudToken[34];
  // char      cloudHost[34];
  // uint16_t  cloudPort;

  // uint32_t  staticIP;
  // uint32_t  staticMask;
  // uint32_t  staticGW;
  // uint32_t  staticDNS;
  // uint32_t  staticDNS2;

  // int       last_error;

  // void setFlag(uint8_t mask, bool value) {
  //   if (value) {
  //     flags |= mask;
  //   } else {
  //     flags &= ~mask;
  //   }
  // }

  // bool getFlag(uint8_t mask) {
  //   return (flags & mask) == mask;
  // }
} __attribute__((packed));


const ConfigStore configDefault = {
  0x626C6E6B,
  // 0x00,
  
  "",
  "",

  11,
  0xAABBCCDDEEFF,


  // "invalid token",
  // CONFIG_DEFAULT_SERVER,
  // CONFIG_DEFAULT_PORT,
  // 0,
  // BLYNK_PROV_ERR_NONE
};




ConfigStore configStore;  



#include <EEPROM.h>
#define EEPROM_CONFIG_START 0

void config_load()
{
  memset(&configStore, 0, sizeof(configStore));
  EEPROM.get(EEPROM_CONFIG_START, configStore);
  if (configStore.magic != configDefault.magic) {
    DEBUG_PRINT("Using default config.");
    configStore = configDefault;
    return;
  }
}

bool config_save()
{
  EEPROM.put(EEPROM_CONFIG_START, configStore);
  EEPROM.commit();
  DEBUG_PRINT("Configuration stored to flash");
  return true;
}

bool config_init()
{
  EEPROM.begin(sizeof(ConfigStore));
  config_load();
  return true;
}
 
void enterResetConfig()
{
  DEBUG_PRINT("Resetting configuration!");
  // configStore = configDefault;
  // config_save();
  // BlynkState::set(MODE_WAIT_CONFIG);
}

// void config_set_last_error(int error) {
//   // Only set error if not provisioned
//   if (!configStore.getFlag(CONFIG_FLAG_VALID)) {
//     configStore = configDefault;
//     configStore.last_error = error;
//     BLYNK_LOG2("Last error code: ", error);
//     config_save();
//   }
// }
 