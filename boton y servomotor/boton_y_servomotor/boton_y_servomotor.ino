
#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo

int BotonReduce1 = 46;  
int BotonIncrementa1 = 7;
int BotonReduce2 = 48;  
int BotonIncrementa2 = 49;
int BotonReduce3 = 50;  
int BotonIncrementa3 = 51;
int BotonReduce4 = 52;  
int BotonIncrementa4 = 53;

int val1=0;
int val2=0;
int val3=0;
int val4=0;

void setup() {
  myservo1.attach(8);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo4.attach(11);  // attaches the servo on pin 9 to the servo object

  pinMode(BotonReduce1, INPUT);  
  pinMode(BotonIncrementa1, INPUT); 
  pinMode(BotonReduce2, INPUT);  
  pinMode(BotonIncrementa2, INPUT); 
  pinMode(BotonReduce3, INPUT);  
  pinMode(BotonIncrementa3, INPUT); 
  pinMode(BotonReduce4, INPUT);  
  pinMode(BotonIncrementa4, INPUT);  

  Serial.begin(9600);
}

void loop() {
/*
   if (digitalRead(BotonIncrementa1) == HIGH){val1++;}  
   if (digitalRead(BotonReduce1) == HIGH){val1--;}
   
   if (digitalRead(BotonIncrementa2) == HIGH){val2++;}  
   if (digitalRead(BotonReduce2) == HIGH){val2--;}
   
   if (digitalRead(BotonIncrementa3) == HIGH){val3++;}  
   if (digitalRead(BotonReduce3) == HIGH){val3--;}
   
   if (digitalRead(BotonIncrementa4) == HIGH){val4++;}  
   if (digitalRead(BotonReduce4) == HIGH){val4--;}
    
    myservo1.write(val1);  
    myservo2.write(val2);  
    myservo3.write(val3);  
    myservo4.write(val4);  
*/
   Serial.print(val1);
   Serial.print(" ");
   Serial.print(val2);
   Serial.print(" ");
   Serial.print(val3);
   Serial.print(" ");
   Serial.print(val4);
   Serial.print(" ");
   Serial.println();

////////////////////////////
   if (digitalRead(BotonIncrementa1) == HIGH)   
   {   
      val1++;   
     delay(5);  
   }     
   if (digitalRead(BotonReduce1) == HIGH)   
   {   
      val1--;  
     delay(5);  
    }
    myservo1.write(val1);         
    delay(5);
  
////////////////////////////
   if (digitalRead(BotonIncrementa2) == HIGH)   
   {   
      val2++;   
     delay(5);  
   }     
   if (digitalRead(BotonReduce2) == HIGH)   
   {   
      val2--;  
     delay(5);  
    }
    myservo2.write(val2);         
    delay(5);
///////////////////////////////////
   if (digitalRead(BotonIncrementa3) == HIGH)   
   {   
      val3++;   
     delay(5);  
   }     
   if (digitalRead(BotonReduce3) == HIGH)   
   {   
      val3--;  
     delay(5);  
    }
    myservo3.write(val3);         
    delay(5);
  
////////////////////////////
    if (digitalRead(BotonIncrementa4) == HIGH)   
   {   
      val4++;   
     delay(5);  
   }     
   if (digitalRead(BotonReduce4) == HIGH)   
   {   
      val4--;  
     delay(5);  
    }
    myservo4.write(val4);         
    delay(5);
    }
 
     //if (val2 > 180) { val2=180; }  
   // if (val2 < 0) { val2=0; } 
