//HeTPro
//http://www.hetpro.com.mx
//Ejempo para el sensor sigue-lineas.
//qre1113
//Enviar datos de 8 bits por el serial
//Visualizarlos en processing
//Codigo de ejemplo adaptado de:
//http://boolscott.wordpress.com/2010/02/04/arduino-processing-analogue-bar-graph-2/
 
int Analogue0 = 0;
int Analogue1 = 0;
int Analogue2 = 0;
int Analogue3 = 0;
int Analogue4 = 0;
int Analogue5 = 0;
int inByte = 0;
void setup()
{
 
 Serial.begin(9600);
establishContact();
}
void loop()
{
  
 if (Serial.available() > 0) {
  
 inByte = Serial.read();
  
 Analogue0 = analogRead(0)/4;
  
 delay(10);
  
 Analogue1 = analogRead(1)/4;
  
 delay(10);
 Analogue2 = analogRead(2)/4;
 delay(10);
 Analogue3 = analogRead(3)/4;
 delay(10);
 Analogue4 = analogRead(4)/4;
 delay(10);
 Analogue5 = analogRead(5)/4;
 delay(10);
 
 Serial.write(Analogue0 );
 Serial.write(Analogue1 );
 Serial.write(Analogue2 );
 Serial.write(Analogue3 );
 Serial.write(Analogue4 );
 Serial.write(Analogue5 );
 }
}
void establishContact() {
 while (Serial.available() <= 0) {
 Serial.write('A');
 delay(300);
 }
}

