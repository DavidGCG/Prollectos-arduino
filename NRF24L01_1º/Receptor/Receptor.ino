
//Receptor

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//comfiguracion de los pines CNS y CE
RF24 radio(7, 8);

//Canal de comunicacion
const byte address[6] = "00001";

void setup() {
  //Iniciamos el puerto serie a 9600
  Serial.begin(9600);
  //Iniciomos el objeto radio
  radio.begin();
  //Establece la direccion del receptor al que recibe los datos
  radio.openReadingPipe(0, address);
  //Fijamos nivel de amplificador de energía
  radio.setPALevel(RF24_PA_MIN);
  //Establece el modulo como receptor
  radio.startListening();
}

void loop() {
  //Si hay datos disponobles
  if (radio.available()) {
    //Creamos un arrat de 32 elementos
    char text[32] = "";
    //Leemos y almacenamos los datos
    radio.read(&text, sizeof(text));
    //Imprimimos el valor por el puerto serie
    Serial.println(text);
  }
}
