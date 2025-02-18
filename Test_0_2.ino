#include <Keypad.h>

bool t = false;
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
  }

void loop() {
  Serial.print("bla ");
  t = false;
  while(t == false)
  {
    Taste = Tastenfeld.getKey();
  if(Taste)
  {
    if(Taste == 'D')
    {
      Serial.print(Taste);
    }else
    {
      Serial.print("andere ");
    }
    t = true;
  }
  }
}
