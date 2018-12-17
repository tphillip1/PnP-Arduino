#include <Servo.h>

Servo myservo;

int pos = 0;
const int LEDPin = 13;//declare the LED port (hard-wired on arduino)
int incomingByte;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LEDPin, OUTPUT);
  myservo.attach(9); //attached to pin 9 
}

void loop() {
  // put your main code here, to run repeatedly:
  //int pos = 180;
  //int neg = 0;
  if(Serial.available() > 0) { //read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if its > 0, turn on the LED:

    
    if (incomingByte > 0)
     { 
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
       myservo.write(pos);              // tell servo to go to position in variable 'pos'
       delay(15);  

       digitalWrite(LEDPin, HIGH);
      //myservo.write();
      delay(150);
      }
      
      //myservo.write(0);
      //delay(150);
     }
    //if its = 0, turn off the LED;
    //if (incomingByte == 0)
      //digitalWrite(LEDPin, LOW);
      
      
      //feed back the byte:
      Serial.println(incomingByte);
}
}
