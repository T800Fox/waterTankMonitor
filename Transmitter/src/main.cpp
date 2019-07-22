#include <Arduino.h>
#include <helper.cpp>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// setting up transceiver
RF24 radio(10, 9); // CE, CSN
const byte address[6] = "00001"; // reciver address

// initalizing helper class
int tankVol = 5;
waterTank mainTank(3, tankVol, 2);  // digitalpin for rangefinder, capacity of tank (m^3), depth of tank (m)

// initalizing varibles
long waterLevel;
char buffer[32];
int currentPercent;

void setup() {
  // seting up serial
  Serial.begin(9600);
  // initalizing radio
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX); // replace MIN with MAX if working over longer distances
  radio.stopListening();
}



void loop() {
  currentPercent = mainTank.getTankPercentage();
  long currentDistance = mainTank.getDistance();
  Serial.println(currentDistance);

  itoa(currentPercent, buffer, 10);
  Serial.println(buffer);
  radio.write(&buffer, sizeof(buffer));
  delay(500);
}
