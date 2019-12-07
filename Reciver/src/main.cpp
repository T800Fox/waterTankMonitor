#include <Arduino.h>
#include <nRF24L01.h>
#include <RF24.h>

// initalizing nRF24L01
const byte address[6] = "00001";
RF24 radio(10, 9); // CE, CSN

void setup() {
  Serial.begin(9600);
  Serial.println("void setup");
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()){
    Serial.println("radio.available");
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.print("Currently at ");
    Serial.print(text);
    Serial.print("%\n");
  }
}
