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
uint16_t fireWorks [4][46]{};
uint8_t fireWorkAnimRed[] = {255, 223, 191, 159, 127, 95, 63, 31};
uint8_t fireWorkAnimGreen[] = {255, 150, 0, 0, 0, 0, 0, 0};
uint8_t fireWorkAnimBlue[] = {255, 150, 20, 20, 0, 0, 0, 0};

//end paste block

//long strands have 134 pixels, short strands have 127
#define lightsNum 1043

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.
Adafruit_NeoPixel pixels(lightsNum, PIN, NEO_GRB + NEO_KHZ800);

long Time = 0;
long Speed = 10;
uint8_t currentFireWork = 0;

void setup() {

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(255);
  pixels.show();
  Serial.begin(9600);
}

void MakeFireworkArray(uint16_t center)
{   
    fireWorks[currentFireWork][0] = center;
    for(int i=1; i<9; i++){
      fireWorks[currentFireWork][i] = center + i;
    }
    for(int i=1; i<9; i++){
      fireWorks[currentFireWork][i+8] = center - i;
    }
    for(int i=17; i<29; i++){
      fireWorks[currentFireWork][i] = 10;
    }
    fireWorks[currentFireWork][29] = 255;
    //row 1
    if(center < 134){
      for(int i=30; i<38;i++){
        fireWorks[currentFireWork][i] = 0;
      }
      for(int i=38; i<46;i++){
        fireWorks[currentFireWork][i] = 134 + (134 - center) + i-42;
      }
    }
    //row 2...
    else if(center < 260){
      for(int i=30; i<38;i++){
        fireWorks[currentFireWork][i] = 134 - (center - 134) - 30+i;
      }
      for(int i=38; i<46;i++){
        fireWorks[currentFireWork][i] = 260 + (260 - center) + i-42;
      }
    }
    else if(center < 394){
      for(int i=30; i<38;i++){
        fireWorks[currentFireWork][i] = 260 - (center - 260) - 30+i;
      }
      for(int i=38; i<46;i++){
        fireWorks[currentFireWork][i] = 394 + (394 - center) + i-42;
      }
    }
    else if(center < 521){
      for(int i=30; i<38;i++){
        fireWorks[currentFireWork][i] = 394 - (center - 394) - 30+i;
      }
      for(int i=38; i<46;i++){
        fireWorks[currentFireWork][i] = 521 + (521 - center) + i-42;
      }
    }
    else if(center < 655){
      for(int i=30; i<38;i++){
        fireWorks[currentFireWork][i] = 521 - (center - 521) - 30+i;
      }
      for(int i=38; i<46;i++){
        fireWorks[currentFireWork][i] = 655 + (655 - center) + i-42;
      }
    }
    else if(center < 782){
      for(int i=30; i<38;i++){
        fireWorks[currentFireWork][i] = 655 - (center - 655) - 30+i;
      }
      for(int i=38; i<46;i++){
        fireWorks[currentFireWork][i] = 782 + (782 - center) + i-42;
      }
    }
    else if(center < 916){
      for(int i=30; i<38;i++){
        fireWorks[currentFireWork][i] = 782 - (center - 782) - 30+i;
      }
      for(int i=38; i<46;i++){
        fireWorks[currentFireWork][i] = 916 + (916 - center) + i-42;
      }
    }
    else{
      for(int i=30; i<38;i++){
        fireWorks[currentFireWork][i] = 916 - (center - 916) - 30+i;
      }
      for(int i=38; i<46;i++){
        fireWorks[currentFireWork][i] = 0;
      }
    }
}

void KillFirework(uint8_t index){
  for(int j = 0; j<45; j++){
    fireWorks[index][j] = 0;
  }
}

void loop() {
  Time = Time + Speed;

  if(Time > 255) {
    Time = 0;
    currentFireWork++;
    if(currentFireWork > 3){
      currentFireWork = 0;
    }
    uint16_t start = random(0, 1043);
    MakeFireworkArray(start);
    for(int i=0; i<45; i++){
      Serial.println(fireWorks[currentFireWork][i]);
    }
  }
  uint32_t off = pixels.Color(0, 50, 100);
  for(int i = 0; i < lightsNum; i++){
    pixels.setPixelColor(i, off);
  }
  
  for(int i=0; i<3; i++) { // For each pixel...
    if(fireWorks[i][29] > 255){
      fireWorks[i][29] = 255;
    }
    fireWorks[i][29] = fireWorks[i][29] - Speed/2;
    //less than 32
    uint32_t fireWorkColor = pixels.Color(fireWorkAnimRed[0], fireWorkAnimGreen[0], fireWorkAnimBlue[0]);
    if(fireWorks[i][29] < 210){
      fireWorkColor = pixels.Color(fireWorkAnimRed[1], fireWorkAnimGreen[1], fireWorkAnimBlue[1]);
    }
    if(fireWorks[i][29] < 192){
      fireWorkColor = pixels.Color(fireWorkAnimRed[2], fireWorkAnimGreen[2], fireWorkAnimBlue[2]);
    }
    if(fireWorks[i][29] < 160){
      fireWorkColor = pixels.Color(fireWorkAnimRed[3], fireWorkAnimGreen[3], fireWorkAnimBlue[3]);
    }
    if(fireWorks[i][29] < 128){
      fireWorkColor = pixels.Color(fireWorkAnimRed[4], fireWorkAnimGreen[4], fireWorkAnimBlue[4]);
    }
    if(fireWorks[i][29] < 96){
      fireWorkColor = pixels.Color(fireWorkAnimRed[5], fireWorkAnimGreen[5], fireWorkAnimBlue[5]);
    }
    if(fireWorks[i][29] < 64){
      fireWorkColor = pixels.Color(fireWorkAnimRed[6], fireWorkAnimGreen[6], fireWorkAnimBlue[6]);
    }
    if(fireWorks[i][29] < 32){
      fireWorkColor = pixels.Color(fireWorkAnimRed[7], fireWorkAnimGreen[7], fireWorkAnimBlue[7]);
    }
    if(fireWorks[i][29] < 10){
      KillFirework(i);
    }
    for(int j=0; j<46; j++){
      pixels.setPixelColor(fireWorks[i][j], fireWorkColor);
    }
    uint32_t white = pixels.Color(255, 255, 255);
    pixels.setPixelColor(fireWorks[i][0], white);
  }
    
  pixels.show();   // Send the updated pixel colors to the hardware.
}
