#include<unistd.h>

int ledPin=13;
int inputPin=8;
int secondLedPin = 12;
int thirdLedPin = 11;

int pirState = LOW;

int val=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(secondLedPin,OUTPUT);
  pinMode(thirdLedPin,OUTPUT);

  pinMode(inputPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin);
  if (val== HIGH)
  {
    digitalWrite(ledPin,HIGH);
    if(pirState==LOW)
    {
      Serial.println("Motion detected!");
      pirState= HIGH;
      delay(2000);
      digitalWrite(ledPin,LOW);
      digitalWrite(secondLedPin,HIGH);
      delay(3000);
      digitalWrite(secondLedPin,LOW);
      digitalWrite(thirdLedPin,HIGH);
      delay(5000);
      digitalWrite(thirdLedPin,LOW);
      
    } 
  }
  else{
    digitalWrite(ledPin,LOW);
    if (pirState == HIGH)
    {
      Serial.println("Motion ended!");
      pirState= LOW;
    }
  }

}
