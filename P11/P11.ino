#include <SoftwareSerial.h>
SoftwareSerial BT(10,11);
char entrada;

void setup() {
    BT.begin(9600);
    Serial.begin(9600);
   
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
}

void loop() {
    if (BT.available() > 0) {
        entrada = BT.read();

        switch (entrada) {
            case '1':digitalWrite(4, HIGH);   
                     digitalWrite(5, LOW);
                     digitalWrite(6, LOW);   
                     digitalWrite(3, LOW);   
                     delay(1000);  
   
                     digitalWrite(3, HIGH);
                     digitalWrite(6, LOW);   
                     digitalWrite(5, LOW);
                     digitalWrite(4, LOW);   
                     delay(1000);  
 
                     digitalWrite(5, LOW);
                     digitalWrite(6, HIGH);   
                     digitalWrite(3, LOW);
                     digitalWrite(4, LOW);   
                     delay(1000);  
   
                     digitalWrite(3, LOW);
                     digitalWrite(6, LOW);   
                     digitalWrite(5, HIGH);
                     digitalWrite(4, LOW);   
                     delay(1000); 
                 digitalWrite(5, LOW); 
                     break;
            
          case '2':digitalWrite(5, HIGH);
                   digitalWrite(6, LOW);   
                   digitalWrite(3, LOW);
                   digitalWrite(4, LOW);   
                   delay(1000);  

                   digitalWrite(5, LOW);
                   digitalWrite(6, HIGH);   
                   digitalWrite(3, LOW);
                   digitalWrite(4, LOW);   
                   delay(1000);  
  
                   digitalWrite(5, LOW);
                   digitalWrite(6, LOW);   
                   digitalWrite(3, HIGH);
                   digitalWrite(4, LOW);   
                   delay(1000);  
 
                   digitalWrite(5, LOW);
                   digitalWrite(6, LOW);   
                   digitalWrite(3, LOW);
                   digitalWrite(4, HIGH);   
                   delay(1000);
                   digitalWrite(4, LOW);
                   break;
 
          case '3':digitalWrite(5, HIGH);
                   digitalWrite(6, LOW);   
                   digitalWrite(3, LOW);
                   digitalWrite(4, LOW);   
                   delay(1000);  
  
                   digitalWrite(5, LOW);
                   digitalWrite(6, HIGH);   
                   digitalWrite(3, LOW);
                   digitalWrite(4, LOW);   
                   delay(1000); 
   
                   digitalWrite(5, LOW);
                   digitalWrite(6, LOW);   
                   digitalWrite(3, HIGH);
                   digitalWrite(4, LOW);   
                   delay(1000);  
  
                   digitalWrite(5, LOW);
                   digitalWrite(6, LOW);   
                   digitalWrite(3, LOW);
                   digitalWrite(4, HIGH);   
                   delay(1000);
   
                   digitalWrite(5, LOW);
                   digitalWrite(6, LOW);   
                   digitalWrite(3, LOW);
                   digitalWrite(4, HIGH);   
                   delay(1000);  
  
                   digitalWrite(5, LOW);
                   digitalWrite(6, LOW);   
                   digitalWrite(3, HIGH);
                   digitalWrite(4, LOW);   
                   delay(1000);  

                   digitalWrite(5, LOW);
                   digitalWrite(6, HIGH);   
                   digitalWrite(3, LOW);
                   digitalWrite(4, LOW);   
                   delay(1000);  
 
                   digitalWrite(5, HIGH);
                   digitalWrite(6, LOW);   
                   digitalWrite(3, LOW);
                   digitalWrite(4, LOW);   
                   delay(1000); 
                   digitalWrite(5, LOW);
                   break;

          case '4':digitalWrite(4, HIGH);
                   delay(2000);
                   digitalWrite(4, LOW);
                   delay(1000);

                   digitalWrite(4, HIGH);
                   delay(1000);
                   digitalWrite(4, LOW);
                   delay(1000);
                   digitalWrite(4, HIGH);
                   delay(1000);
                   digitalWrite(4, LOW);
                   digitalWrite(3, HIGH);
                   delay(1500);
                   digitalWrite(3, LOW);
                   digitalWrite(6, HIGH);
                   delay(4500);
                   digitalWrite(6, LOW);
                   break;
          
          case '5':Serial.println("Salir");
                   digitalWrite(5, LOW);
                   digitalWrite(2, LOW);
                   digitalWrite(3, LOW);
                   digitalWrite(4, LOW);
                   break;

           default:Serial.println("Opcion no valida");
                   break;
        }
    }
}
