#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6
//long strands have 134 pixels, short strands have 127
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1200

#define Pixel 260

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels1(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  
  pixels1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
    pixels1.setPixelColor(Pixel, pixels1.Color(150, 0, 0));
    pixels1.show();
}
