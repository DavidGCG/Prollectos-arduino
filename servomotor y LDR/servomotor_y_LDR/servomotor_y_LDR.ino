#include <Servo.h>

Servo myservo;
int potpin = 0;
int val;

void setup()
{
  Serial.begin(9600);
  myservo.attach(22);
}

void loop() {
  val = analogRead(potpin);
  Serial.println(val);
  
  val = map(val, 0, 1023, 0, 179);
  
  myservo.write(val);
  
  delay(100);
}
