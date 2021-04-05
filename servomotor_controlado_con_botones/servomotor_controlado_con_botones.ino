#include <Servo.h>

Servo myservo;
int servo=0;
 int botonderecha=40;
int botonizquierda=50;

void setup()
{
  myservo.attach(30); 
  pinMode(botonderecha,INPUT);
  pinMode(botonizquierda,INPUT);
}

void loop()
{
  if(digitalRead(botonderecha) == HIGH)
  {
    servo ++;
   if (servo > 190) servo = 0;
  }
  myservo.write(servo);
  delay(10);
  ////////////////////
  if(digitalRead(botonizquierda) == HIGH)
  {
    servo --;
   if (servo > 190) servo = 0;
  }
  myservo.write(servo);
  delay(10);
  
}




