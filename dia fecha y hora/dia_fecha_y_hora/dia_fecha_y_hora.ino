#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

RTC_DS1307 RTC;
int a =0;
void setup () {
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Wire.begin(); // Inicia el puerto I2C
 RTC.begin(); 
Serial.begin(9600); 
}
char dia=0;

void loop () {
DateTime now = RTC.now();

 
  switch(now.dayOfWeek())
  {
    case 1:
lcd.setCursor(3,0);
lcd.print(now.day(), DEC); // Año
lcd.print('/');
lcd.print(now.month(), DEC); // Mes
lcd.print('/');
lcd.print(now.year(), DEC); // Dia
lcd.print(' ');
lcd.setCursor(0,1);
lcd.print("Lunes"); // Horas
lcd.print(' ');
lcd.print(' ');
lcd.print(now.hour(), DEC); // Horas
lcd.print(':');
lcd.print(now.minute(), DEC); // Minutos
lcd.print(':');
lcd.print(now.second(), DEC); // Segundos
lcd.print(' ');
break;
    
    case 2:
lcd.setCursor(3,0);
lcd.print(now.day(), DEC); // Año
lcd.print('/');
lcd.print(now.month(), DEC); // Mes
lcd.print('/');
lcd.print(now.year(), DEC); // Dia
lcd.print(' ');
lcd.setCursor(0,1);
lcd.print("Martes"); // Horas
lcd.print(' ');
lcd.print(' ');
lcd.print(now.hour(), DEC); // Horas
lcd.print(':');
lcd.print(now.minute(), DEC); // Minutos
lcd.print(':');
lcd.print(now.second(), DEC); // Segundos
lcd.print(' ');
break;
    
    case 3:
lcd.setCursor(3,0);
lcd.print(now.day(), DEC); // Año
lcd.print('/');
lcd.print(now.month(), DEC); // Mes
lcd.print('/');
lcd.print(now.year(), DEC); // Dia
lcd.print(' ');
lcd.setCursor(0,1);
lcd.print("Miercoles"); // Horas
lcd.print(' ');
lcd.print(' ');
lcd.print(now.hour(), DEC); // Horas
lcd.print(':');
lcd.print(now.minute(), DEC); // Minutos
lcd.print(':');
lcd.print(now.second(), DEC); // Segundos
lcd.print(' ');
break;
    
    case 4:
lcd.setCursor(3,0);
lcd.print(now.day(), DEC); // Año
lcd.print('/');
lcd.print(now.month(), DEC); // Mes
lcd.print('/');
lcd.print(now.year(), DEC); // Dia
lcd.print(' ');
lcd.setCursor(0,1);
lcd.print("Jueves"); // Horas
lcd.print(' ');
lcd.print(' ');
lcd.print(now.hour(), DEC); // Horas
lcd.print(':');
lcd.print(now.minute(), DEC); // Minutos
lcd.print(':');
lcd.print(now.second(), DEC); // Segundos
lcd.print(' ');
break;
    
    case 5:
lcd.setCursor(3,0);
lcd.print(now.day(), DEC); // Año
lcd.print('/');
lcd.print(now.month(), DEC); // Mes
lcd.print('/');
lcd.print(now.year(), DEC); // Dia
lcd.print(' ');
lcd.setCursor(0,1);
lcd.print("Viernes"); // Horas
lcd.print(' ');
lcd.print(' ');
lcd.print(now.hour(), DEC); // Horas
lcd.print(':');
lcd.print(now.minute(), DEC); // Minutos
lcd.print(':');
lcd.print(now.second(), DEC); // Segundos
lcd.print(' ');
break;
    
    case 6:
lcd.setCursor(3,0);
lcd.print(now.day(), DEC); // Año
lcd.print('/');
lcd.print(now.month(), DEC); // Mes
lcd.print('/');
lcd.print(now.year(), DEC); // Dia
lcd.print(' ');
lcd.setCursor(0,1);
lcd.print("Sabado"); // Horas
lcd.print(' ');
lcd.print(' ');
lcd.print(now.hour(), DEC); // Horas
lcd.print(':');
lcd.print(now.minute(), DEC); // Minutos
lcd.print(':');
lcd.print(now.second(), DEC); // Segundos
lcd.print(' ');
break;
    
    case 7:
lcd.setCursor(3,0);
lcd.print(now.day(), DEC); // Año
lcd.print('/');
lcd.print(now.month(), DEC); // Mes
lcd.print('/');
lcd.print(now.year(), DEC); // Dia
lcd.print(' ');
lcd.setCursor(0,1);
lcd.print("Domingo"); // Horas
lcd.print(' ');
lcd.print(' ');
lcd.print(now.hour(), DEC); // Horas
lcd.print(':');
lcd.print(now.minute(), DEC); // Minutos
lcd.print(':');
lcd.print(now.second(), DEC); // Segundos
lcd.print(' ');
break;
    
}
delay(1000); 
}
