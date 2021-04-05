
#include <Wire.h> //iniciamos las librerias
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);// codigo de la LCD

void setup()
{
 lcd.init();//se inicializa el LCD                      
 lcd.backlight();//Se conecta la iluminacion de la LCD
  
  lcd.begin(16,2);//posicion del texto
  lcd.print("   INCREMENTO");//imprimimos un texto
}


void loop()
{
  lcd.setCursor(0,1);//posicion del cursor
  lcd.print(millis()/1000);//imprimimos el tiempo en segundos
}
