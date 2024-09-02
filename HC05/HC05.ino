#include <SoftwareSerial.h>
SoftwareSerial BT (10,11);
int baselineTemp = 0; 
int celsius = 0; 
int fahrenheit = 0; 
void setup(){

	  pinMode(A0, INPUT);  
    BT.begin(9600);
    Serial.begin(9600);  
    pinMode(3, OUTPUT);  
  	pinMode(4, OUTPUT);  
  	pinMode(5, OUTPUT);   
    
} 
void loop()
  {  
    
    if (BT.available())
    {
      Serial.write(BT.read());
    }
    if (Serial.available()){
      BT.write(Serial.read()) ; 
      Serial.print(celsius);
    }
    
}