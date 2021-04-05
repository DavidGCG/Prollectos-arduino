
#include <Keypad.h>

//empieza el codigo necesario
const byte filas=4;
const byte columnas=4;
byte pinsFilas[filas]={46,48,50,52};
byte pinsColumnas[columnas]={47,49,51,53};

char teclas[filas][columnas]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad teclado=Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas, filas, columnas);
//termina el codigo necesario

char tecla;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  tecla=teclado.getKey();
  if(tecla != NO_KEY) {
    Serial.print(tecla);
  }
}


