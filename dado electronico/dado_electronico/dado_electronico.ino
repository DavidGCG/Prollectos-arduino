
//Dado electronico
int valor=1;//valor es igual a 1
int a=22;//configuramos el pin a en el pin 22
int b=24;//configuramos el pin b en el pin 24
int c=26;//configuramos el pin c en el pin 26
int d=28;//configuramos el pin d en el pin 28
int e=30;//configuramos el pin e en el pin 30
int f=32;//configuramos el pin f en el pin 32
int g=34;//configuramos el pin g en el pin 34

void setup()
{
  pinMode(a,OUTPUT);//declaramos a como salida
  pinMode(b,OUTPUT);//declaramos b como salida
  pinMode(c,OUTPUT);//declaramos c como salida
  pinMode(d,OUTPUT);//declaramos d como salida
  pinMode(e,OUTPUT);//declaramos e como salida
  pinMode(f,OUTPUT);//declaramos f como salida
  pinMode(g,OUTPUT);//declaramos g como salida
}

void loop()
{
  if(analogRead(A1>10)) {//si a1 esta precionado asta 10=encendido
    valor++;//incrementar en 1
    delay(15);//esperar
  }
  if(valor==7){//cuando el valor sea igual a 7
    valor=1;//volver al valor 1
    delay(15);//esperar
  }
  switch(valor){//donde se escriben los casos
    case 1://1
       digitalWrite(a,LOW);//pin a en bajo 
       digitalWrite(b,HIGH);//pin b en alto
       digitalWrite(c,HIGH);//pin c en alto
       digitalWrite(d,LOW);//pin d en bajo
       digitalWrite(e,LOW);//pin e en bajo
       digitalWrite(f,LOW);//pin f en bajo
       digitalWrite(g,LOW);//pin g en bajo
       break;
    case 2://2
       digitalWrite(a,HIGH);//pin a en alto
       digitalWrite(b,HIGH);//pin b en alto
       digitalWrite(c,LOW);//pin c en bajo
       digitalWrite(d,HIGH);//pin d en alto
       digitalWrite(e,HIGH);//pin e en alto
       digitalWrite(f,LOW);//pin f en bajo
       digitalWrite(g,HIGH);//pin g en alto
       break;
    case 3://3
       digitalWrite(a,HIGH);//pin a en alto
       digitalWrite(b,HIGH);//pin b en alto
       digitalWrite(c,HIGH);//pin c en alto
       digitalWrite(d,HIGH);//pin d en alto
       digitalWrite(e,LOW);//pin e en bajo
       digitalWrite(f,LOW);//pin f en bajo
       digitalWrite(g,HIGH);//pin g en alto
       break;
    case 4://4
       digitalWrite(a,LOW);//pin a en bajo
       digitalWrite(b,HIGH);//pin b en alto
       digitalWrite(c,HIGH);//pin c en alto
       digitalWrite(d,LOW);//pin d en bajo
       digitalWrite(e,LOW);//pin e en bajo
       digitalWrite(f,HIGH);//pin f en alto
       digitalWrite(g,HIGH);//pin g en alto
       break;
    case 5://5
       digitalWrite(a,HIGH);//pin a en alto
       digitalWrite(b,LOW);//pin b en bajo
       digitalWrite(c,HIGH);//pin c en alto
       digitalWrite(d,HIGH);//pin d en alto
       digitalWrite(e,LOW);//pin e en bajo
       digitalWrite(f,HIGH);//pin f en alto
       digitalWrite(g,HIGH);//pin g en alto
       break;
    case 6://6
       digitalWrite(a,HIGH);//pin a en alto
       digitalWrite(b,LOW);//pin b en bajo
       digitalWrite(c,HIGH);//pin c en alto
       digitalWrite(d,HIGH);//pin d en alto
       digitalWrite(e,HIGH);//pin e en alto
       digitalWrite(f,HIGH);//pin f en alto
       digitalWrite(g,HIGH);//pin g en alto
       break;
  }
}
   
  
