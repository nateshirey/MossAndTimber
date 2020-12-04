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
uint8_t reds [] = {255,255,255,255,255,255,255,80,0,0,0,0,0,0,0,0,74,255,255,174,0,0,0,25,234,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,1,0,0,0,94,145,181,247,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,213,0,0,44,39,0,0,224,255,255,255,255,255,255,255,234,181,167,174,123,11,0,0,0,0,0,80,255,255,255,255,255,255,255,7,0,0,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,255,255,255,255,255,255,255,60,0,0,0,0,0,16,123,174,174,181,219,254,255,254,255,255,255,255,255,0,0,39,95,0,0,224,255,255,251,207,224,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,251,213,131,0,0,0,0,234,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,239,25,0,0,0,145,255,255,54,0,0,0,0,0,0,0,0,131,255,255,255,255,255,255,255,255,255,255,145,255,255,255,255,255,255,255,167,0,0,0,0,0,0,0,0,30,255,255,116,0,0,0,41,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,219,0,0,0,0,174,255,255,255,255,255,255,255,234,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,174,60,36,138,255,255,234,0,0,122,28,0,30,255,255,255,243,131,123,174,207,201,188,181,167,116,30,0,0,0,0,0,54,255,255,255,255,255,255,255,138,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,213,255,255,255,255,255,255,255,60,0,0,0,0,0,47,109,160,188,194,181,131,36,0,0,116,255,255,255,87,0,19,136,0,0,239,255,230,4,0,0,30,234,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,207,123,207,255,255,255,255,255,255,224,4,0,0,0,207,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,67,0,0,0,94,255,255,4,0,0,0,0,0,0,0,0,194,255,255,255,255,255,255,255,255,255,247,11,255,255,255,255,255,255,255,219,0,0,0,0,0,0,0,0,0,255,255,67,0,0,0,102,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,188,0,0,0,20,255,255,255,255,255,255,255,94,11,109,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,145,0,0,0,0,138,255,247,0,0,143,7,0,138,255,255,247,0,0,0,0,47,153,201,194,145,94,67,20,0,0,0,0,67,255,255,255,255,255,255,255,255,54,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,167,255,255,255,255,255,255,255,255,94,0,0,0,0,87,94,80,123,188,194,116,0,0,0,0,0,174,255,255,181,0,0,122,0,0,254,255,36,0,0,0,0,60,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,30,0,11,255,255,255,255,255,255,255,47,0,0,0,181,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,131,0,0,0,41,255,255,0,0,7,0,0,0,0,0,0,234,255,255,255,255,255,255,255,255,255,181,0,255,255,255,255,255,255,255,247,0,0,0,0,0,0,28,0,0,255,255,20,0,0,0,153,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,167,0,0,0,87,255,255,255,255,255,255,234,0,0,0,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,4,0,23,88,0,0,255,255,0,0,95,0,0,207,255,255,87,0,1,0,0,0,80,181,174,102,67,123,167,67,0,0,0,116,255,255,255,255,255,255,255,255,251,138,41,0,0,0,0,0,0,0,0,0,0,0,0,47,167,247,255,255,255,255,255,255,255,255,255,123,0,0,1,167,230,160,67,80,138,145,36,0,0,101,136,0,11,255,255,219,0,0,44,0,0,255,254,0,4,218,143,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,213,0,0,0,213,255,255,255,255,255,255,123,0,0,0,167,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,153,0,0,0,0,255,255,0,0,28,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,109,0};
uint8_t greens [] = {0,3,11,16,7,11,117,255,255,63,169,255,255,255,255,255,255,186,156,255,255,255,255,255,255,109,21,38,101,117,71,16,0,0,0,0,0,7,11,16,7,3,38,255,255,255,255,255,255,255,255,255,148,32,16,57,94,71,32,3,3,7,7,7,7,7,11,7,3,0,3,21,44,71,86,79,79,86,125,178,212,193,125,148,255,255,123,0,0,139,255,255,79,11,57,125,140,156,219,255,255,255,255,255,255,255,217,70,92,255,255,132,0,0,0,0,16,199,255,244,15,0,10,123,244,255,255,255,255,255,255,255,223,146,63,25,99,255,255,156,7,0,0,0,0,140,255,255,63,70,234,255,255,255,255,255,255,255,255,245,255,249,164,44,44,235,255,198,0,0,49,255,255,132,164,255,255,255,235,140,51,11,16,11,11,3,3,7,16,21,21,11,0,3,0,3,0,7,71,156,199,148,57,21,79,206,255,255,255,255,255,255,255,255,38,0,0,0,0,3,0,0,0,0,0,16,64,109,86,32,16,101,255,255,255,255,255,255,164,186,255,255,223,255,255,255,177,99,255,255,71,0,0,3,3,0,0,0,44,212,255,0,0,0,0,0,0,44,255,255,131,198,255,255,255,154,248,255,199,178,255,255,255,255,255,255,86,11,21,64,86,51,11,0,0,0,0,0,0,0,0,0,0,44,255,255,255,255,255,255,249,199,125,38,21,109,235,255,240,117,11,0,0,0,0,0,16,38,44,32,16,3,0,0,0,0,0,64,219,255,255,255,255,230,140,255,255,20,0,0,239,255,193,44,109,255,255,255,255,255,255,255,255,255,255,255,255,255,123,77,255,255,140,0,0,0,0,0,109,255,255,217,131,146,184,217,255,255,255,255,255,255,229,217,229,229,244,255,255,255,71,0,0,0,0,0,132,255,255,115,191,255,255,255,255,255,255,255,255,255,255,255,255,255,199,51,156,255,255,0,0,6,255,255,156,255,255,255,255,255,255,101,0,0,0,0,0,3,21,57,79,57,21,0,0,0,0,0,11,156,255,255,255,171,26,16,57,117,186,255,255,255,255,255,255,51,0,0,0,0,0,0,0,0,0,0,7,38,64,44,11,7,71,240,255,255,255,255,255,186,212,255,198,77,248,255,255,217,169,255,255,32,0,0,0,0,0,0,0,57,255,255,0,0,0,0,0,0,26,255,255,211,239,255,255,211,20,146,255,224,206,255,255,255,255,255,219,57,3,3,26,44,26,7,0,0,0,0,0,0,0,0,0,0,51,255,255,239,255,255,249,101,44,16,3,32,224,255,255,255,199,16,0,0,0,0,0,32,86,117,94,44,7,0,0,0,0,0,140,255,255,255,239,255,255,186,255,255,6,0,0,255,255,117,71,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,177,255,255,125,0,0,0,0,0,44,249,255,255,255,255,255,234,205,211,255,252,184,169,198,255,255,255,255,255,255,193,26,0,0,0,0,0,117,255,255,244,255,255,255,255,255,255,255,255,255,255,255,184,177,255,255,94,94,255,255,3,0,20,255,255,212,255,248,43,107,255,255,178,7,0,0,0,3,16,71,140,164,117,44,3,0,0,0,0,16,235,255,255,255,253,38,0,0,7,44,206,255,255,234,255,255,57,0,0,0,0,0,0,0,0,0,0,3,16,26,16,0,0,44,193,255,255,255,255,255,219,235,255,99,0,169,255,255,255,244,255,255,26,0,0,0,0,0,0,0,71,255,255,0,0,0,0,0,0,26,255,255,255,255,255,255,139,0,70,255,240,230,255,255,248,255,255,171,32,0,0,7,16,11,3,0,0,0,0,0,0,0,0,0,0,57,255,255,234,255,255,156,11,0,0,0,44,255,255,255,255,255,21,0,0,3,3,7,57,156,212,193,117,38,11,0,0,0,7,206,255,223,0,0,92,255,240,249,255,49,0,20,255,255,71,117,255,252,0,6,217,255,255,255,255,255,255,255,255,255,255,255,255,255,109,0,0,0,0,0,16,132,255,255,255,255,255,255,205,131,255,234,115,131,234,255,255,255,255,255,199,94,21,7,3,0,0,0,140,255,255,255,255,255,255,255,255,255,255,255,255,255,107,0,0,115,255,164,79,255,255,56,0,115,255,235,255,255,0,0,0,123,255,230,11,0,0,7,32,86,186,245,249,193,71,11,7,16,16,3,57,255,255,255,255,255,51,0,0,0,0,117,255,255,239,255,255,64,0,0,0,3,3,0,0,0,0,0,3,11,21,11,0,0,32,164,255,255,223,252,255,249,249,255,70,0,123,255,255,255,255,255,249,21,0,0,0,0,0,0,0,94,255,255};
uint8_t blues [] = {0,0,0,0,0,0,0,0,245,255,255,127,18,120,249,194,0,0,0,0,42,168,113,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,148,134,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,86,255,255,255,255,79,0,0,0,0,0,0,0,0,0,0,0,0,0,0,134,255,255,255,227,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,168,27,141,60,42,120,222,255,255,255,255,255,212,0,0,0,0,0,0,0,0,0,245,255,255,255,113,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,255,255,255,255,113,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,175,206,37,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,206,92,0,0,0,0,232,255,181,48,141,255,255,222,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,187,255,255,148,79,227,255,255,0,0,0,0,127,227,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,241,200,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,66,241,255,255,249,0,0,0,0,0,0,0,0,0,120,255,255,255,255,255,255,200,168,200,222,252,255,255,255,255,255,212,22,0,0,0,0,0,0,0,0,0,245,255,255,181,18,0,0,0,0,0,0,0,0,18,13,0,0,0,0,0,245,255,255,255,120,0,0,0,0,106,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,212,255,99,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,106,237,161,0,0,0,0,255,255,255,106,148,255,255,155,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,113,255,255,148,134,255,255,255,9,0,0,0,187,249,99,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,255,212,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,245,255,134,0,0,0,113,255,255,255,217,0,0,0,0,9,194,194,60,0,0,0,0,0,0,0,0,86,255,255,227,0,0,0,0,0,0,0,0,0,0,79,168,217,245,255,255,255,155,255,255,255,255,255,200,113,42,0,0,0,0,0,0,0,0,0,0,0,187,255,181,6,0,0,0,0,0,0,0,9,200,255,255,148,0,0,0,0,187,255,255,255,86,0,0,0,255,255,255,206,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,0,0,206,255,141,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,86,255,212,0,0,0,27,255,255,255,155,141,255,255,79,0,0,0,0,0,0,0,0,0,0,0,92,0,0,0,0,0,0,0,0,42,245,237,134,168,255,255,255,37,0,0,0,232,255,79,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,155,255,187,0,0,0,0,0,0,0,0,37,155,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,27,0,0,48,255,255,255,155,0,0,0,0,255,255,255,255,73,0,0,0,0,0,0,0,0,79,217,141,0,0,0,0,0,0,0,0,0,0,0,0,22,120,227,255,255,92,255,255,255,255,175,42,0,0,0,0,0,0,0,0,0,0,0,0,0,86,134,0,0,0,0,0,0,0,0,0,141,255,255,255,255,0,0,0,0,134,255,255,255,13,0,0,99,255,255,255,255,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,222,86,0,0,0,0,0,0,0,0,168,255,161,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,92,255,255,2,0,0,37,255,255,255,181,120,212,206,9,0,0,0,0,0,0,0,0,0,0,0,222};

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
