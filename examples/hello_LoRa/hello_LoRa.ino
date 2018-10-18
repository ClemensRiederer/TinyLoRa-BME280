// Hello LoRa - ABP TTN Packet Sender
// Tutorial Link: https://learn.adafruit.com/the-things-network-for-feather/using-a-feather-32u4
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Brent Rubell for Adafruit Industries
// Copyright 2018 Adafruit Industries
// Copyright 2015, 2016 Ideetron B.V.
/************************** Configuration ***********************************/
#include <TinyLoRa.h>
#include <SPI.h>

// Feather 32u4 LoRA Pins
#define DIO0      7
#define NSS_RFM   8

// Network Session Key (MSB)
uint8_t NwkSkey[16] = { FILL_THIS_IN };

// Application Session Key (MSB)
uint8_t AppSkey[16] = { FILL_THIS_IN };

// Device Address (MSB)
uint8_t DevAddr[4] = { FILL_THIS_IN };

/************************** Example Begins Here ***********************************/
// Data Packet to Send to TTN
unsigned char loraData[11] = {"hello LoRa"};

// How many times data transfer should occur, in seconds
const unsigned int sendInterval = 30;

// Global LoRaWan object
TinyLoRa lora;

void setup()
{
  delay(2000);
  while (! Serial);
  Serial.begin(9600);
 
  // Initialize pin LED_BUILTIN as an output
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Initialize LoRa
  Serial.println("Starting LoRa...");
  SPI.begin();
  lora.begin();
}

void loop()
{
  Serial.println("Sending LoRa Data...");
  lora.sendData(loraData, sizeof(loraData), lora.frameCounter);
  Serial.print("Frame Counter: ");Serial.println(lora.frameCounter);
  lora.frameCounter++;

  // blink LED to indicate packet sent
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  
  Serial.println("delaying...");
  delay(sendInterval * 1000);
}
