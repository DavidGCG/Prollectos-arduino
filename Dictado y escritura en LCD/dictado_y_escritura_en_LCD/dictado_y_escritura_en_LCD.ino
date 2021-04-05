
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  
String  mensaje;

void setup()
{
  lcd.init();                 
  lcd.backlight();
  Serial3.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  while(Serial3.available()){
    delay(10);
    char c= Serial3.read();
    mensaje += c;
  }
    if(mensaje.length()>0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(mensaje);
    }
    mensaje="";
 }


