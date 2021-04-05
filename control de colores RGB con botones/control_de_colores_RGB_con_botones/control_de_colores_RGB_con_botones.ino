
// Define los pines a utilizar para cada color  
int ledRojo=3;  
int ledAzul=4;  
int ledVerde=5;  
  
// Guarda los valores a signar a cada color (0-254)  
int ValorRojo=254;  
int ValorVerde=254;  
int ValorAzul=254;  
  
// Define los pines utilizados por los botones  
int BotonReducerojo = 24;  
int BotonIncrementarojo = 22;  
  
int BotonReduceverde = 30;  
int BotonIncrementaverde = 28;  
  
int BotonReduceazul = 36;  
int BotonIncrementaazul = 34;  
      

   
void setup()   
{   
  
  // Hay que indicar que lo pines utilizados por los botones son de ENTRADA  

  pinMode(BotonReducerojo, INPUT);  
  pinMode(BotonIncrementarojo, INPUT);  
  
  pinMode(BotonReduceverde, INPUT);  
  pinMode(BotonIncrementaverde, INPUT);
  
  pinMode(BotonReduceazul, INPUT);  
  pinMode(BotonIncrementaazul, INPUT);
    
}   
   
// Valor por defecto: Rojo  
// 0= Rojo, 1=Verde, 2=Azul  
int pinLedrojo = 0; 
int pinLedverde = 0;
int pinLedazul = 0;
   
void loop()   
{  
 //Rojo 
   {    
   int valorLedrojo = 0;  
  
   // Comprobamos si se incrementa el valor  
   if (digitalRead(BotonIncrementarojo) == HIGH)   
   {   
     if (pinLedrojo == 0) { ValorRojo++; }  
       
     delay(5);  
    }  
      // Comprobamos si se reduce el valor  
   if (digitalRead(BotonReducerojo) == HIGH)   
   {   
     if (pinLedrojo == 0) { ValorRojo--; }  
   
     delay(5);  
    }           
      // Esto para no pasarse de vueltas en el valor de salida (0-254)  
    if (ValorRojo > 254) { ValorRojo=254; }  
    if (ValorRojo < 0) { ValorRojo=0; }  
      
        
  
  // Actualiza el valor del color seleccionado  
  if (pinLedrojo == 0) { analogWrite(ledRojo, ValorRojo); }  
   }
   
   //verde
   {    
   int valorLedverde = 0;  
  
   // Comprobamos si se incrementa el valor  
   if (digitalRead(BotonIncrementaverde) == HIGH)   
   {   
     if (pinLedverde == 0) { ValorVerde++; }  
       
     delay(5);  
    }  
      // Comprobamos si se reduce el valor  
   if (digitalRead(BotonReduceverde) == HIGH)   
   {   
     if (pinLedverde == 0) { ValorVerde--; }  
   
     delay(5);  
    }           
      // Esto para no pasarse de vueltas en el valor de salida (0-254)  
    if (ValorVerde > 254) { ValorVerde=254; }  
    if (ValorVerde < 0) { ValorVerde=0; }  
      
        
  
  // Actualiza el valor del color seleccionado  
  if (pinLedverde == 0) { analogWrite(ledVerde, ValorVerde); }  
   }
   
   //azul
   {    
   int valorLedazul = 0;  
  
   // Comprobamos si se incrementa el valor  
   if (digitalRead(BotonIncrementaazul) == HIGH)   
   {   
     if (pinLedazul == 0) { ValorAzul++; }  
       
     delay(5);  
    }  
      // Comprobamos si se reduce el valor  
   if (digitalRead(BotonReduceazul) == HIGH)   
   {   
     if (pinLedazul == 0) { ValorAzul--; }  
   
     delay(5);  
    }           
      // Esto para no pasarse de vueltas en el valor de salida (0-254)  
    if (ValorAzul > 254) { ValorAzul=254; }  
    if (ValorAzul < 0) { ValorAzul=0; }  
      
        
  
  // Actualiza el valor del color seleccionado  
  if (pinLedazul == 0) { analogWrite(ledAzul, ValorAzul); }  
   }
   
}   
