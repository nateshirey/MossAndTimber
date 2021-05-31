#include <nRF24L01.h>
#include <RF24.h>
#include<SPI.h>

RF24 radio(9,10);
const byte address[6] = "00001";

#define mic A0
int micValue = 0;

const int sampleWindow = 10; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;


const char var1[32] = "Mic";
double micLevel = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setChannel(100);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long startMillis= millis();  // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level
 
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;
  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
     sample = analogRead(A0);
     if (sample < 1024)  // toss out spurious readings
     {
        if (sample > signalMax)
        {
           signalMax = sample;  // save just the max levels
        }
        else if (sample < signalMin)
        {
           signalMin = sample;  // save just the min levels
        }
     }
  }
  peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
  double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
 
  Serial.println(volts);
  double threshold = 2;

  radio.write(&var1, sizeof(var1));
  micValue = volts;
  radio.write(&micValue, sizeof(micValue));
}
