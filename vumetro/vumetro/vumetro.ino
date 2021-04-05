
//Volumetro

void setup()
{
 pinMode(22,OUTPUT);//LED verde
 pinMode(24,OUTPUT);//LED verde
 pinMode(26,OUTPUT);//LED verde
 pinMode(28,OUTPUT);//LED amarillo
 pinMode(30,OUTPUT);//LED amarillo
 pinMode(32,OUTPUT);//LED amarillo
 pinMode(34,OUTPUT);//LED rojo
 pinMode(36,OUTPUT);//LED rojo
}

void loop()
{
  int valor=analogRead(A0);
  valor=map(valor,0, 1023, 0, 8);
  
  switch(valor) {
  case 0:
   digitalWrite(22,LOW);//pin 22 apagado
   digitalWrite(24,LOW);//pin 24 apagado
   digitalWrite(26,LOW);//pin 26 apagado
   digitalWrite(28,LOW);//pin 28 apagado
   digitalWrite(30,LOW);//pin 30 apagado
   digitalWrite(32,LOW);//pin 32 apagado
   digitalWrite(34,LOW);//pin 34 apagado
   digitalWrite(36,LOW);//pin 36 apagado
   break;
  case 1:
   digitalWrite(22,HIGH);//pin 22 encendido
   digitalWrite(24,LOW);//pin 24 apagado
   digitalWrite(26,LOW);//pin 26 apagado
   digitalWrite(28,LOW);//pin 28 apagado
   digitalWrite(30,LOW);//pin 30 apagado
   digitalWrite(32,LOW);//pin 32 apagado
   digitalWrite(34,LOW);//pin 34 apagado
   digitalWrite(36,LOW);//pin 36 apagado
   break;
  case 2:
   digitalWrite(22,HIGH);//pin 22 encendido
   digitalWrite(24,HIGH);//pin 24 encendido
   digitalWrite(26,LOW);//pin 26 apagado
   digitalWrite(28,LOW);//pin 28 apagado
   digitalWrite(30,LOW);//pin 30 apagado
   digitalWrite(32,LOW);//pin 32 apagado
   digitalWrite(34,LOW);//pin 34 apagado
   digitalWrite(36,LOW);//pin 36 apagado
   break;
  case 3:
   digitalWrite(22,HIGH);//pin 22 encendido
   digitalWrite(24,HIGH);//pin 24 encendido
   digitalWrite(26,HIGH);//pin 26 encendido
   digitalWrite(28,LOW);//pin 28 apagado
   digitalWrite(30,LOW);//pin 30 apagado
   digitalWrite(32,LOW);//pin 32 apagado
   digitalWrite(34,LOW);//pin 34 apagado
   digitalWrite(36,LOW);//pin 36 apagado
   break;
  case 4:
   digitalWrite(22,HIGH);//pin 22 encendido
   digitalWrite(24,HIGH);//pin 24 encendido
   digitalWrite(26,HIGH);//pin 26 encendido
   digitalWrite(28,HIGH);//pin 28 encendido
   digitalWrite(30,LOW);//pin 30 apagado
   digitalWrite(32,LOW);//pin 32 apagado
   digitalWrite(34,LOW);//pin 34 apagado
   digitalWrite(36,LOW);//pin 36 apagado
   break;
  case 5:
   digitalWrite(22,HIGH);//pin 22 encendido
   digitalWrite(24,HIGH);//pin 24 encendido
   digitalWrite(26,HIGH);//pin 26 encendido
   digitalWrite(28,HIGH);//pin 28 encendido
   digitalWrite(30,HIGH);//pin 30 encendido
   digitalWrite(32,LOW);//pin 32 apagado
   digitalWrite(34,LOW);//pin 34 apagado
   digitalWrite(36,LOW);//pin 36 apagado
   break;
  case 6:
   digitalWrite(22,HIGH);//pin 22 encendido
   digitalWrite(24,HIGH);//pin 24 encendido
   digitalWrite(26,HIGH);//pin 26 encendido
   digitalWrite(28,HIGH);//pin 28 encendido
   digitalWrite(30,HIGH);//pin 30 encendido
   digitalWrite(32,HIGH);//pin 32 encendido
   digitalWrite(34,LOW);//pin 34 apagado
   digitalWrite(36,LOW);//pin 36 apagado
   break;
  case 7:
   digitalWrite(22,HIGH);//pin 22 encendido
   digitalWrite(24,HIGH);//pin 24 encendido
   digitalWrite(26,HIGH);//pin 26 encendido
   digitalWrite(28,HIGH);//pin 28 encendido
   digitalWrite(30,HIGH);//pin 30 encendido
   digitalWrite(32,HIGH);//pin 32 encendido
   digitalWrite(34,HIGH);//pin 34 encendido
   digitalWrite(36,LOW);//pin 36 apagado
   break;
  case 8:
   digitalWrite(22,HIGH);//pin 22 encendido
   digitalWrite(24,HIGH);//pin 24 encendido
   digitalWrite(26,HIGH);//pin 26 encendido
   digitalWrite(28,HIGH);//pin 28 encendido
   digitalWrite(30,HIGH);//pin 30 encendido
   digitalWrite(32,HIGH);//pin 32 encendido
   digitalWrite(34,HIGH);//pin 34 encendido
   digitalWrite(36,HIGH);//pin 36 encendido
   break;
  }
}


      
