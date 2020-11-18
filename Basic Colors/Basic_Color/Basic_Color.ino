#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 600

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels1(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  
  pixels1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels2.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
//  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
//
//    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
//    // Here we're using a moderately bright green color:
//    pixels1.setPixelColor(i, pixels1.Color(150 , 150, 150));
//    pixels1.show();   // Send the updated pixel colors to the hardware.
//  }
  for(int i = NUMPIXELS + 1; i < 1200; i++){
      pixels2.setPixelColor(i, pixels2.Color(150 , 150, 150));
      pixels2.show();
  }
}
