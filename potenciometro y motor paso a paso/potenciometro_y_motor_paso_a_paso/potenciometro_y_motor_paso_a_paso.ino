#include <Stepper.h>
 
int pasos=100;
int pasosPorLectura=5;
int leer;
int rotacion;
Stepper stepper(pasos, 8,10,9,11);
int velocidadMotor;
void setup(){
  pinMode (A0, INPUT);
  stepper.setSpeed(200);
}
 
 
void loop(){
  leer=analogRead(A0);
  velocidadMotor=abs(map(leer, 0, 1023, -20, 20))*10;
  if (velocidadMotor>10){
    rotacion = leer>511?1:-1;
    stepper.setSpeed(velocidadMotor);
    stepper.step(rotacion*5);
  }
}
