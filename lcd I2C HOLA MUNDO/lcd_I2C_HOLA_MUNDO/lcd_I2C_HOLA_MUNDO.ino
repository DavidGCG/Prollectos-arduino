//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("HOLA, MUNDO");
  lcd.setCursor(2,1);
  lcd.print(" COMO ESTAS =ñ");
}


void loop()
{
}
