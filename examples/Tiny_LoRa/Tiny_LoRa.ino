#include <ATtinyLoRa.h>
#include <SPI.h>

// use your keys from TTN
uint8_t NwkSkey[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t AppSkey[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t DevAddr[4] = { 0x00, 0x00, 0x00, 0x00 };

// Data packet to send
unsigned char loraData[5] = {0x00, 0x01, 0x02, 0x03, 0x04};

// Global LoRaWan object
TinyLoRa lora;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting SPI...");
  SPI.begin();
   
  // set slave select pins from RFM95 as an output
  DDRB |= (1 << NSS_RFM);
  // set RFM95 DIO0 as Input
  DDRB &= ~(1 << DIO0);
  // set NSS_RFM high
  PORTB |= (1 << NSS_RFM);
  
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
