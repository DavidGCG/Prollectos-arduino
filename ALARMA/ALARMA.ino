/*
Boton de alarma
*/

int pinLed1=40;//Configuramos el Led1 en el pin40
int pinLed2=42;//Configuramos el Led2 en el pin42
int boton=30;//Configuramos el boton en el pin 30
int zumb=9;//Configuramos el altavoz en el pin 9 PWM
int notas[]={1915,1700,1519,1432,1275,1136,1014};//Definir la matriz de 8 notas
int tnota=150;//Tiempo del tono
int n=0;
int m=0;

void setup()
{
  pinMode(pinLed1,OUTPUT);//Configuramos el pinLed1 como salida
  pinMode(pinLed2,OUTPUT);//Configuramos el pinLed2 como salida
  pinMode(zumb,OUTPUT);//Configuramos el altavoz comosalida
  pinMode(boton,INPUT);//Configuramos el boton como entrada
  
}
void nota(){//Rutina que generan los tonos de llamada
for(m=0;m<=tnota;m++){
  digitalWrite(zumb,HIGH);
  delayMicroseconds(notas[n]);
  digitalWrite(zumb,LOW);
  delayMicroseconds(notas[n]);
}
}


void loop()
{
 
 
  if(digitalRead(boton)==HIGH){
    
    digitalWrite(pinLed1,HIGH);//parpadea el LED
    n=6;//Elegimos la primera nota del timbre
    nota();//Aqui es la primera de la cadena
    delay(10);
   
digitalWrite(pinLed1,LOW);

digitalWrite(pinLed2,HIGH);
    n=0;//Elegimos la primera nota del timbre
    nota();//Aqui es la primera de la cadena
    delay(10);
digitalWrite(pinLed2,LOW);

    }
  }


  


