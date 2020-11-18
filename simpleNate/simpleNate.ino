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
#define Strand1 134
#define Strand2 260
#define Strand3 394
#define Strand4 521
#define Strand5 655
#define Strand6 782
#define Strand7 916
#define Strand8 1043

//Color1 (255, 218, 24)
//Color2 (251, 194, 38)
//Color3 (246, 171, 51)
//Color4 (242, 147, 65)
//Color5 (236, 128, 61)
//Color6 (229, 105, 56)
//Color7 (224, 85, 51)
//Color8 (219, 69, 48)

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.
Adafruit_NeoPixel pixels1(Strand8, PIN, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels2(Strand2, PIN, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels3(Strand3, PIN, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels4(Strand4, PIN, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels5(Strand5, PIN, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels6(Strand6, PIN, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels7(Strand7, PIN, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels8(Strand8, PIN, NEO_GRB + NEO_KHZ800);

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


  pixels1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels1.show();
}

void loop() {
  uint32_t Color1 = pixels1.Color(255, 218, 24);
  uint32_t Color2 = pixels1.Color(255, 195, 21);
  uint32_t Color3 = pixels1.Color(255, 172, 18);
  uint32_t Color4 = pixels1.Color(255, 149, 15);
  uint32_t Color5 = pixels1.Color(255, 126, 12);
  uint32_t Color6 = pixels1.Color(255, 103, 9);
  uint32_t Color7 = pixels1.Color(255, 40, 0);
  uint32_t Color8 = pixels1.Color(255, 0, 0);

//  long currentTime = millis();
//  if(currentTime > waitTime * 1000){
//    Color8 = pixels1.Color(0, 255, 0);
//    
//    }


  for(int i=0; i<Strand8; i++) { // For each pixel...

    if (i < Strand1) {
      pixels1.setPixelColor(i, Color8);
    }
    if (i > Strand1 && i < Strand2) {
      pixels1.setPixelColor(i, Color7);
    }
    if (i > Strand2 && i < Strand3) {
      pixels1.setPixelColor(i, Color6);
    }
    if (i > Strand3 && i < Strand4) {
      pixels1.setPixelColor(i, Color5);
    }
    if (i > Strand4 && i < Strand5) {
      pixels1.setPixelColor(i, Color4);
    }
    if (i > Strand5 && i < Strand6) {
      pixels1.setPixelColor(i, Color3);
    }
    if (i > Strand6 && i < Strand7) {
      pixels1.setPixelColor(i, Color2);
    }
    if (i > Strand7 && i < Strand8) {
      pixels1.setPixelColor(i, Color1);
    }
  }
  pixels1.show();   // Send the updated pixel colors to the hardware.

}
