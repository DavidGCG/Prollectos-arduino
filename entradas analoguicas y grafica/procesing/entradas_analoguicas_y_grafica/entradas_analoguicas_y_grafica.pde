//HeTPro
//http://www.hetpro.com.mx
//Ejempo para el sensor sigue-lineas.
//qre1113
//Enviar datos de 8 bits por el serial
//Visualizarlos en processing
//Codigo de ejemplo adaptado de:
//http://boolscott.wordpress.com/2010/02/04/arduino-processing-analogue-bar-graph-2/
 
// Feel Free to edit these variables ///////////////////////////
String xLabel = "Analogue Inputs";
String yLabel = "Voltage (V)";
String Heading = "HETPRO SIGUE LINEAS";
String URL = "www.hetpro.com.mx";
float Vcc = 5.0; // the measured voltage of your usb
int NumOfVertDivisions=5; // dark gray
int NumOfVertSubDivisions=10; // light gray
int NumOfBars=6; // you can choose the number of bars, but it can cause issues
 // since you should change what the arduino sends
// if these are changed, background image has problems
// a plain background solves the problem
int ScreenWidth = 600, ScreenHeight=400;
/////////////////////////////////////////////////////////
// Serial port stuff ///////////////////////
import processing.serial.*;
Serial myPort;
boolean firstContact = false;
int[] serialInArray = new int[6];
int serialCount = 0;
///////////////////////////////////////////////
int LeftMargin=100;
int RightMArgin=80;
int TextGap=50;
int GraphYposition=80;
float BarPercent = 0.4;
int value;
PFont font;
PImage bg;
int temp;
float yRatio = 0.58;
int BarGap, BarWidth, DivisounsWidth;
int[] bars = new int[NumOfBars];
void setup(){
// bg = loadImage("BG.jpg");
/// NB SETTINGS ////////////////////////////////////////////////////////
 myPort = new Serial(this, Serial.list()[1], 9600);
 ////////////////////////////////////////////////////////////////////////
DivisounsWidth = (ScreenWidth-LeftMargin-RightMArgin)/(NumOfBars);
 BarWidth = int(BarPercent*float(DivisounsWidth));
 BarGap = DivisounsWidth - BarWidth;
//size(ScreenWidth,ScreenHeight);
size(600,400);
 font = createFont("Arial",12);
textAlign(CENTER);
 textFont(font);
}
void draw(){
// background(bg); // My one used a background image, I've
 background(250); // commented it out and put a plain colour
// Headings(); // Displays bar width, Bar gap or any variable.
 Axis();
 Labels();
 PrintBars();
}
// Send Recieve data //
void serialEvent(Serial myPort) {
// read a byte from the serial port:
 int inByte = myPort.read();
if (firstContact == false) {
 if (inByte == 'A') {
 myPort.clear(); // clear the serial port buffer
 firstContact = true; // you've had first contact from the microcontroller
 myPort.write('A');// ask for more
 }
 }
 else {
 // Add the latest byte from the serial port to array:
 serialInArray[serialCount] = inByte;
 serialCount++;
// If we have 6 bytes:
 if (serialCount > 5 ) {
for (int x=0;x<6;x++){
bars[x] = int (yRatio*(ScreenHeight)*(serialInArray[x]/256.0));
}
// Send a capital A to request new sensor readings:
 myPort.write('A'); // Reset serialCount:
 serialCount = 0;
 }
 }
}
/////// Display any variables for testing here//////////////
void Headings(){
 fill(0 );
 text("BarWidth",50,TextGap );
 text("BarGap",250,TextGap );
 text("DivisounsWidth",450,TextGap );
 text(BarWidth,100,TextGap );
 text(BarGap,300,TextGap );
 text(DivisounsWidth,520,TextGap );
}
void PrintBars(){
int c=0;
 for (int i=0;i<NumOfBars;i++){
fill((0xe4+c),(255-bars[i]+c),(0x1a+c));
 stroke(90);
 rect(i*DivisounsWidth+LeftMargin, ScreenHeight-GraphYposition, BarWidth, -bars[i]);
 fill(0x2e,0x2a,0x2a);
 text(float(bars[i])/(yRatio*(ScreenHeight))*Vcc, i*DivisounsWidth+LeftMargin+BarWidth/2, ScreenHeight-bars[i]-5-GraphYposition );
 text("A", i*DivisounsWidth+LeftMargin+BarWidth/2 -5, ScreenHeight-GraphYposition+20 );
 text(i, i*DivisounsWidth+LeftMargin+BarWidth/2 +5, ScreenHeight-GraphYposition+20 );
 }
}
void Axis(){
strokeWeight(1);
 stroke(220);
 for(float x=0;x<=NumOfVertSubDivisions;x++){
int bars=(ScreenHeight-GraphYposition)-int(yRatio*(ScreenHeight)*(x/NumOfVertSubDivisions));
 line(LeftMargin-15,bars,ScreenWidth-RightMArgin-DivisounsWidth+50,bars);
 }
 strokeWeight(1);
 stroke(180);
 for(float x=0;x<=NumOfVertDivisions;x++){
int bars=(ScreenHeight-GraphYposition)-int(yRatio*(ScreenHeight)*(x/NumOfVertDivisions));
 line(LeftMargin-15,bars,ScreenWidth-RightMArgin-DivisounsWidth+50,bars);
 }
 strokeWeight(2);
 stroke(90);
 line(LeftMargin-15, ScreenHeight-GraphYposition+2, ScreenWidth-RightMArgin-DivisounsWidth+50, ScreenHeight-GraphYposition+2);
 line(LeftMargin-15,ScreenHeight-GraphYposition+2,LeftMargin-15,GraphYposition);
 strokeWeight(1);
}
void Labels(){
 textFont(font,18);
 fill(50);
 rotate(radians(-90));
 text(yLabel,-ScreenHeight/2,LeftMargin-45);
 textFont(font,16);
 for(float x=0;x<=NumOfVertDivisions;x++){
int bars=(ScreenHeight-GraphYposition)-int(yRatio*(ScreenHeight)*(x/NumOfVertDivisions));
 text(round(x),-bars,LeftMargin-20);
 }
textFont(font,18);
 rotate(radians(90));
 text(xLabel,LeftMargin+(ScreenWidth-LeftMargin-RightMArgin-50)/2,ScreenHeight-GraphYposition+40);
 textFont(font,24);
 fill(50);
 text(Heading,LeftMargin+(ScreenWidth-LeftMargin-RightMArgin-50)/2,70);
 textFont(font);
fill(150);
 text(URL,ScreenWidth-RightMArgin-40,ScreenHeight-15);
 textFont(font);
}