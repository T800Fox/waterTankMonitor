#include <Arduino.h>
// class to handle measurements from water tank
class waterTank
{
  private:
    // initalization varibles
    int pwmPin; // pin the ultrasonic is assigned to
    float tankCapacity; // capactiy of the water tank in Litres
    float tankDepth; // depth of tank

    // operation varibles
    float occupiedVolume; // water level in the tank
    float tankPercentage;  // percent of how full the tank is converted to decimal
    float tankRadius;  // radius of tank
    long distance; // varibles for distance
    float tankArea;

  public:
    waterTank(int aPin, float aVolume, float aDepth) {
      // if the pin value is a digital pin accept it
      pwmPin = aPin;
      tankDepth = aDepth;
      tankCapacity = aVolume; // sets the volume of the tank} // constructor for waterTank
    }
    long getDistance(){
      pinMode(pwmPin, INPUT);
      distance = pulseIn(pwmPin, HIGH);
      if (distance > 2000){
        throwError("ERROR: rangefinder over reading!");
      }
      return distance;}
    int getTankPercentage(){
      tankArea = tankCapacity / tankDepth;  // calculates the area over the tank base
      occupiedVolume = tankArea * (tankDepth - (float(distance) / 1000 ));  // calculates the volume occupied by water
      tankPercentage = occupiedVolume / tankCapacity; // calculates the percentage of how full tank is
      return int(tankPercentage * 100);
    }

    String throwError(String reason){
      Serial.println(reason);
      while(1);
    }
};
