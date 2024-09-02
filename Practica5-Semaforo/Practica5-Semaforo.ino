// C++ code
//
int entrada;

void setup()
{
  Serial.begin(9600);
  pinMode(4,OUTPUT);//led naranja
  pinMode(5,OUTPUT);//led blanco
  pinMode(6,OUTPUT);//led verde
  pinMode(7,OUTPUT);//led amarillo
  pinMode(8,OUTPUT);//led rojo
}

void loop()
{
  if(Serial.available() > 0){
    do 
    {
      entrada = Serial.read();
      switch (entrada) {
        case '1':
          Serial.println("Opcion 1");
          digitalWrite(4,HIGH);   
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);   

          delay(1000);  

          digitalWrite(4,LOW);   
          digitalWrite(5,HIGH);
          digitalWrite(6,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);   

          delay(1000);  

          digitalWrite(4,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(6,HIGH);   
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);   

          delay(1000);  

          digitalWrite(4,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(7,HIGH);
          digitalWrite(8,LOW);   

          delay(1000);  

          digitalWrite(4,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(8,HIGH);   

          delay(1000);
          
          digitalWrite(8,LOW);
        
          break;
        case '2':
          Serial.println("Opcion 2");
          digitalWrite(8,HIGH);   
          digitalWrite(7,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(4,LOW);   

          delay(1000);  

          digitalWrite(8,LOW);   
          digitalWrite(7,HIGH);
          digitalWrite(6,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(4,LOW);   

          delay(1000);  

          digitalWrite(8,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(6,HIGH);   
          digitalWrite(5,LOW);
          digitalWrite(4,LOW);   

          delay(1000);  

          digitalWrite(8,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(5,HIGH);
          digitalWrite(4,LOW);   

          delay(1000);  
        
          digitalWrite(8,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(4,HIGH);
        
          delay(1000);
        
          digitalWrite(4,LOW);
          break;
        case '3':
          Serial.println("Opcion 3");
          digitalWrite(4,HIGH);   
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);   

          delay(1000);  

          digitalWrite(4,LOW);   
          digitalWrite(5,HIGH);
          digitalWrite(6,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);   

          delay(1000);  

          digitalWrite(4,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(6,HIGH);   
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);   

          delay(1000);  

          digitalWrite(4,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(7,HIGH);
          digitalWrite(8,LOW);   

          delay(1000);  

          digitalWrite(4,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(8,HIGH);   

          delay(1000);
          
          digitalWrite(8,HIGH);   
          digitalWrite(7,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(4,LOW);   

          delay(1000);  

          digitalWrite(8,LOW);   
          digitalWrite(7,HIGH);
          digitalWrite(6,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(4,LOW);   

          delay(1000);  

          digitalWrite(8,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(6,HIGH);   
          digitalWrite(5,LOW);
          digitalWrite(4,LOW);   

          delay(1000);  

          digitalWrite(8,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(5,HIGH);
          digitalWrite(4,LOW);   

          delay(1000);  
        
          digitalWrite(8,LOW);   
          digitalWrite(7,LOW);
          digitalWrite(6,LOW);   
          digitalWrite(5,LOW);
          digitalWrite(4,HIGH);
        
          delay(1000);
        
          digitalWrite(4,LOW);
          
          break;
        case '4':
          Serial.println("Opcion 4");
          digitalWrite(6,HIGH);
          delay(2000);

          digitalWrite(6,LOW);
          delay(1000);

          digitalWrite(6,HIGH);
          delay(1000);

          digitalWrite(6,LOW);
          delay(1000);

          digitalWrite(6,HIGH);
          delay(1000);

          digitalWrite(6,LOW);
          digitalWrite(5,HIGH);
          delay(1500);

          digitalWrite(5,LOW);
          digitalWrite(4,HIGH);
          delay(2000);

          digitalWrite(4,LOW);
          break;
        case '5':
          Serial.println("Saliendo..........");
          break;
        default:
          //Serial.println("Opción inválida. Por favor, elija 1, 2 o 3.");
          break;
      }
    }while(entrada!=5);
  }
}
