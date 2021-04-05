#include <IRremote.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);
 
const int RECV_PIN = 9;
 
IRrecv irrecv(RECV_PIN);
decode_results results;

int BotonSelect = 8; 
int Grabar = 7; 

 long val0 = 0 ;
 long val1 =0; 
 long val2 =0 ;
 int pinLed = 0 ;

 long cod=0;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  lcd.init();
  lcd.backlight();  

  lcd.setCursor(0,0);
  lcd.print("Cod:");

     lcd.setCursor(0,1);
     lcd.print("Valor");
     lcd.setCursor(5,1);
     lcd.print("0");

  pinMode(BotonSelect, INPUT);
  pinMode(Grabar, INPUT);
}
 
void loop()
{
   if (digitalRead(BotonSelect) == HIGH)   
   {  
      pinLed++;     
      // Para no pasarnos de vueltas  
      if (pinLed > 2) { pinLed=0; }  

    lcd.setCursor(0,1);
     lcd.print("Valor");
     lcd.setCursor(5,1);
     lcd.print(pinLed);
     
      // Esperamos a que el boton se suelte  
      while (digitalRead(BotonSelect) == HIGH) {  }              
      delay(10); // Esperamos un poquito más...  
      lcd.clear();
   }

  if((irrecv.decode(&results))&& (pinLed == 0)) { 
     lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Cod:");
   //  lcd.setCursor(0,1);
   //  lcd.print("Valor");
     lcd.setCursor(5,1);
     lcd.print("0");
  val0=results.value,HEX;
  lcd.setCursor(0,3);
  lcd.print(val0,HEX);
  irrecv.resume();
    }
    if(pinLed == 0) { 
    lcd.setCursor(0,0);
    lcd.print("Cod:");
    lcd.setCursor(0,1);
    lcd.print("Valor");
    lcd.setCursor(5,1);
    lcd.print("0");
    lcd.setCursor(0,3);
    lcd.print(val0,HEX);
    }
    
    if((irrecv.decode(&results))&& (pinLed == 1)) { 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Cod:");
    lcd.setCursor(0,1);
    lcd.print("Valor");
    lcd.setCursor(5,1);
    lcd.print("1");
    val1=results.value,HEX;
    lcd.setCursor(0,3);
    lcd.print(val1,HEX);
    irrecv.resume();
    }
    if(pinLed == 1) {
    lcd.setCursor(0,0);
    lcd.print("Cod:");
    lcd.setCursor(0,1);
    lcd.print("Valor");
    lcd.setCursor(5,1);
    lcd.print("1"); 
    lcd.setCursor(0,3);
    lcd.print(val1,HEX);
    }
    
    if((irrecv.decode(&results))&& (pinLed == 2)) { 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Cod:");
    lcd.setCursor(0,1);
    lcd.print("Valor");
    lcd.setCursor(5,1);
    lcd.print("2");
    val2=results.value,HEX;
    lcd.setCursor(0,3);
    lcd.print(val2,HEX);
    irrecv.resume();
    }
    if(pinLed == 2) { 
   lcd.setCursor(0,0);
   lcd.print("Cod:");
   lcd.setCursor(0,1);
   lcd.print("Valor");
   lcd.setCursor(5,1);
   lcd.print("2");
   lcd.setCursor(0,3);
   lcd.print(val2,HEX);
    }  

      //Para grabar datos
    if (digitalRead(Grabar) == HIGH)
    {
      Serial.println(val0,HEX);
      Serial.println(val1,HEX);
      Serial.println(val2,HEX);
      Serial.println(' ');
    }
      while (digitalRead(Grabar) == HIGH) {  }              
      delay(10); // Esperamos un poquito más...  
    
}
