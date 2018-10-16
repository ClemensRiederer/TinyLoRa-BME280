#include <ATtinyLoRa.h>
#include <SPI.h>

// use your keys from TTN
uint8_t NwkSkey[16] = { 0xB3, 0xCD, 0x30, 0x2F, 0x0D, 0x8F, 0x24, 0xCD, 0x28, 0xEE, 0x8D, 0x28, 0x36, 0x75, 0x03, 0x6F };
uint8_t AppSkey[16] = { 0x1D, 0x85, 0x94, 0xD5, 0x14, 0xB9, 0xF7, 0x87, 0x9A, 0x28, 0xDB, 0x6F, 0xCC, 0x95, 0x2A, 0x6F };
uint8_t DevAddr[4] = { 0x26, 0x02, 0x1E, 0x91 };

// Data packet to send
unsigned char loraData[5] = {0x00, 0x01, 0x02, 0x03, 0x04};

// Global LoRaWan object
TinyLoRa lora;

void setup()
{
  delay(3000);
  while (! Serial);
  Serial.begin(9600);
  Serial.println("Starting SPI...");
  SPI.begin();
   
  
  // init LoRa
  Serial.println("Starting LoRa...");
  lora.begin();
}

void loop()
{
  Serial.println("Sending LoRa Data...");
  lora.sendData(loraData, sizeof(loraData), lora.frameCounter);
  Serial.println("incrementing LoRa framecounter...");
  lora.frameCounter++;
  Serial.println("delaying...");
  delay(10000);
}