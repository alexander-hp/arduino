int buzzer = 12;//el pin del zumbador activo

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);//Inicializa el pin del zumbador como una salida
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char i;

  while(1){
    // statement
    //proporciona una frecuencia
    for(int i=0; i<80; i++){
      digitalWrite(buzzer, HIGH);
      delay(1000); //Espera 1 ms
      digitalWrite(buzzer, LOW);
      delay(1000); //Espera 1 ms
    }
    //proporciona otra frecuencia
    for(int i=0; i<150; i++){
      digitalWrite(buzzer, HIGH);
      delay(1000); //Espera 1 ms
      digitalWrite(buzzer, LOW);
      delay(1000); //Espera 1 ms
    }
  }
}
