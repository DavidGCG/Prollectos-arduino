
int led=13;
int boton=22;
boolean contador=true;
int val=0;

void setup() {                
  pinMode(led,OUTPUT);
  pinMode(boton,INPUT);
}

void loop() {
  val= digitalRead(boton); 
if(val== HIGH) {
  if(contador==true){
  digitalWrite(led, HIGH);   
  delay(10); 
  contador=false;
  }else{
    contador=true;
    digitalWrite(led, LOW);   
  delay(10);
  }
}
}

