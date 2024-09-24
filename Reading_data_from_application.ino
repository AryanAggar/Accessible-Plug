
#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

char data = 0; //Variable for storing received data

void setup()
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(5, OUTPUT);        //Sets digital pin 13 as output pin
  tmrpcm.speakerPin=9;

}
void loop()
{
  if (Serial.available() > 0) // Send data only when you receive data:
  {
    data = Serial.read();      //Read the incoming data and store it into variable data
    if (data == 'A')           //Checks whether value of data is equal to "A"
    {
      Serial.begin(9600);
      digitalWrite(5, HIGH);  //If value is "A" then LED turns O
      if(!SD.begin(4))
      {
       Serial.println("SD fail");
       return;
      }
      tmrpcm.setVolume(6);
      tmrpcm.play("songkal.wav");
    }
    else if (data == 'B')      //Checks whether value of data is equal to "B"
      digitalWrite(5, LOW);   //If value is "B" then LED turns OFF
  }
}
