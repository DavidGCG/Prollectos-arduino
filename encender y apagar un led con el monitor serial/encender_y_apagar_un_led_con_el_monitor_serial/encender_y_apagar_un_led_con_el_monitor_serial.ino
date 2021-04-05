
int ledpin=13;

void setup()
{
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Introducir codigo:");
  while(Serial.available()==0);
  int variable=Serial.read() -'0';
  if (variable==0)
  {
    Serial.println(" El LED esta apagado");
    digitalWrite(ledpin,LOW);
  }
  else if (variable==1)
  {
    Serial.println(" El LED esta encendido");
    digitalWrite(ledpin,HIGH);
  }
  else
  {
    Serial.println(" codigo incorrecto");
  }
  Serial.flush();
  }
  



    
