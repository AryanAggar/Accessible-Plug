#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

int Relay  = 2;                 // Digital pin D5
int Relay1 =3;
int redPin= 7;
int greenPin = 6;
int bluePin = 5;
char data = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Relay, OUTPUT);       // declare Relay as output
  pinMode(Relay1, OUTPUT);       // declare Relay as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
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
      setColor(0, 0, 255); // Blue Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(7);
      tmrpcm.play("agartum.wav");
     
    }
    //Device Fully charged
    else if(data=='B'){
      Serial.begin(9600);
      digitalWrite(Relay,HIGH);
      setColor(0, 255, 0); // Green Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("agartum.wav");
    }
    //Device disconnected due to disturbance
    else if(data=='C'){
      Serial.begin(9600);
      digitalWrite(Relay,HIGH);
      setColor(255, 0, 0); // Red Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("agartum.wav");
 
    }
    //Device charged 10%
    else if(data=='D'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      setColor(170, 0, 255); // Purple Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("agartum.wav");
 
    }
    //Device charged 20%
    else if(data=='E'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      setColor(170, 0, 255); // Purple Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("agartum.wav");
 
    }
    //Device charged 30%
    else if(data=='F'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      setColor(170, 0, 255); // Purple Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("agartum.wav");
 
    }
    //Device charged 40%
    else if(data=='G'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      setColor(170, 0, 255); // Purple Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("agartum.wav");
 
    }
    //Device charged 50%
    else if(data=='H'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      setColor(170, 0, 255); // Purple Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("agartum.wav");
 
    }
    //Device charged 60%
    else if(data=='I'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      setColor(170, 0, 255); // Purple Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("agartum.wav");
 
    }
    //Device charged 70%
    else if(data=='J'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      setColor(170, 0, 255); // Purple Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("agartum.wav");
 
    }
    //Device charged 80%
    else if(data=='K'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      setColor(170, 0, 255); // Purple Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("agartum.wav");
 
    }
    //Device charged 90%
    else if(data=='L'){
      Serial.begin(9600);
      digitalWrite(Relay,LOW);
      setColor(170, 0, 255); // Purple Color
      delay(1000);
      tmrpcm.disable();
      tmrpcm.setVolume(6);
      tmrpcm.play("agartum.wav");
 
    }
    
}
}
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
} 
