#include <nRF24L01.h>
#include <RF24.h>
#include<SPI.h>

RF24 radio(9,10);
const byte address[6] = "00001";

char input[32] = "";
const char var1[32] = "Mic";

double volume = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setChannel(100);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3);
  if(!radio.available())
    {
      Serial.println("radio unavailable");
    }
  if(radio.available())
    {
      radio.read(&input, sizeof(input));
      Serial.println(input);
      if((strcmp(input, var1)) == 0)
      {
        while(!radio.available());
        Serial.println("Still Available");
        radio.read(&volume, sizeof(volume));
        Serial.println(volume);
      }
 
    }

}
