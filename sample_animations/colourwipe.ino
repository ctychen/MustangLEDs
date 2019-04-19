#include <Adafruit_NeoPixel.h>
 
#define PIN 5
 
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin();
  strip.setBrightness(75); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {
  strip.begin();
  setWipe(0, 255, 0); //change these values for whatever colour you want
  strip.show();
}

void setWipe(int r, int g, int b)
{

  for (int i = 0; i <= strip.numPixels(); i++)
  {
    strip.setPixelColor(i, r, g, b);
    strip.show();
    delay(20);                              //Slows down the leds so we can see the effects
  }
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
    delay(20);                            //Slows down the leds so we can see the effects
  }

}
