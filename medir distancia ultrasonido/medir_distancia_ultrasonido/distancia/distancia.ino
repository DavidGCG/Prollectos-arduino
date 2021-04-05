// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 22;
const int echoPin = 23;
// Variables for the duration and the distance
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
}

void loop() {
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.println("cm"); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  delay(300);
  }
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance()
{ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
