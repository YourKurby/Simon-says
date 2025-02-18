#include <Keypad.h>
#include <Adafruit_NeoPixel.h>
#define PIN 11          // Pin zum ansteuern des LED-Streifens
#define NUMPIXEL 16

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

char right_Taster[5]; // speichert welche Taster gedrückt werden müssen

char Taster_In; // input des Kaypads
bool Taster_Schleife = false; // zum warten auf taster input
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
  Serial.print("loop "); // Testwiedergabe
  
  int anzahl_LED = 2; // anzahl der LED die in einem Durchlauf leuchten
  int anzahl_Taster = 2; // anzahl der Taster die gedrückt werden müssen

  for(anzahl_LED > 0; anzahl_LED--;)
  {
    randNumber = random(16); // Random zahl zwischen 0 und 15
    Serial.print(randNumber + " "); // Testwiedergabe

    pixels.setPixelColor(randNumber, pixels.Color(0, 0, 255));
    pixels.show();
    delay(600);
    pixels.clear();
    pixels.show();
    delay(200);

    switch (randNumber) 
    {
        case 0:
            right_Taster[anzahl_LED] = 'D';
          break;  
        case 1:
            right_Taster[anzahl_LED] = '#';
          break;
        case 2:
            right_Taster[anzahl_LED] = '0';
          break;
        case 3:
            right_Taster[anzahl_LED] = '*';
          break;
        case 4:
            right_Taster[anzahl_LED] = '7';
          break;
        case 5:
            right_Taster[anzahl_LED] = '8';
          break;
        case 6:
            right_Taster[anzahl_LED] = '9';
          break;
        case 7:
            right_Taster[anzahl_LED] = 'C';
          break;
        case 8:
            right_Taster[anzahl_LED] = 'B';
          break;
        case 9:
            right_Taster[anzahl_LED] = '6';
          break;
        case 10:
            right_Taster[anzahl_LED] = '5';
          break;
        case 11:
            right_Taster[anzahl_LED] = '4';
          break;
        case 12:
            right_Taster[anzahl_LED] = '1';
          break;
        case 13:
            right_Taster[anzahl_LED] = '2';
          break;
        case 14:
            right_Taster[anzahl_LED] = '3';
          break;
        case 15:
            right_Taster[anzahl_LED] = 'A';
          break;
        default:
          break;
      } // end switch case

  } // end for(anzahl_LED)

  for(anzahl_Taster > 0; anzahl_Taster--;)
  {
    Taster_Schleife = false;
    while(Taster_Schleife == false) // leuft bis eine Taste gedrückt wurde
    {
        Taster_In = Tastenfeld.getKey();
        if(Taster_In)
        {
            if(Taster_In == right_Taster[anzahl_Taster])
            {
                Serial.print(Taster_In + " "); // Testwiedergabe
                pixels.setPixelColor(0, pixels.Color(0, 255, 0));
                pixels.show();
                delay(400);
                pixels.clear();
                pixels.show();
            }else
            {
                Serial.print("andere "); // Testwiedergabe
                pixels.setPixelColor(0, pixels.Color(255, 0, 0));
                pixels.show();
                delay(400);
                pixels.clear();
                pixels.show();
            }
            Taster_Schleife = true;
        } // end if(taster)
    } // end While(t)
  } // end for(anzahl_T)
} // end void loop