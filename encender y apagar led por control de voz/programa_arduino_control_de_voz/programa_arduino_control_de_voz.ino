
String mensaje;

void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop()
{
  while(Serial.available())
  {
    delay(10);
    char c = Serial.read();
    mensaje += c;
  }
  if(mensaje.length()>0)
  {
    if(mensaje=="encender LED"){digitalWrite(13,HIGH);}
    else if (mensaje=="apagar LED"){digitalWrite(13,LOW);}
  }
  mensaje="";
}

