#include <ArduinoJson.h>

/*
    Video: https://www.youtube.com/watch?v=oCMOYS71NIU
    Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleNotify.cpp
    Ported to Arduino ESP32 by Evandro Copercini
    updated by chegewara

   Create a BLE server that, once we receive a connection, will send periodic notifications.
   The service advertises itself as: 4fafc201-1fb5-459e-8fcc-c5c9c331914b
   And has a characteristic of: beb5483e-36e1-4688-b7f5-ea07361b26a8

   The design of creating the BLE server is:
   1. Create a BLE Server
   2. Create a BLE Service
   3. Create a BLE Characteristic on the Service
   4. Create a BLE Descriptor on the characteristic
   5. Start the service.
   6. Start advertising.

   A connect hander associated with the server starts a background task that performs notification
   every couple of seconds.
*/

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

BLEServer* pServer = NULL;
BLECharacteristic* pTxCharacteristic = NULL;
// BLECharacteristic* pRxCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint32_t value = 0;

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

// #define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
// #define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"



void send2Ble(String mess);


class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      BLEDevice::startAdvertising();
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};


class RxCharacteristicCallbacks: public BLECharacteristicCallbacks {
    
    void onWrite(BLECharacteristic *pCharacteristic)
    {
      std::string rxValue = pCharacteristic->getValue();
      // Serial.print("value received = ");
      // Serial.println(rxValue.c_str());
  
      if (rxValue.length() > 0) 
        str_BLE_received = rxValue.c_str();

      recharge_taskBleReceived();
    }
};


void setup_BLE_multi() {
 
  // Create the BLE Device
  BLEDevice::init("ESP49");

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());



  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // // Create a BLE TxCharacteristic
  // pTxCharacteristic = pService->createCharacteristic(
  //                     CHARACTERISTIC_UUID_TX,
  //                     BLECharacteristic::PROPERTY_READ |
  //                     BLECharacteristic::PROPERTY_WRITE |
  //                     BLECharacteristic::PROPERTY_NOTIFY //|
  //                   //   BLECharacteristic::PROPERTY_INDICATE
  //                   );
  // pTxCharacteristic->setCallbacks(new RxCharacteristicCallbacks());


  // Create a BLE TxCharacteristic
  pTxCharacteristic = pService->createCharacteristic(
										  CHARACTERISTIC_UUID_TX,
                      // BLECharacteristic::PROPERTY_READ |
                      // BLECharacteristic::PROPERTY_WRITE |
                      BLECharacteristic::PROPERTY_NOTIFY //|
                      // BLECharacteristic::PROPERTY_INDICATE
									  );
  pTxCharacteristic->addDescriptor(new BLE2902());

  BLECharacteristic * pRxCharacteristic = pService->createCharacteristic(
											CHARACTERISTIC_UUID_RX,
											BLECharacteristic::PROPERTY_WRITE
										);
  pRxCharacteristic->setCallbacks(new RxCharacteristicCallbacks());






  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
  // Create a BLE Descriptor
  // pTxCharacteristic->addDescriptor(new BLE2902());

  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Waiting a client connection to notify...");

//   // Start the service
//   pService->start();

//   // Start advertising
//   pServer->getAdvertising()->start();
//   Serial.println("Waiting a client connection to notify...");

}


void loop_BLE_multi() {
    // notify changed value
    if (deviceConnected) {

        DynamicJsonDocument doc(20);

        int measurement = hallRead();
        doc["AABBCCDDEE"] = measurement; //millis()/1000;
        JsonObject obj = doc.as<JsonObject>();

        String strMess;
        serializeJson(obj, strMess);

        pTxCharacteristic->setValue((uint8_t*)strMess.c_str(), strMess.length());
        // pTxCharacteristic->setValue((uint8_t*)json_string.c_str(), json_string.length());
      
        pTxCharacteristic->notify();
        // value++;
        delay(900); // bluetooth stack will go into congestion, if too many packets are sent, in 6 hours test i was able to go as low as 3ms
    }
    // disconnecting
    if (!deviceConnected && oldDeviceConnected) {
        delay(500); // give the bluetooth stack the chance to get things ready
        pServer->startAdvertising(); // restart advertising
        Serial.println("start advertising");
        oldDeviceConnected = deviceConnected;
    }
    // connecting
    if (deviceConnected && !oldDeviceConnected) {
        // do stuff here on connecting
        oldDeviceConnected = deviceConnected;
    }
}


void send2Ble(String mess)
{
    Serial.println(mess);
    pTxCharacteristic->setValue((uint8_t*)mess.c_str(), mess.length());
    pTxCharacteristic->notify();
}


/*
const char* keys[] = {
    "pin_0",
    "pin_1",
    "pin_2",
    "pin_3",
    // up to NUMBER_OF_OUTPUTS
};

for (int i = 0; i < NUMBER_OF_OUTPUTS; i++) {   
    root.set(keys[i], i);
}
*/
