int entrada;
int led = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0){
    entrada = Serial.read();
    if(entrada == 'a'){ 
      digitalWrite(led, HIGH);
      Serial.println("Encendido");
    }
    if(entrada == 'b'){
      digitalWrite(led, LOW);
      Serial.println("Apagado");
    }
  }
}
