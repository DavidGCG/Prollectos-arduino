import processing.serial.*;
Serial port;
void setup() {
size(255, 255);
port = new Serial(this, Serial.list()[1], 9600);
}
void draw()
{
background(0);
}
void keyReleased() { //Manda al puerto la tecla pulsada
port.write(key);
}
