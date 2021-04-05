/*
Led IR
Apaga y enciende una televisión mediante un led IR.
*/
 
int ledIR =  13;         //Declaro pin para el led IR
 
void setup() {
pinMode(ledIR, OUTPUT);  //Configuro el pin 13 como salida
Serial.begin(9600);      //Inicio la comunicación serie
Serial.println("             led IR               ");
Serial.println("**********************************");
Serial.println("* Control TV:                    *");
Serial.println("**********************************");
Serial.println("* Encender/Apagar:               *");
Serial.println("*       barra espaciadora        *");
Serial.println("**********************************");
}
 
void loop(){
  int serie;                          //Almaceno los datos que llegan por serie
 
  while (Serial.available() > 0){     //Cuando hay datos para leer
 
    serie = Serial.read();            //Leo esos datos
 
    switch(serie){
      case ' ':         //Barra espaciadora
        emitirPulsos(); //Llamo a la función que emite los pulsos
        Serial.println("Enviado!");
        delay(2000);
        break;
      default:          //Si es otra cosa
        break;          //no hago nada
    }
  }
}
 
void emitirPulsos(){
  /*Aquí pegamos el código proporcionado por el anterior programa*/
  pulseIR(80);
  delayMicroseconds(7140);
  pulseIR(60);
  delayMicroseconds(7820);
  pulseIR(80);
  delayMicroseconds(4240);
  pulseIR(100);
  delayMicroseconds(7200);
  pulseIR(80);
  delayMicroseconds(1460);
  pulseIR(80);
  delayMicroseconds(6340);
  pulseIR(80);
  delayMicroseconds(11540);
  pulseIR(60);
  delayMicroseconds(280);
  pulseIR(120);
  delayMicroseconds(5760);
  pulseIR(60);
  delayMicroseconds(2160);
  pulseIR(120);
  delayMicroseconds(160);
  pulseIR(100);
  delayMicroseconds(11740);
  pulseIR(140);
  delayMicroseconds(580);
  pulseIR(60);
  delayMicroseconds(5440);
  pulseIR(280);
  delayMicroseconds(9600);
  pulseIR(160);
  delayMicroseconds(2840);
  pulseIR(160);
  delayMicroseconds(9420);
  pulseIR(100);
  delayMicroseconds(10220);
  pulseIR(80);
  delayMicroseconds(5420);
  pulseIR(120);
  delayMicroseconds(4720);
  pulseIR(480);
  delayMicroseconds(10280);
  pulseIR(60);
  delayMicroseconds(3280);
  pulseIR(80);
  delayMicroseconds(38100);
  pulseIR(140);
  delayMicroseconds(25520);
  pulseIR(80);
  delayMicroseconds(12400);
  pulseIR(60);
  delayMicroseconds(40780);
  pulseIR(120);
  delayMicroseconds(160);
  pulseIR(80);
  delayMicroseconds(39980);
  pulseIR(60);
  delayMicroseconds(4420);
  pulseIR(60);
  delayMicroseconds(11960);
  pulseIR(60);
  delayMicroseconds(8780);
  pulseIR(80);
  delayMicroseconds(7960);
  pulseIR(60);
  delayMicroseconds(12160);
  pulseIR(100);
  delayMicroseconds(42220);
  pulseIR(80);
  delayMicroseconds(38932);
  pulseIR(100);
  delayMicroseconds(3540);
  pulseIR(80);
  delayMicroseconds(51940);
  pulseIR(100);
}
 
void pulseIR(long microseg){
  /*Genera los pulsos de 38KHz de frecuencia
   durante x microsegundos.
     ·Parámetros: microseg*/
 
cli(); // desabilitamos cualquier interrupción
while (microseg > 0) {
  /*38KHz son aprox. 13microseg en HIGH y 13microseg en LOW
    la instrucción digitalWrite tarde 3microseg en ejecutarse
    por lo que hacemos dos delays de 10 en vez de 13.
    En total el ciclo dura 26microseg, cuando se completa,
    restamos al tiempo que tiene que estar mandando el pulso*/
digitalWrite(ledIR, HIGH);
delayMicroseconds(10);
digitalWrite(ledIR, LOW);
delayMicroseconds(10);
microseg -= 26;
}
sei(); // activa las interrupciones
}
