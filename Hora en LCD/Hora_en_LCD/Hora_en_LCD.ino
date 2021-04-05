
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include "RTClib.h"
RTC_DS1307 RTC;
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Wire.begin(); // Inicia el puerto I2C
  RTC.begin(); // Inicia la comunicación con el RTC

}
void loop()
{
  DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
lcd.setCursor(3,0);
lcd.print(now.year(), DEC); // Año
lcd.print('/');
lcd.print(now.month(), DEC); // Mes
lcd.print('/');
lcd.print(now.day(), DEC); // Dia
lcd.print(' ');
  lcd.setCursor(4,1);

lcd.print(now.hour(), DEC); // Horas
lcd.print(':');
lcd.print(now.minute(), DEC); // Minutos
lcd.print(':');
lcd.print(now.second(), DEC); // Segundos
lcd.print(' ');
delay(1000); // La información se actualiza cada 1 seg.
}
