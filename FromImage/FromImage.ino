// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 

//paste colors here

//end paste block
//long strands have 134 pixels, short strands have 127
#define lightsNum 1043

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.
Adafruit_NeoPixel pixels(lightsNum, PIN, NEO_GRB + NEO_KHZ800);

long waitTime = 5;
long startTime = 0;

void setup() {
  startTime = millis();

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();
}

void loop() {
  for(int i=0; i<lightsNum; i++) { // For each pixel...
    uint32_t color = pixels.Color(reds[i], greens[i], blues[i]);
    pixels.setPixelColor(i, color);
  }
  pixels.show();   // Send the updated pixel colors to the hardware.

}
