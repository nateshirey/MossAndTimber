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
//fireWorks[x][y] are x number of arrays that contain y number of lights
//the following arrays are stages of a firework animation
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
//current firework is the index of the next firework to be instantiated
uint8_t currentFireWork = 0;
//randLight is 8 random numbers in the range of the firework array used for sparkling
uint8_t randLight[8] = {};

void setup() {

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(255);
  pixels.show();
  Serial.begin(9600);
}

//this function populates the oldest firework array with new light numbers
void MakeFireworkArray(uint16_t center)
{   
  //The first 8 indexes are the 8 lights forward in the strip
    fireWorks[currentFireWork][0] = center;
    for(int i=1; i<9; i++){
      fireWorks[currentFireWork][i] = center + i;
    }
    //the next 8 are the 8 lights backwards in the strip
    for(int i=1; i<9; i++){
      fireWorks[currentFireWork][i+8] = center - i;
    }
    //not sure what this was
    for(int i=17; i<29; i++){
      fireWorks[currentFireWork][i] = 0;
    }
    //the 29th index is used for the timer on the firework
    fireWorks[currentFireWork][29] = 255;
    //this next part gets the indeces of the lights directly up and down 
    //depending on where the center of the light is
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
//this just sets the index of the light to 0 for each light after the timer
//runs out
void KillFirework(uint8_t index){
  for(int j = 0; j<45; j++){
    fireWorks[index][j] = 0;
  }
}

void loop() {
  Time = Time + Speed;
  //count up by the speed and if the timer hits 255, make a new firework
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
  //set all the pixels to the background color
  uint32_t back = pixels.Color(0, 40, 120);
  for(int i = 0; i < lightsNum; i++){
    pixels.setPixelColor(i, back);
  }

  //pick 8 random lights to flicker
  for(int r=0; r<7; r++){
    randLight[r] = random(0,45);
  }
  
  for(int i=0; i<3; i++) { // For each firework array...
    //clamp the timer
    if(fireWorks[i][29] > 255){
      fireWorks[i][29] = 255;
    }
    //count the timer down
    fireWorks[i][29] = fireWorks[i][29] - Speed;
    //if the timer is still close to the beginning...
    uint32_t fireWorkColor = pixels.Color(fireWorkAnimRed[0], fireWorkAnimGreen[0], fireWorkAnimBlue[0]);
    if(fireWorks[i][29] < 210){
      fireWorkColor = pixels.Color(fireWorkAnimRed[1], fireWorkAnimGreen[1], fireWorkAnimBlue[1]);
    }
    //if the timer is in the 160 - 192 range...
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
    //if the timer gets close to 0, kill
    if(fireWorks[i][29] < 10){
      KillFirework(i);
    }
    //for each pixel in the firework
    for(int j=0; j<46; j++){
      //set the pixel color for every light in the fireWork array execpt the timer
      if(j != 29){
        pixels.setPixelColor(fireWorks[i][j], fireWorkColor);
      }
      uint32_t flicker = pixels.Color(255, 232, 36);
      //then for each light, check if it is one of the flicker values and set it
      for(int r=0; r<2; r++){
        if(randLight[r] != 29){
          if(j == randLight[r]){
            pixels.setPixelColor(fireWorks[i][j], flicker);
          }
        }
      }
    }
  }
    
  pixels.show();   // Send the updated pixel colors to the hardware.
}
