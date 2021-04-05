
int i = 0; 

void setup () 
{
  Serial.begin(9600);
} 

void loop () 
{ 
  String prueba  = "360"; 
  int val4 = prueba.toInt();
  Serial.println(val4+1);
  
    
} 

