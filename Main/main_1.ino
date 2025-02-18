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

char Taster_In;
bool Taster_Schleife;

Keypad Tastenfeld = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Adafruit_NeoPixel pixels(NUMPIXEL, PIN, NEO_GRB + NEO_KHZ800);


void setup() 
{
    Serial.begin(9600);
    pixels.begin();
}


void loop()
{
  Serial.print("bla ");
  Taster_Schleife = false;

  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.show();

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
            delay(200);
        }else
        {
            Serial.print("andere ");
            pixels.setPixelColor(0, pixels.Color(255, 0, 0));
            pixels.show();
            delay(200);
        }
        Taster_Schleife = true;
     } // end if(taster)
  } // end While(t)
} // end void loop