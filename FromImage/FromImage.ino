// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

//long strands have 134 pixels, short strands have 127
#define lightsNum 1043


// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.
Adafruit_NeoPixel pixels(lightsNum, PIN, NEO_GRB + NEO_KHZ800);

uint32_t pixelColors = new uint32_t[pixels.numPixels()];

long waitTime = 5;
long startTime = 0;

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  startTime = millis();


  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();

}

void loop() {
  uint32_t Color8 = pixels.Color(255, 0, 0);

  for(int i=0; i<lightsNum; i++) { // For each pixel...
    uint32_t color = pixels.Color(255, 255, 255);
    pixels.setPixelColor(i, color);
  }
  pixels.show();   // Send the updated pixel colors to the hardware.

}


struct vector3 {
  unsigned int X;
  unsigned int Y;
  unsigned int Z;
};

vector3 colorsArray = new vector3[2];
