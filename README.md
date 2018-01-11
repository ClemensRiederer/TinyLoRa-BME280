# TinyLoRa-BME280
Arduino library for a Atmospheric Sensor BME280 LoRaWan Node.
The LoRa Node measures barometric pressure, humidity, and temperature every 15 min. 
After the measurements, the ATtiny85 goes into sleep mode and is awakened by the watchdog timer.
The RFM module sends the values to the TTN backend with Activation by Personalization (ABP) a fix datarate and one of three random channels.

The example sketch that fits in the 8K Bytes Flash Memory of the ATtiny85
