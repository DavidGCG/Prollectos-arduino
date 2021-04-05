
int rojo = 8;
int verde = 9;
int azul = 10;
int time=100;

void setup() {                
  pinMode(rojo, OUTPUT); 
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
}

void loop() {
  for(int i=0;i<=255;i++){  
  digitalWrite(azul,HIGH);  
  analogWrite(rojo,i);
  delay(time);  
  }
for(int i=255;i>=0;i--){  
  analogWrite(azul,i); 
  delay(time);  
}
for(int i=0;i<=255;i++){  
  analogWrite(verde,i);
  delay(time);  
  }
for(int i=255;i>=0;i--){  
  analogWrite(rojo,i);
  delay(time);  
} 
for(int i=0;i<=255;i++){  
  analogWrite(azul,i); 
  delay(time);  
  }
for(int i=255;i>=0;i--){  
  analogWrite(verde,i);
  
  delay(time);  
} 
  
}

