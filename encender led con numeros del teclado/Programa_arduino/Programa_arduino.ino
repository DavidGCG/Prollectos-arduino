int ledPin1= 13, ledPin2= 12, ledPin3= 11, ledPin4= 10,
    ledPin5= 9, ledPin6= 8, ledPin7= 7, ledPin8= 6, ledPin9= 5;
    
int status1 = HIGH, status2 = HIGH, status3 = HIGH , status4 = HIGH
, status5 = HIGH, status6 = HIGH, status7 = HIGH
,status8 = HIGH, status9 = HIGH;
int val;
void setup() {
Serial.begin(9600);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(ledPin4, OUTPUT);
pinMode(ledPin5, OUTPUT);
pinMode(ledPin6, OUTPUT);
pinMode(ledPin7, OUTPUT);
pinMode(ledPin8, OUTPUT);
pinMode(ledPin9, OUTPUT);

}
void loop(){
val= Serial.read();// lee el valor del puerto
if(val!= -1) {
switch(val) {
case'1': status1 = !status1; break;
case'2': status2 = !status2; break;
case'3': status3 = !status3; break;
case'4': status4 = !status4; break;
case'5': status5 = !status5; break;
case'6': status6 = !status6; break;
case'7': status7 = !status7; break;
case'8': status8 = !status8; break;
case'9': status9 = !status9; break;
}
}
digitalWrite(ledPin1, status1);
digitalWrite(ledPin2, status2);
digitalWrite(ledPin3, status3);
digitalWrite(ledPin4, status4);
digitalWrite(ledPin5, status5);
digitalWrite(ledPin6, status6);
digitalWrite(ledPin7, status7);
digitalWrite(ledPin8, status8);
digitalWrite(ledPin9, status9);
}
