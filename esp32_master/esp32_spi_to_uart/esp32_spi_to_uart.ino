//----------------------------------------Load libraries
#include <esp_now.h>
#include <SPI.h>
#include <WiFi.h>
//----------------------------------------
// UART pins
#define TXD2_PIN 17
#define RXD2_PIN 16

// SPI pins
#define SPI_MOSI_PIN 23
#define SPI_MISO_PIN 19
#define SPI_SCK_PIN 18
#define SPI_CS_PIN 5

#define LED_TEST 4
void sendChar(char data);
uint8_t broadcastAddress[] = {0xB8, 0xD6, 0x1A, 0xA5, 0xC3, 0x98}; //--> REPLACE WITH THE MAC Address of your receiver / ESP32 Receiver.

//----------------------------------------Variables to accommodate the data to be sent.
char send_val_1;

//----------------------------------------

String success; //--> Variable to store if sending data was successful.

//----------------------------------------Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
    char val_1;
   
} struct_message;

struct_message send_Data; //--> Create a struct_message to send data.
//----------------------------------------

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
  if (status ==0){
    success = "Delivery Success :)";
  }
  else{
    success = "Delivery Fail :(";
  }
  Serial.println(">>>>>");
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ VOID SETUP
void setup() {
  pinMode( LED_TEST, OUTPUT);

  Serial.begin(115200);
   Serial2.begin(9600, SERIAL_8N1, RXD2_PIN, TXD2_PIN);

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

 
  WiFi.mode(WIFI_STA); //--> Set device as a Wi-Fi Station.

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
  
  //----------------------------------------Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  //----------------------------------------
  
  //----------------------------------------Register peer
  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  //----------------------------------------
  
  //----------------------------------------Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  //----------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ VOID LOOP
void loop() {
  //----------------------------------------Set values to send
 if (Serial2.available() > 0) 
   
 { send_val_1 =Serial2.read();
  
    send_Data.val_1 = send_val_1;
     sendChar(send_val_1);

        //----------------------------------------Send message via ESP-NOW
      esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &send_Data, sizeof(send_Data));
      
      if (result == ESP_OK) {
        Serial.println("Sent with success");
      }
      else {
        Serial.println("Error sending the data");
      }

       //----------------------------------------
  
        Serial.println();
        Serial.print(">>>>> ");
        Serial.println("Send data");


  }
  
 
 
  }


  //----------------------------------------
  void sendChar(char data)
  {
    Serial.println(data);

    // Send character to SPI
    digitalWrite(SPI_CS_PIN, LOW); // Select the slave
    SPI.transfer(data);
    digitalWrite(SPI_CS_PIN, HIGH); // Deselect the slave

    //toggle led
    digitalWrite(LED_TEST, 1 ^ digitalRead(LED_TEST));
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



