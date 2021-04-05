
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//empieza el codigo necesario
const byte filas=4;
const byte columnas=4;
byte pinsFilas[filas]={22,24,26,28};
byte pinsColumnas[columnas]={23,25,27,29};

char teclas[filas][columnas]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad teclado=Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas, filas, columnas);
//termina el codigo necesario

char tecla;
String Datosleidos;
String contrase="1234";
int i=0;
void setup()
{
  lcd.init();
  lcd.backlight();
  //Serial.begin(9600);
}

void loop()
{
  tecla=teclado.getKey();
  if(tecla != NO_KEY && tecla !='A') {
    lcd.setCursor(0,0);
    lcd.print("Clave:         ");
    lcd.setCursor(i,1);
    lcd.print(tecla);
    Datosleidos +=tecla;
    i=i+1;
  }
  if(tecla == 'A'&& contrase == Datosleidos) {
  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.println("Clave corecta         ");
  i=0;
  Datosleidos="";
  }
  else if(tecla == 'A'&& contrase != Datosleidos){
  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.println("acceso denegado ");
  i=0;
  Datosleidos=""; 
  }
}
