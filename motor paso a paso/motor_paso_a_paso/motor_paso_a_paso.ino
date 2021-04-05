
// Este ejemplo demuestra que el motor 28BYJ-48 opera de forma
// bidireccional, usando un módulo ULN2003.
//La frecuencia de operación es 100Hz. Y la corriente de 92mA. 
////////////////////////////////////////////////

//declaración de las variables para los pines del motor
int motorPin1 = 8;    // Azul   - 28BYJ48 pin 1 motor
int motorPin2 = 9;    // Rosa   - 28BYJ48 pin 2 motor
int motorPin3 = 10;    // Amarillo - 28BYJ48 pin 3 motor
int motorPin4 = 11;    // Naranja - 28BYJ48 pin 4 motor
                        // Rojo   - 28BYJ48 pin 5 (VCC) motor

int motorSpeed = 650;  //variable para fijar la velocidad del motor (el retraso entre cada secuencia)
int count = 0;          // cuenta de los pasos dados
int countsperrev = 550; // número de pasos por vuelta completa 
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

void setup() {
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if(count < countsperrev )
    clockwise(); //sentido agujas del reloj
  else if (count == countsperrev * 2)
    count = 0;
  else
    anticlockwise(); //sentido antihorario
  count++;
}


//creación funciones giro horario y antihorario
void anticlockwise() 
{
  for(int i = 0; i < 8; i++)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void clockwise()
{
  for(int i = 7; i >= 0; i--)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void setOutput(int out) //función secuencia giro
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}



