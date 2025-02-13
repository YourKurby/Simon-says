#include <Adafruit_NeoPixel.h>
#include <Keypad.h>
#define PIN 11
#define NUMPIXEL 12
#define Taster 

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

int ms = 400;
int lvl = 0;
long randNumber;
bool hit = true;  // ture bis fehler gemacht wird

char H[5];

Adafruit_NeoPixel pixels(NUMPIXEL, PIN, NEO_GRB +NEO_KHZ800);
Keypad Tastenfeld = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  pixels.begin();
  randomSeed(analogRead(0));

}

void loop() 
{
  pixels.clear();
  pixels.show();
  Taste = Tastenfeld.getKey();

  while(hit == true) // Leuft bis fehler gemacht wurde
  {
    int anzahlT;
    for(lvl < 16; lvl++;)
    {
      int anzahlB;

      if(lvl == 0)
      {
        anzahlB = 2;
        anzahlT = 2;
      }else if(lvl == 1)
      {
        anzahlB = 3;
        anzahlT = 3;
      }else
      {
        anzahlB = 4;
        anzahlT = 4;
      }

      if(lvl>=3)
      {
       ms = ms - 10;
      }

      for(anzahlB != 0; anzahlB--;)
      {
        randNumber = random(16);
        pixels.setPixelColor(randNumber, pixels.Color(0, 0, 255));
        pixels.show();
        delay(ms);
        pixels.clear();
        pixels.show();

          switch (randNumber) {
          case 0:
              H[anzahlB] = 'D';
            break;  
          case 1:
              H[anzahlB] = '#';
            break;
          case 2:
              H[anzahlB] = '0';
            break;
          case 3:
              H[anzahlB] = '*';
            break;
          case 4:
              H[anzahlB] = '7';
            break;
          case 5:
              H[anzahlB] = '8';
            break;
          case 6:
              H[anzahlB] = '9';
            break;
          case 7:
              H[anzahlB] = 'C';
            break;
          case 8:
              H[anzahlB] = 'B';
            break;
          case 9:
              H[anzahlB] = '6';
            break;
          case 10:
              H[anzahlB] = '5';
            break;
          case 11:
              H[anzahlB] = '4';
            break;
          case 12:
              H[anzahlB] = '1';
            break;
          case 13:
              H[anzahlB] = '2';
            break;
          case 14:
              H[anzahlB] = '3';
            break;
          case 15:
              H[anzahlB] = 'A';
            break;
          default:
            break;
        }

      }

      for(anzahlT>0; anzahlT--;)
      {
        if(Taste == H[anzahlT])
        {
          pixels.setPixelColor(1, pixels.Color(0, 255, 0));
          pixels.show();
          delay(200);
          pixels.clear();
          pixels.show();
        }else if(Taste != H[anzahlT])
        {
          pixels.setPixelColor(1, pixels.Color(255, 0, 0));
          pixels.show();
          delay(200);
          pixels.clear();
          pixels.show();
          hit = false;
          break;
        }

      }

    }

  }

}