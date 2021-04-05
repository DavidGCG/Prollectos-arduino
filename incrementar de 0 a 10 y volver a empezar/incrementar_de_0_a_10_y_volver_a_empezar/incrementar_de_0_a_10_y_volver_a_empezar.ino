
void setup() {
  
  Serial.begin(9600);
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=0;i<=10;i++){  
  Serial.println(i);
  delay(100);
  }
 
}
