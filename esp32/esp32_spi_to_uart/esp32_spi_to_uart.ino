/*
   UART to SPI Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <SPI.h>

// UART pins
#define TXD2_PIN 17
#define RXD2_PIN 16

// SPI pins
#define SPI_MOSI_PIN 23
#define SPI_MISO_PIN 19
#define SPI_SCK_PIN 18
#define SPI_CS_PIN 5

#define LED_TEST 4

void setup() {
  pinMode( LED_TEST, OUTPUT);


  // Configure UART
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXD2_PIN, TXD2_PIN);

  // Configure SPI
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16); // 1 MHz clock
  SPI.setDataMode(SPI_MODE0);
  pinMode(SPI_CS_PIN, OUTPUT);
  digitalWrite(SPI_CS_PIN, HIGH); // Deselect the slave

  digitalWrite(LED_TEST, HIGH);
  delay(1000);
  digitalWrite(LED_TEST, LOW);
}

void loop() {

  if (Serial2.available() > 0) {
    uint8_t data = Serial2.read();
    Serial.println(data);
    // Send character to SPI
    digitalWrite(SPI_CS_PIN, LOW); // Select the slave
    SPI.transfer(data);
    digitalWrite(SPI_CS_PIN, HIGH); // Deselect the slave

      digitalWrite(LED_TEST, 1 ^ digitalRead(LED_TEST));
  }

  if (Serial.available() > 0) {
    uint8_t data = Serial.read();
    Serial.println(data);
    // Send character to SPI
    digitalWrite(SPI_CS_PIN, LOW); // Select the slave
    SPI.transfer(data);
    digitalWrite(SPI_CS_PIN, HIGH); // Deselect the slave

    digitalWrite(LED_TEST, 1 ^ digitalRead(LED_TEST));
  }
}