
   const int a = 22;
   const int b = 24;
   const int c = 26;
   const int d = 28;
   const int e = 30;
   const int f = 32;
   const int g = 34;
   const int botonincremento = 36;
   const int botondecremento = 38;
   
   const int tiempoantirebote=10;
   int cuenta=0;
   int estadobotonincremento;
   int estadobotonanteriorincremento;
   int estadobotondecremento;
   int estadobotonanteriordecremento;
   
   boolean antirebote(int pin)
     {
       int contador=0;
       boolean estado;
       boolean estadoanterior;
       
       do {
         estado=digitalRead(pin);
         if(estado != estadoanterior) {
            contador=0;
            estadoanterior=estado;
         }
         else{
           contador=contador+1;
         }
         delay(1);
       }while(contador<tiempoantirebote);
       
       return estado;
     }
     
     void actualizarNumero()
     {
       switch(cuenta)
         {
       
   case 0:
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);    
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);
     break;
   case 1:
     digitalWrite(a,LOW);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);    
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);
     break;
   case 2:
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(c,LOW);    
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);
     break;
   case 3:
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);    
     digitalWrite(d,HIGH);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);
     break;
   case 4:
     digitalWrite(a,LOW);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);    
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);
     break;
   case 5:
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);    
     digitalWrite(d,HIGH);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);
     break;
   case 6:
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);    
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);
     break;
   case 7:
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);    
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);
     break;
   case 8:
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);    
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);
     break;
   case 9:
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);    
     digitalWrite(d,HIGH);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);
     break;
         }
     }
     
   void setup()
   {
     pinMode(a,OUTPUT);
     pinMode(b,OUTPUT);
     pinMode(c,OUTPUT);
     pinMode(d,OUTPUT);
     pinMode(e,OUTPUT);
     pinMode(f,OUTPUT);
     pinMode(g,OUTPUT);
     pinMode(botonincremento,INPUT);
     pinMode(botondecremento,INPUT);
     
     
   }
   
   void loop()
   {
     estadobotonincremento = digitalRead(botonincremento);
     if(estadobotonincremento != estadobotonanteriorincremento) {
       if(antirebote(botonincremento)) {
         cuenta++;
         if(cuenta > 9) {
           cuenta = 9;
         }
       }
     }
       estadobotonanteriorincremento =estadobotonincremento; 
       
       //////////////////////////////////
       
       estadobotondecremento = digitalRead(botondecremento);
     if(estadobotondecremento != estadobotonanteriordecremento) {
       if(antirebote(botondecremento)) {
         cuenta--;
         if(cuenta < 0) {
           cuenta = 0;
         }
       }
     }
       estadobotonanteriordecremento =estadobotondecremento;
      
      actualizarNumero();
   } 
       
       
