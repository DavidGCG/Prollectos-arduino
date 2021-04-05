
void setup(){
  Serial.begin(9600);
  Serial.print(1996,BIN);//inserta el numero
  Serial.print("\t");//inserta tabulacion
  Serial.print(16,BIN);//inserta el numero
  Serial.print("\n");//inserta salto de linea
  Serial.print(56,BIN);//inserta el numero
}

void loop(){
 // Serial.println(78,BIN);
}
