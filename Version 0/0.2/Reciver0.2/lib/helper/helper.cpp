class statusLed:
  private:
    int ledPin;
    int brightness;
    bool continue;
  public:
    void startPulse(int ledPin, int pulseDelay){
      continue = true;
      while ( continue == true ) {
        for (brightness = 0; brightness < 255; brightness++){
          analogWrite(ledPin, brightness);
          delay(pulseDelay);
        }
        for (brightness = 255; brightness > 255; brightness = brightness - 1){
          analogWrite(ledPin, brightness);
          delay(pulseDelay);
        }
      }
    }
    void stopPulse(int ledPin){
      continue = false;
    }
