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

char right_Taster[6]; // speichert welche Taster gedrückt werden müssen
char Taster_In; // input des Kaypads

bool Taster_Schleife = false; // zum warten auf taster input
bool miss = false; // true wenn eine faltsche Taste gedrückt würd
bool Spiel = true; // false wenn spiel beendet wird (durch miss oder lvl)
bool lvl_select = false;

long randNumber; // random zahl für LED die leuchtet

int lvl = 0; // Zählt die geschaften Level
int anzahl_LED; // anzahl der LED die in einem Durchlauf leuchten
int anzahl_Taster; // anzahl der Taster die gedrückt werden müssen
int LED_speed = 700; // Wie lange die LEDs leuchten

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
  pixels.clear();
  pixels.show();
  delay(2000);
  Serial.print("loop "); // Testwiedergabe

  for(int i = 0; i < 16; i++)
  {
    pixels.fill(pixels.Color(248, 38, 255), 0, i);
    pixels.show();
    delay(100);
    pixels.clear();
    pixels.show();
  }

  lvl = 0;
  lvl_select = false;
  Spiel = true;
  LED_speed = 700;

  while(lvl_select == false)
  {
    Taster_In = Tastenfeld.getKey();
    if(Taster_In)
    {
      switch (Taster_In) 
      {
          case 'D':
              lvl = 0;
            break;  
          case '#':
              lvl = 1;
            break;
          case '0':
              lvl = 2;
            break;
          case '*':
              lvl = 3;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case '7':
              lvl = 4;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case '8':
              lvl = 5;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case '9':
              lvl = 6;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case 'C':
              lvl = 7;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case 'B':
              lvl = 8;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case '6':
              lvl = 9;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case '5':
              lvl = 10;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case '4':
              lvl = 11;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case '1':
              lvl = 12;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case '2':
              lvl = 13;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case '3':
              lvl = 14;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          case 'A':
              lvl = 15;
              LED_speed = LED_speed - (30*(lvl-2));
            break;
          default:
            break;
        } // end switch case
      lvl_select = true;
    } // ende if(Taster_in)
  } // ende while(lvl_select)

  fail:

  if(miss == true)
  {
    for(int i = 0; i < 3; i++)
    {
      pixels.fill(pixels.Color(248, 38, 255), 0, lvl+1);
      pixels.show();
      delay(500);
      pixels.clear();
      pixels.show();
      delay(500);
    }
    miss = false;
  }else if(lvl == 16)
  {
    for(int i = 0; i < 3; i++)
    {
      pixels.fill(pixels.Color(248, 38, 255), 0, lvl);
      pixels.show();
      delay(500);
      pixels.clear();
      pixels.show();
      delay(500);
      miss = false;
    } 
  }

  while(Spiel == true)
  {
    if(lvl == 0)
    {
      anzahl_LED = 3;
      anzahl_Taster = 3;
    }else if(lvl == 1)
    {
      anzahl_LED = 4;
      anzahl_Taster = 4;
    }else
    {
      anzahl_LED = 5;
      anzahl_Taster = 5;
      LED_speed = LED_speed - 30;
    }
  
    Serial.print((int)lvl);
    Serial.print(" lvl ");
  
    for(anzahl_LED > 0; anzahl_LED--;)
    {
      randNumber = random(16); // Random zahl zwischen 0 und 15
      Serial.print((int)randNumber); // Testwiedergabe
      
      pixels.setPixelColor(randNumber, pixels.Color(0, 0, 255));
      pixels.show();
      delay(LED_speed);
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
                Serial.print(" andere "); // Testwiedergabe
                pixels.setPixelColor(15, pixels.Color(255, 0, 0));
                pixels.show();
                delay(400);
                pixels.clear();
                pixels.show();
                miss = true;
                Spiel = false;
                goto fail;
              }
              Taster_Schleife = true;
          } // end if(taster)
      } // end While(t)
    } // end for(anzahl_T)
    delay(300);
    lvl++;
    if(lvl == 16)
    goto fail;
  } // end While(Spiel)
} // end void loop
