#include <Keypad.h>

const byte COLS = 4; //4 Spalten const byte ROWS = 4; //4 Zeilen //Die Ziffern und Zeichen des Keypads werden eingegeben:
const byte ROWS = 4;

char hexaKeys[ROWS][COLS]={
{'D', '#', '0', '*'},
{'C', '9', '8', '7'},
{'B', '6', '5', '4'},
{'A', '3', '2', '1'}
};

byte colPins[COLS] = {2,3,4,5}; //Definition der Pins für die 4 Spalten
byte rowPins[ROWS] = {6,7,8,9}; //Definition der Pins für die 4 Zeilen
char Taste;

Keypad Tastenfeld = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() 
{
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  Taste = Tastenfeld.getKey();
  if(Taste)
  {
    if(Taste == 'D')
    {
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));
      pixels.show();
      delay(200);
      pixels.clear();
      pixels.show();
    }else
    {
      Serial.print("*");
      pixels.setPixelColor(0, pixels.Color(255, 0, 0));
      pixels.show();
      delay(200);
      pixels.clear();
      pixels.show();
    }
  }

}
