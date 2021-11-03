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
uint8_t reds [] = {0,0,0,0,0,0,0,0,0,2,4,5,7,9,11,12,14,16,18,19,21,23,25,26,28,30,32,33,35,37,39,40,42,44,46,47,49,51,53,55,56,58,60,62,63,65,67,69,70,72,74,76,77,79,81,83,84,86,88,90,91,93,95,97,98,100,102,104,106,107,109,111,113,114,116,118,120,121,123,125,127,128,130,132,134,135,137,139,141,142,144,146,148,149,151,153,155,157,158,160,162,164,165,167,169,171,172,174,176,178,179,181,183,185,186,188,190,192,193,195,197,199,200,202,204,206,208,234,232,230,229,227,225,223,222,220,218,216,215,213,211,209,208,206,204,202,200,199,197,195,193,192,190,188,186,185,183,181,179,178,176,174,172,171,169,167,165,164,162,160,158,157,155,153,151,149,148,146,144,142,141,139,137,135,134,132,130,128,127,125,123,121,120,118,116,114,113,111,109,107,106,104,102,100,98,97,95,93,91,90,88,86,84,83,81,79,77,76,74,72,70,69,67,65,63,62,60,58,56,55,53,51,49,47,46,44,42,40,39,37,35,33,32,30,28,26,25,23,21,19,18,16,14,12,11,9,7,5,4,2,0,28,30,32,33,35,37,39,40,42,44,46,47,49,51,53,55,56,58,60,62,63,65,67,69,70,72,74,76,77,79,81,83,84,86,88,90,91,93,95,97,98,100,102,104,106,107,109,111,113,114,116,118,120,121,123,125,127,128,130,132,134,135,137,139,141,142,144,146,148,149,151,153,155,157,158,160,162,164,165,167,169,171,172,174,176,178,179,181,183,185,186,188,190,192,193,195,197,199,200,202,204,206,208,209,211,213,215,216,218,220,222,223,225,227,229,230,232,234,236,237,239,241,243,244,246,248,250,255,255,255,255,255,255,255,255,255,255,255,255,255,253,251,250,248,246,244,243,241,239,237,236,234,232,230,229,227,225,223,222,220,218,216,215,213,211,209,208,206,204,202,200,199,197,195,193,192,190,188,186,185,183,181,179,178,176,174,172,171,169,167,165,164,162,160,158,157,155,153,151,149,148,146,144,142,141,139,137,135,134,132,130,128,127,125,123,121,120,118,116,114,113,111,109,107,106,104,102,100,98,97,95,93,91,90,88,86,84,83,81,79,77,76,74,72,70,69,67,65,63,62,60,58,56,55,53,51,49,47,46,44,42,70,72,74,76,77,79,81,83,84,86,88,90,91,93,95,97,98,100,102,104,106,107,109,111,113,114,116,118,120,121,123,125,127,128,130,132,134,135,137,139,141,142,144,146,148,149,151,153,155,157,158,160,162,164,165,167,169,171,172,174,176,178,179,181,183,185,186,188,190,192,193,195,197,199,200,202,204,206,208,209,211,213,215,216,218,220,222,223,225,227,229,230,232,234,236,237,239,241,243,244,246,248,250,251,253,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,253,251,250,248,246,244,243,241,239,237,236,234,232,230,229,227,225,223,222,220,218,216,215,213,211,209,208,206,204,202,200,199,197,195,193,192,190,188,186,185,183,181,179,178,176,174,172,171,169,167,165,164,162,160,158,157,155,153,151,149,148,146,144,142,141,139,137,135,134,132,130,128,127,125,123,121,120,118,116,114,113,111,109,107,106,104,102,100,98,97,95,93,91,90,88,86,84,113,114,116,118,120,121,123,125,127,128,130,132,134,135,137,139,141,142,144,146,148,149,151,153,155,157,158,160,162,164,165,167,169,171,172,174,176,178,179,181,183,185,186,188,190,192,193,195,197,199,200,202,204,206,208,209,211,213,215,216,218,220,222,223,225,227,229,230,232,234,236,237,239,241,243,244,246,248,250,251,253,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,253,251,250,248,246,244,243,241,239,237,236,234,232,230,229,227,225,223,222,220,218,216,215,213,211,209,208,206,204,202,200,199,197,195,193,192,190,188,186,185,183,181,179,178,176,174,172,171,169,167,165,164,162,160,158,157,155,153,151,149,148,146,144,142,141,139,137,135,134,132,130,128,127};
uint8_t greens [] = {17,0,0,0,73,255,161,12,0,0,201,255,79,0,0,0,0,0,0,0,165,255,170,0,0,0,0,0,194,255,211,0,22,206,255,71,0,0,0,0,4,226,255,212,3,0,0,0,82,255,255,99,0,0,0,0,140,255,82,0,0,0,130,255,33,0,0,0,0,0,0,14,241,255,25,0,0,0,33,206,191,12,0,0,0,4,54,34,0,0,0,0,141,221,115,0,0,163,188,0,0,23,126,102,18,0,0,0,191,221,131,24,0,0,0,0,0,0,0,6,63,69,0,0,0,210,194,0,0,33,194,120,0,0,0,83,72,22,0,0,0,0,0,0,78,171,178,192,24,0,0,5,75,78,40,0,0,32,134,46,0,30,184,159,16,0,0,0,15,48,19,0,0,0,0,12,152,140,2,0,0,0,67,247,255,9,0,0,0,0,0,0,255,238,140,0,0,19,255,167,0,0,0,0,13,255,248,81,0,0,0,0,0,22,225,255,101,0,0,0,0,13,76,255,161,0,166,255,233,76,0,0,0,0,11,242,255,0,0,0,0,0,0,3,246,255,46,0,0,0,12,162,255,22,0,0,46,255,0,0,0,255,0,0,167,255,4,0,0,0,0,0,164,255,228,1,0,0,0,0,40,255,158,0,0,0,0,0,205,255,205,44,0,145,255,238,78,0,0,0,19,239,255,16,0,0,0,0,0,0,0,255,234,31,0,0,0,0,36,255,199,10,0,78,255,141,0,0,0,0,0,0,0,14,255,240,0,0,0,45,110,64,0,0,0,0,0,5,53,45,7,0,0,0,10,147,155,0,0,77,91,0,0,3,47,84,46,0,0,0,8,74,129,126,49,0,0,0,0,0,26,71,0,0,0,0,1,169,0,43,134,72,83,0,0,0,6,59,20,0,0,0,0,5,79,85,35,0,0,0,0,4,80,77,4,0,0,15,61,22,0,41,105,82,3,0,0,0,4,68,72,67,3,0,0,0,0,6,84,38,0,0,0,251,198,35,0,0,0,0,0,0,0,125,255,75,0,52,255,208,0,0,0,0,0,62,255,225,0,0,0,0,0,0,0,105,244,255,60,0,0,0,197,255,16,0,0,0,16,160,255,98,0,0,0,0,43,255,169,0,0,0,0,35,255,255,29,0,0,0,0,0,36,154,255,13,0,127,255,117,0,0,204,15,32,189,240,255,57,0,0,0,0,0,89,255,94,0,0,0,1,245,255,1,0,0,0,0,189,255,35,0,0,0,0,225,255,193,0,0,0,0,156,255,241,78,0,0,0,0,0,0,193,255,143,0,0,0,0,77,255,68,0,0,131,249,255,0,0,0,0,0,0,0,48,255,207,0,0,0,0,54,39,0,0,0,0,18,97,14,3,0,0,0,0,27,45,62,4,0,1,31,38,1,0,0,15,84,50,0,0,0,0,0,39,66,55,1,0,0,0,37,77,90,0,0,0,38,88,0,19,36,55,6,0,0,0,90,144,90,0,0,0,13,78,68,5,0,0,0,0,32,122,31,0,0,0,25,33,3,0,0,0,5,45,39,9,0,0,0,43,59,111,7,0,0,3,14,18,27,0,0,0,4,181,255,13,0,0,0,0,0,0,0,86,255,103,0,49,255,199,6,0,0,0,0,214,247,255,0,0,0,0,0,0,159,255,137,0,0,0,0,0,22,242,255,27,0,0,92,255,255,38,0,0,0,0,0,169,255,90,0,0,0,122,255,87,0,0,0,0,0,39,231,255,5,0,21,255,225,28,0,0,153,0,0,0,208,255,41,0,0,0,0,0,77,255,238,2,0,0,82,255,218,0,0,0,0,0,2,216,255,136,0,0,165,255,145,0,0,0,0,0,0,163,255,186,0,0,0,0,0,0,139,255,183,0,0,0,0,0,131,255,93,0,69,255,215,0,0,0,0,0,0,0,0,178,255,85,0,0,0,8,11,14,18,0,0,4,76,132,134,42,0,0,22,50,36,5,0,0,0,0,4,21,8,0,0,0,49,48,0,0,0,0,0,4,80,65,0,0,0,110,173,45,0,0,0,1,9,0,15,44,15,0,0,0,0,77,143,100,0,0,0,57,48,0,0,0,0,0,0,0,0,0,0,0,20,6,0,0,0,0,0,6,57,26,6,0,0,105,177,18,0,0,0,0,22,15,13,2,0,0,0,142,255,5,0,0,0,0,0,0,0,0,255,169,38,0,54,255,126,0,0,0,0,0,65,255,56,0,0,0,0,0,0,138,255,21,0,0,0,0,0,0,129,255,146,0,0,67,255,233,19,0,0,0,0,109,255,186,17,0,0,73,255,213,24,0,0,0,0,0,67,255,86,0,0,0,22,117,255,225,28};
uint8_t blues [] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//end paste block

//long strands have 134 pixels, short strands have 127
#define lightsNum 1043

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.
Adafruit_NeoPixel pixels(lightsNum, PIN, NEO_GRB + NEO_KHZ800);

long timer = 0;
long animSpeed = 1;

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();
}

void loop() {

  timer += animSpeed;
  if(timer > 255){
    timer = 0;
  }
  
  for(int i=0; i<lightsNum; i++) { // For each pixel...

    uint32_t color = pixels.Color(249, 79, 30);
    pixels.setPixelColor(i, color);

    uint8_t redMask = reds[i] + timer;
    if(redMask > 255){
      redMask = redMask - 255;
    }

    if(redMask > 200){
      uint32_t color = pixels.Color(249, 198, 30);
      pixels.setPixelColor(i, color);
    }

  }
  pixels.show();   // Send the updated pixel colors to the hardware.

}
