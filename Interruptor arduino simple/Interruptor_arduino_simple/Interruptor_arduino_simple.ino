
const int BOTON = 8;
const int LED = 7;
int estado=0;
int salida=0;

void setup() {
  pinMode(BOTON,INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
estado=digitalRead(BOTON);

if(estado==HIGH){
  salida=1-salida;
  while (digitalRead(BOTON) == HIGH) {  } 
 delay(10); 
 }
 if(salida==1)
 {
   digitalWrite(LED,HIGH);
   }else{
   digitalWrite(LED,LOW);
 }  
 }
