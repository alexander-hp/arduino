#include <SoftwareSerial.h>

SoftwareSerial BT(10,11); //10 RX, 11 TX

byte led_1 = 3;
byte led_2 = 4;
byte led_3 = 5;
byte led_4 = 6;

char CharIN = ' ';

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  IniciarPines();
  SerialPrintln("Iniciando Control ...");
}

void loop() {
  if(BT.available()){
    CharIN = BT.read();
    Serial.print{CharIN};
    OnOffLeds();
  }
}

IniciarPines(void){
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);

  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
}

void OnOffLeds{
  if(CharIN == 'A'){digitalWrite(led_1, HIGH);}
  if(CharIN == 'B'){digitalWrite(led_1, LOW);}

  if(CharIN == 'C'){digitalWrite(led_2, HIGH);}
  if(CharIN == 'D'){digitalWrite(led_2, LOW);}

  if(CharIN == 'E'){digitalWrite(led_3, HIGH);}
  if(CharIN == 'F'){digitalWrite(led_3, LOW);}

  if(CharIN == 'G'){digitalWrite(led_4, HIGH);}
  if(CharIN == 'H'){digitalWrite(led_4, LOW);}
}
