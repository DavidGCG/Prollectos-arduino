
/*********************************** 
  Tutorial Diodos LED Tricolor y Pulsadores   
  Oscar Gonzalez - Marzo 2009 
  www.BricoGeek.com 
   
  Debes conectar el Diodo LED RGB según los pines de configuración indicados como 
  "ledRojo", "ledAzul" y "ledVerde". Lo mismo para los botones, con sus respectivas 
  resistencias como indicado en el video tutorial. 
   
  Básicamente se trata de enviar un valor de entre 0 y 254 a cada color mediante la función analogWrite() a la cual 
  indicamos el PIN a utilizar y el valor a enviar. Podemos utilizar otros pines, pero es muy importante utilizar los pines 
  indicados como "PWM" ya que de no utilizarlo, no podremos variar el color y el programa no tendrá efecto alguno. 
   
  Utiliza éste código como mejor te guste ya que es totalmente libre, aunque siempr ese agradece algún comentario 
  sobre el autor original! :) 
   
 ************************************/  
  
// Define los pines a utilizar para cada color  
int ledRojo=3;  
int ledAzul=4;  
int ledVerde=5;  
  
// Guarda los valores a signar a cada color (0-254)  
int ValorRojo=254;  
int ValorVerde=254;  
int ValorAzul=254;  
  
// Define los pines utilizados por los botones  
int BotonSelect = 8;  
int BotonReduce = 9;  
int BotonIncrementa = 10;  
  
int ledSeleccionado = 0;  
   
void setup()   
{   
  
  // Hay que indicar que lo pines utilizados por los botones son de ENTRADA  
  pinMode(BotonSelect, INPUT);  
  pinMode(BotonReduce, INPUT);  
  pinMode(BotonIncrementa, INPUT);  
    
  analogWrite(ledRojo, 255);    
}   
   
// Valor por defecto: Rojo  
// 0= Rojo, 1=Verde, 2=Azul  
int pinLed = 0;  
   
void loop()   
{   
       
   int valorLed = 0;  
  
   if (digitalRead(BotonSelect) == HIGH)   
   {  
      pinLed++;    
        
      // Para no pasarnos de vueltas  
      if (pinLed > 2) { pinLed=0; }  
     
      // Apagamos todos los LED ya qu eluego se mostrarÃ¡ sÃ³lo el led seleccionado  
      analogWrite(ledRojo, 0);  
      analogWrite(ledVerde, 0);  
      analogWrite(ledAzul, 0);        
        
      // Esperamos a que el boton se suelte  
      while (digitalRead(BotonSelect) == HIGH) {  }              
      delay(10); // Esperamos un poquito más...  
   }  
    
   // Comprobamos si se incrementa el valor  
   if (digitalRead(BotonIncrementa) == HIGH)   
   {   
     if (pinLed == 0) { ValorRojo++; }  
     if (pinLed == 1) { ValorVerde++; }  
     if (pinLed == 2) { ValorAzul++; }  
       
     delay(5);  
    }  
      
   // Comprobamos si se reduce el valor  
   if (digitalRead(BotonReduce) == HIGH)   
   {   
     if (pinLed == 0) { ValorRojo--; }  
     if (pinLed == 1) { ValorVerde--; }  
     if (pinLed == 2) { ValorAzul--; }  
       
     delay(5);  
    }           
      
    // Esto para no pasarse de vueltas en el valor de salida (0-254)  
    if (ValorRojo > 254) { ValorRojo=254; }  
    if (ValorRojo < 0) { ValorRojo=0; }  
      
    if (ValorVerde > 254) { ValorVerde=254; }  
    if (ValorVerde < 0) { ValorVerde=0; }  
  
    if (ValorAzul > 254) { ValorAzul=254; }  
    if (ValorAzul < 0) { ValorAzul=0; }      
  
  // Actualiza el valor del color seleccionado  
  if (pinLed == 0) { analogWrite(ledRojo, ValorRojo); }  
  if (pinLed == 1) { analogWrite(ledVerde, ValorVerde); }  
  if (pinLed == 2) { analogWrite(ledAzul, ValorAzul); }  
    
} 
