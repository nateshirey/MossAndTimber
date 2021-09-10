#include <Wire.h>

int number = 0;

void setup(){
  Wire.begin(0x04);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop(){
  delay(100);
}

void receiveData(int byteCount){
  while(Wire.available()){
    number = Wire.read();
    Serial.print("Received: ");
    Serial.println(number);

    if(number == 1){
      Serial.println("Lightning");
    }
  }
  int x = Wire.read();
  Serial.println(x);
}

void sendData(){
  Wire.write(number);
}
