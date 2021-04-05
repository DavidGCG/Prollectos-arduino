int ledGreen = 9;
int ledRed = 10;
int potPin = 0;

void setup(){

}

void loop () {
  int value = analogRead(potPin);
  int redValue = map(value,0,1023,0,255);
  int greenValue = map(value,0,1023,255,0);
  analogWrite(ledRed,redValue);
  analogWrite(ledGreen,greenValue);
}
