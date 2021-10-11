#include <Servo.h>

Servo xservo;  // objekat serva koji upravlja x osom
Servo yservo;  // objekat serva koji upravlja y osom

//Promenljive za servo
int pos = 0;       // Promenljiva koja cuva poziciju serva
int XServoPin = 9; // Pin za servo koji kontrolise X osom
int YServoPin = 8; // Pin za servo koji kontrolise Y osom

//Promenljive za dzojstik
int xposPin = A0;    // ulazni analog pin potenciometra na dzojstiku
int yposPin = A1;    // ulazni analog pin potenciometra na dzojstiku
int Xpos = 0;
int Ypos = 0;
int buttonPin = 7;
int buttonPress = 0;

//Promenljiva za laser
int lazerPin = 10;

void setup() {
  pinMode(lazerPin,OUTPUT);      // laser ce biti output
  pinMode(buttonPin,INPUT);      // pritisak dugmeta je input
  digitalWrite(buttonPin,HIGH);  // arduino pali pull-up za ovaj pin
  
  xservo.attach(XServoPin);  // povezuje servo na pin 9 sa servo objektom
  yservo.attach(YServoPin);  // povezuje servo na pin 8 sa servo objektom
}

void loop() {

  buttonPress = digitalRead(buttonPin); // cita stanje dugmeta
  if(buttonPress == LOW) // pritisak na dugme je nizak napon, ako se pritisne iskljucice laser
  {
    digitalWrite(lazerPin, HIGH); // pali laser
  }
  else
  {
    digitalWrite(lazerPin, LOW); // ako nije pritisnuto, zadrzi laser na off
  }
 
  Xpos = analogRead(xposPin);     // cita i cuva x lokaciju pozicije dzojstika
  Xpos = map(Xpos,0,1023,0,180);  // mapira analogne vrednosti x-a u 0-180 servo vrednosti
  Ypos = analogRead(yposPin);     // cita i cuva y lokaciju pozicije dzojstika
  Ypos = map(Ypos,0,1023,0,180);  // mapira analogne vrednosti y-a u 0-180 servo vrednosti
  xservo.write(Xpos);             // pomeri X lokaciju servo-a na x poziciju dzojstika
  yservo.write(Ypos);             // pomeri Y lokaciju servo-a na x poziciju dzojstika
  delay(50);                      // dodajemo malo kasnjenje da nam pomogne za dziterovanje
}
