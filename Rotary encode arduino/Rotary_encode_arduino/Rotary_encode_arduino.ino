
 int outputA = 7;
 int outputB = 6;
 
const int BOTON = 9;
int estado=0;
int salida=0;

 int counter = 0; //Definimos el contador inicial a 0
 int aState;
 int aLastState; 
 int led=8; 
 int i =0;
void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode(BOTON,INPUT);
   pinMode (led,OUTPUT);
   Serial.begin (9600);
   aLastState = digitalRead(outputA);//Para leer el estado inicial de la salida A
 } 
 void loop() { 
   
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
  estado=digitalRead(BOTON);
 
 if(estado==HIGH){
     while (digitalRead(BOTON) == HIGH) {  } 
 delay(10); 
 }
   
  if ((estado== HIGH)&&(counter==LOW)){
    for(i=led; i<255; i++){ //Para incrementar el 
    analogWrite(led,i);     //encendido del LED
    delay(10);              //poco a poco
    }
    //analogWrite(led,255);
    counter=255;
    }
    else if ((estado== HIGH)&&(counter>=1)){
    analogWrite(led,0);
    counter=0;
    }

   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       
       counter ++;
       if(counter>255){counter=255;}//Para que el valor LED no sobrepaso de 255
     } else {
       counter --;
       if(counter<0){counter=0;}//Para que el valor LED no sea mener que 0
     }
     
     Serial.print("Position: ");
     Serial.println(counter);
     analogWrite(led,counter);
   } 
   aLastState = aState; //Para actializar el estadode la A
 }

