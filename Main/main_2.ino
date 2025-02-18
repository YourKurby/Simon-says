#include <Keypad.h>
#include <Adafruit_NeoPixel.h>
#define PIN 11          // Pin zum ansteuern des LED-Streifens
#define NUMPIXEL 12

const byte COLS = 4; //4 Spalten 
const byte ROWS = 4; //4 Zeilen

char hexaKeys[ROWS][COLS]={
{'D', '#', '0', '*'},
{'C', '9', '8', '7'},
{'B', '6', '5', '4'},
{'A', '3', '2', '1'}
};

byte colPins[COLS] = {2,3,4,5}; //Definition der Pins für die 4 Spalten
byte rowPins[ROWS] = {6,7,8,9}; //Definition der Pins für die 4 Zeilen

char Taster_In; // input des Kaypads
bool Taster_Schleife; // zum warten auf taster input
long randNumber; // random zahl für LED die leuchtet

Keypad Tastenfeld = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Adafruit_NeoPixel pixels(NUMPIXEL, PIN, NEO_GRB + NEO_KHZ800);


void setup() 
{
    Serial.begin(9600);
    pixels.begin();
    randomSeed(analogRead(0));
}


void loop()
{
  Serial.print("bla ");
  Taster_Schleife = false;
  
  int anzahl_LED = 2; // anzahl der LED die in einem Durchlauf leuchten

  for(anzahl_LED > 0; anzahl_LED--;)
  {
    randNumber = random(16); // Random zahl zwischen 0 und 15
    pixels.setPixelColor(randNumber, pixels.Color(0, 0, 255));
    pixels.show();
    delay(400);
    pixels.clear();
    pixels.show();
  }

  

  while(Taster_Schleife == false)
  {
    Taster_In = Tastenfeld.getKey();
    if(Taster_In)
    {
        if(Taster_In == 'D')
        {
            Serial.print(Taster_In + " ");
            pixels.setPixelColor(0, pixels.Color(0, 255, 0));
            pixels.show();
            delay(400);
            pixels.clear();
            pixels.show();
        }else
        {
            Serial.print("andere ");
            pixels.setPixelColor(0, pixels.Color(255, 0, 0));
            pixels.show();
            delay(400);
            pixels.clear();
            pixels.show();
        }
        Taster_Schleife = true;
     } // end if(taster)
  } // end While(t)
} // end void loop