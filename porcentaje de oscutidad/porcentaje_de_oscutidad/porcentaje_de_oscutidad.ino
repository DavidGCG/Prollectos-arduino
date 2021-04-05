
void setup() {
Serial.begin(9600);
}
void loop() {
 float temperatura = analogRead(5);
 temperatura=(100*temperatura/1024);
Serial.print(temperatura); 
Serial.println("% de oscuridad");
delay(100);
}
