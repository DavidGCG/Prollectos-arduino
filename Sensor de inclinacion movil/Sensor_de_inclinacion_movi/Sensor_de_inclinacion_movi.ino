int led1=6;
int led2=9;
int led3=10;
int led4=11;
int vel = 255;
int estado='g';

void setup(){
  Serial3.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
                  }

void loop(){
 if(Serial3.available()>0){
 estado = Serial3.read();
 }
 
 
 if (estado =='5'){
   digitalWrite(led1,HIGH);
   digitalWrite(led2,0);
   digitalWrite(led3,HIGH);
   digitalWrite(led4,0);
  }
  if (estado =='4'){//delante
   digitalWrite(led1,LOW);
   digitalWrite(led2,HIGH);
   digitalWrite(led3,LOW);
   digitalWrite(led4,HIGH);
  }
  if (estado =='3'){
   digitalWrite(led1,LOW);
   digitalWrite(led2,HIGH);
   digitalWrite(led3,HIGH);
   digitalWrite(led4,LOW);
  }
  if (estado =='2'){//izq
   digitalWrite(led1,HIGH);
   digitalWrite(led2,LOW);
   digitalWrite(led3,LOW);
   digitalWrite(led4,HIGH);
  }
  if (estado =='1'){
   digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(led3,LOW);
   digitalWrite(led4,LOW);
  }
  
  

}    
