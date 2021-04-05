
const int VRxpin=0;
const int VRypin=1;

const int SwButonpin=8;
int pressed=-1;
int x=-1;
int y=-1;

void readJoystick()
{
  pressed=digitalRead(SwButonpin);
  x=analogRead(VRxpin);
  y=analogRead(VRypin);

}

void setup()
{
  pinMode(SwButonpin,INPUT);
  digitalWrite(SwButonpin,HIGH);
  Serial.begin(115200);
}
void loop()
{
  readJoystick();
  
  Serial.print("X");
  Serial.println(x);
  
  Serial.print("Y");
  Serial.println(y);
  
  Serial.print("press");
  Serial.println(pressed);

  delay(200);
}
