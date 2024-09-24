int Relay  = 5;                 // Digital pin D5
char data = 0;
void setup() {
  Serial.begin(9600);
  pinMode(Relay, OUTPUT);       // declare Relay as output
}

void loop() {
  if (Serial.available() > 0) // Send data only when you receive data:
  {
    data = Serial.read();      //Read the incoming data and store it into variable data
    //Charger connected
    if (data == 'A')           //Checks whether value of data is equal to "A"
    {
      Serial.begin(9600);
      digitalWrite(Relay, LOW);  //If value is "A" then LED turns O/Blue light  
    }
    else if(data=='B'){
      Serial.begin(9600);
      digitalWrite(Relay,HIGH);
    }
}
}
