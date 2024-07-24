#include <esp_now.h>
#include <WiFi.h>
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


char receive_val_1;

// Must match the sender structure
typedef struct struct_message {
    char val_1;
} struct_message;

struct_message receive_Data; 

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&receive_Data, incomingData, sizeof(receive_Data));
  Serial.println();
  Serial.println("<<<<< Receive Data:");
  Serial.print("Bytes received: ");
  Serial.println(len);
  receive_val_1 = receive_Data.val_1;
  Serial.println("Receive Data: ");
  Serial.println(receive_val_1);
  Serial.println("<<<<<");

  //Serial2.print(receive_val_1);

   digitalWrite(SPI_CS_PIN, LOW); // Select the slave
   SPI.transfer(receive_val_1);
  digitalWrite(SPI_CS_PIN, HIGH); // Deselect the slave
  digitalWrite(LED_TEST, 1^digitalRead(LED_TEST) );
}

void setup() {
  pinMode( LED_TEST, OUTPUT);

  Serial.begin(115200);
  //Serial2.begin(9600, SERIAL_8N1, RXD2_PIN, TXD2_PIN);
  
  WiFi.mode(WIFI_STA); //--> Set device as a Wi-Fi Station



  //----------------------------------------Init ESP-NOW
  while (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");

    //flash led
    digitalWrite(LED_TEST, LOW );
    delay(900);
    digitalWrite(LED_TEST, HIGH );
    delay(100);
    //return;
  }
  //----------------------------------------
  
  esp_now_register_recv_cb((esp_now_recv_cb_t)&OnDataRecv); //--> Register for a callback function that will be called when data is received


// Configure SPI
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16); // 1 MHz clock
  SPI.setDataMode(SPI_MODE0);
  pinMode(SPI_CS_PIN, OUTPUT);
  digitalWrite(SPI_CS_PIN, HIGH); // Deselect the slave



  //Test LED connected with ESP32 in car
  digitalWrite(LED_TEST, HIGH);
  delay(1000);
  digitalWrite(LED_TEST, LOW);

}

void loop() {
  
}
