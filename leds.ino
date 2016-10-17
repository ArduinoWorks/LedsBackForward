#include <Adafruit_NeoPixel.h>
//Led Settings
#define PIN 6
#define NUMPIXELS 8
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels.begin();
}

void loop(){
  
  for(int i=0; i< NUMPIXELS; i++) {
    pixels.setPixelColor(i, Wheel(((i * 256 / NUMPIXELS)) & 255));
    pixels.show();
    delay(1000);
  }

  delay(2000);
  clearLeds();
  
  for(int i=NUMPIXELS; i >= 0; i--) {
    pixels.setPixelColor(i, Wheel(((i * 256 / NUMPIXELS)) & 255));
    pixels.show();
    delay(1000);
  }

  delay(2000);
  clearLeds();

}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void clearLeds() {
  for(int i=0;i<NUMPIXELS;i++) {
    pixels.setPixelColor(i, 0, 0, 0);
    pixels.show();
  }
}
