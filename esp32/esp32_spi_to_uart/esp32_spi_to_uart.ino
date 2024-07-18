/*
   UART to SPI Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <SPI.h>

// UART pins
#define TXD_PIN 17
#define RXD_PIN 16

// SPI pins
#define SPI_MOSI_PIN 23
#define SPI_MISO_PIN 19
#define SPI_SCK_PIN 18
#define SPI_CS_PIN 5

void setup() {
  // Configure UART
  Serial.begin(9600, SERIAL_8N1);

  // Configure SPI
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16); // 1 MHz clock
  SPI.setDataMode(SPI_MODE0);
  pinMode(SPI_CS_PIN, OUTPUT);
  digitalWrite(SPI_CS_PIN, HIGH); // Deselect the slave
}

void loop() {
  // Read character from UART
  //if(Serial.read()=='f'){
   // Serial.println("gggggg");
 // }

/*
{
  static int i=0;
  char arr[] = {'F','R','L','N','S'};
  digitalWrite(SPI_CS_PIN, LOW); 
  Serial.print(arr[(i) % 5]);// Select the slave
    SPI.transfer(arr[(i++) % 5]);
    digitalWrite(SPI_CS_PIN, HIGH); // Deselect the slave
    delay(2000);
  return ;
}*/


  if (Serial.available() > 0) {
    uint8_t data = Serial.read();
    Serial.println(data);
    // Send character to SPI
    digitalWrite(SPI_CS_PIN, LOW); // Select the slave
    SPI.transfer(data);
    digitalWrite(SPI_CS_PIN, HIGH); // Deselect the slave
  }
}