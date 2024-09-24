#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

int Relay  = 5;                 // Digital pin D5

char data = 0;


void setup() {
  Serial.begin(9600);
  pinMode(Relay, OUTPUT);       // declare Relay as output
  pinMode(7,OUTPUT);//Blue LED when charger connected
  pinMode(6,OUTPUT);//green LED when fully charged
  pinMode(8,OUTPUT);//Red LED when charger disconnected
  tmrpcm.speakerPin=9;//speaker pin
  while (!Serial) 
  {
     // wait for serial port to connect. Needed for native USB port only
  }
  if(!SD.begin(4))
  {
   Serial.println("SD fail");
   return;
  }
  
}

void loop() {
  //Device connected
  if (Serial.available() > 0) // Send data only when you receive data:
  {
    data = Serial.read();      //Read the incoming data and store it into variable data
    if (data == 'A')           //Checks whether value of data is equal to "A"
    {
      Serial.begin(9600);
      digitalWrite(Relay, LOW);  //If value is "A" then Charger connected
      digitalWrite(7,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      tmrpcm.disable();
      tmrpcm.setVolume(7);
      tmrpcm.play("Connected.wav");
     
    }
    //Device Fully charged
    else if(data=='B'){
      Serial.begin(9600);
      digitalWrite(Relay,HIGH);
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(6,LOW); 
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("fullycharged.wav");
    }
    //Device disconnected due to disturbance
    else if(data=='C'){
      Serial.begin(9600);
      digitalWrite(Relay,HIGH);
      digitalWrite(8,HIGH);
      delay(1000);
      digitalWrite(8,LOW);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("chargerdisconnected.wav");
 
    }
    //Device charged 10%
    else if(data=='D'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("10.wav");
 
    }
    //Device charged 20%
    else if(data=='E'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("20.wav");
 
    }
    //Device charged 30%
    else if(data=='F'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("30.wav");
 
    }
    //Device charged 40%
    else if(data=='G'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("40.wav");
 
    }
    //Device charged 50%
    else if(data=='H'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("50.wav");
 
    }
    //Device charged 60%
    else if(data=='I'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("60.wav");
 
    }
    //Device charged 70%
    else if(data=='J'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("70.wav");
 
    }
    //Device charged 80%
    else if(data=='K'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("80.wav");
 
    }
    //Device charged 90%
    else if(data=='L'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("90.wav");
 
    }
    //ultrasonicSensor 
    else if(data=='M'){
      Serial.begin(9600);
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(6,LOW);
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("30cmfar.wav");
    }
     else if(data=='N'){
      Serial.begin(9600);
      digitalWrite(7,HIGH);
      delay(1000);
      digitalWrite(7,LOW);
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("reached.wav");
    }
    
}
}
