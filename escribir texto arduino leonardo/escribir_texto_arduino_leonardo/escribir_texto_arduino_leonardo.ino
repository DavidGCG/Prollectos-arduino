

const int buttonPin = 4;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton               // button push counter

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed, 
  if ((buttonState != previousButtonState) 
    // and it's currently pressed:
  && (buttonState == HIGH)) {
    // increment the button counter

    // type out a message
  
     Keyboard.println("00//00000000//0000///0000//0000000000000/0000000");
     Keyboard.println("00//00000000//000/000/000//000000000000/00/00000");
     Keyboard.println("00//00000000//00/00000/00//00000000000/0000/0000");
     Keyboard.println("00////////////00/00000/00//00000000000/0000/0000");
     Keyboard.println("00//00000000//00/00000/00//00000000000//////0000");
     Keyboard.println("00//00000000//000/000/000//0000000000/000000/000");
     Keyboard.println("00//00000000//0000///0000//////////00/000000/000");
     Keyboard.println(" ");
  //   Keyboard.println("///////////////////////////////////////////");
     
  
  //  Keyboard.print("Arduino es una plataforma de prototipos electrónica de código abierto (open-source) basada en hardware y software exibles y fáciles de usar. Está pensado para artistas, diseñadores, como hobby y para cualquiera interesado en crear objetos o entornos interactivos. Arduino puede sentir el entorno mediante la recepción de entradas desde una variedad de sensores y puede afectar a su alrededor mediante el control de luces, motores y otros artefactos. El microcontrolador de la placa se programa usando el Arduino Programming Language (basado en Wiring1) y el Arduino Development Environment (basado en Processing2). Los proyectos de Arduino pueden ser autonomos o se pueden comunicar con software en ejecución en un ordenador (por ejemplo con Flash, Processing, MaxMSP, etc.). Las placas se pueden ensamblar a mano3 o encargarlas preensambladas4; el software se puede descargar5 gratuitamente. Los diseños de referencia del hardware (archivos CAD) están disponibles bajo licencia open-source, por lo que eres libre de adaptarlas a tus necesidades. Arduino recibió una mención honoríca en la sección Digital Communities del Ars Electronica Prix en 2006.");
   // Keyboard.print(counter); 
   // Keyboard.println(" fin.");
  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState; 
}

