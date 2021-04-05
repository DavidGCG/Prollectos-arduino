#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

char pin[5];
int posicion = 0;
byte rowPins[ROWS] = {22, 24, 26, 28};
byte colPins[COLS] = {30, 32, 34, 36};

Keypad teclado = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Bienvenido ");
  lcd.setCursor(0, 1);
  lcd.print("Introduce tu pin");
  pinMode(22, OUTPUT);
  digitalWrite(22, HIGH);
}

void loop() {
  pin[posicion] = teclado.getKey();

  if (pin[posicion]) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Introduciendo");
    for (int i = 0; i <= posicion; i++) {
      lcd.setCursor(i, 1);
      lcd.print("*");
    }
    posicion++;
    if (posicion == 5) posicion = 0;
  }
  if (pin[4] == 'A') {
    pin[4] = 'a';
    if (pin[0] == '1' && pin[1] == '2' && pin[2] == '3' && pin[3] == '4') {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Pin correcto ");
      lcd.setCursor(0, 1);
      lcd.print("Empuje la puerta ");

      digitalWrite(22, LOW);
      delay(4000);
      digitalWrite(22, HIGH);
    }
    else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Pin incorrecto ");
      digitalWrite(43, HIGH);
      delay(500);
      digitalWrite(43, LOW);
      delay(1500);
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Bienvenido ");
    lcd.setCursor(0, 1);
    lcd.print("Introduce tu pin");
  }
  delay(10);
}

