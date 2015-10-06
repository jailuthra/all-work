#include<Arduino.h>

/*
  DigitalRead
 Reads a digital input on pin 2, lights led accordingly
 
 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
int led = 13;

// the setup routine runs once when you press reset:
void setup() {
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  // make led as output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  if (buttonState) digitalWrite(led, HIGH);
  else digitalWrite(led,LOW);
  // print out the state of the button:
  delay(1);        // delay in between reads for stability
}
