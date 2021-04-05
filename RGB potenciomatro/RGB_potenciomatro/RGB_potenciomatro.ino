const int analogPinA0 = A0;
const int analogPinA1 = A1;
const int analogPinA2 = A2;

int positionA0;   
int positionA1;   
int positionA2;   

const int LEDrojo = 9;
const int LEDverde = 10;
const int LEDazul = 11; 
void setup() 
{
  pinMode(LEDrojo,OUTPUT);
  pinMode(LEDverde,OUTPUT);
  pinMode(LEDazul,OUTPUT);
}
 
void loop() {
   positionA0 = map(analogRead(analogPinA0), 0, 1023, 0, 255); 
   positionA1 = map(analogRead(analogPinA1), 0, 1023, 0, 255);  
   positionA2 = map(analogRead(analogPinA2), 0, 1023, 0, 255);  

  analogWrite(LEDrojo,positionA0);
  analogWrite(LEDverde,positionA1);
  analogWrite(LEDazul,positionA2);
  
  delay(10);
}
