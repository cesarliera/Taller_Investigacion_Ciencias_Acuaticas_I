//bibliotecas
#include "DHT.h"
#include <OneWire.h>                
#include <DallasTemperature.h>

#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#include <SPI.h>
#include <SD.h>


///////////////////variables//////////////////////////////////
Sd2Card card;
SdVolume volume;
SdFile root;
const int chipSelect = 10;

#define DHTPIN 4     // Pin donde está conectado el sensor
#define DHTTYPE DHT11   // Descomentar si se usa el DHT 11
//#define DHTTYPE DHT22   // Sensor DHT22
DHT dht(DHTPIN, DHTTYPE);

float temp;
float h;
float t;

//LEDs//

int ledRojo = 6;
int ledVerde = 5;
int ledAzul = 4;

////SD
const int sentenceSize = 90; // caracteres atmosfericos
char sentence[sentenceSize]; // trama del GPS

unsigned long duracion;
char* v;
char field[15];
unsigned char buffer[64]; // buffer array for data recieve over serial port
int count=0; // counter for buffer array
char field4[20];
const int sentenceSize4 = 80;
char sentence4[sentenceSize];

/////////////////////Variables RTC//////////////
int ano,mes,dia,hora,minuto,segundo;
String mess, dias, segundos,minutos,horas;
int a1,a2,a3,a4,a5;

/////////////////////Variables DataLOG//////////////
String union_variables_sat;
String uniendo;
char envioMOB[200];

void setup() {

pinMode(ledRojo,OUTPUT);
pinMode(ledVerde,OUTPUT);
pinMode(ledAzul,OUTPUT);

rosa();
  // Wait for serial monitor to open
  Serial.begin(19200);
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
  Serial.println("Card failed, or not present");
     //don't do anything more:
    while (1);
   }


}

void loop() {
  verde();
  reloj();
  rojo();
  datos_confort_term();
  lecturas();
  delay(10);
  data_sd();

    horas="";
    minutos="";
    segundos="";
    mess="";
    dias="";
    union_variables_sat="";
    a1=0;
    a2=0;
    a3=0;
    a4=0;
    a5=0;
}