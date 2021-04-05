
int led1=22;
int led2=24;
int led3=26;
int led4=28;
int led5=30;
int led6=32;

int velocidad;

void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(A0,INPUT);
}

void loop()
{
  digitalWrite(led1,HIGH);
  delay(velocidad=analogRead(A0)*4.8);
  digitalWrite(led1,LOW);
  delay(velocidad=analogRead(A0)*4.8);
  
  digitalWrite(led2,HIGH);
  delay(velocidad=analogRead(A0)*4.8);
  digitalWrite(led2,LOW);
  delay(velocidad=analogRead(A0)*4.8);
  
  digitalWrite(led3,HIGH);
  delay(velocidad=analogRead(A0)*4.8);
  digitalWrite(led3,LOW);
  delay(velocidad=analogRead(A0)*4.8);
  
  digitalWrite(led4,HIGH);
  delay(velocidad=analogRead(A0)*4.8);
  digitalWrite(led4,LOW);
  delay(velocidad=analogRead(A0)*4.8);
  
  digitalWrite(led5,HIGH);
  delay(velocidad=analogRead(A0)*4.8);
  digitalWrite(led5,LOW);
  delay(velocidad=analogRead(A0)*4.8);
  
  digitalWrite(led6,HIGH);
  delay(velocidad=analogRead(A0)*4.8);
  digitalWrite(led6,LOW);
  delay(velocidad=analogRead(A0)*4.8);
}
