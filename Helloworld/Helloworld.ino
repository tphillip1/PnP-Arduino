const int LEDPin = 13;//declare the LED port (hard-wired on arduino)
int incomingByte;
void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);//set the LED pin as output mode
  Serial.begin(115200);
}

void loop() {
  //see if there's incoming serial data:
  if(Serial.available() > 0) { //read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if its > 0, turn on the LED:
    if (incomingByte > 0)
      digitalWrite(LEDPin, HIGH);
    //if its = 0, turn off the LED;
    if (incomingByte == 0)
      digitalWrite(LEDPin, LOW);
      //feed back the byte:
      Serial.println(incomingByte);
    
  }
 //this is to blink the LED // put your main code here, to run repeatedly:
  //digitalWrite(LED, HIGH);
  //Serial.println("LED up!");
  //delay(5000);
  //digitalWrite(LED, LOW);
  //Serial.println("LED Down!");
  //delay(2000);
}
