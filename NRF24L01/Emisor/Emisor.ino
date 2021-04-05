
//Emisor

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//comfiguracion de los pines CNS y CE
RF24 radio(7, 8); 

//Canal de comunicacion
const byte address[6] = "00001";

void setup() {
  //Iniciomos el objeto radio
  radio.begin();
  //Establece la direccion del receptor al que enviamos los datos
  radio.openWritingPipe(address);
  //Fijamos nivel de amplificador de energía
  radio.setPALevel(RF24_PA_MIN);
  //Establece el modulo como transmisor
  radio.stopListening();
}

void loop() {
  //Creamos el mensaje a enviar
  const char text[] = "Hello World";
  //Enciamos el mensaje
  radio.write(&text, sizeof(text));
  //Damos un retardo de 1 seg
  delay(1000);
}
