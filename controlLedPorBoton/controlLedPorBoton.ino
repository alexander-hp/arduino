int LedPin = 5; // color rojo al pin 5 en el Arduino
int buttonApin = 9;// un botón al pin 9 en el Arduino
int buttonBpin = 8;// otro botón para el pin 8 en el Arduino


void setup() {  // put your setup code here, to run once:
  pinMode (LedPin, OUTPUT);
  pinMode (buttonApin, INPUT_PULLUP);
  pinMode (buttonBpin, INPUT_PULLUP); 
}


/* El pinMode de INPUT_PULLUP significa que el pin se va a
utilizar como entrada, pero que si nada más se conecta a la
entrada, debe ser 'levantado' en ALTO. Es decir, el valor de la
entrada por defecto es alto, a menos que se tire BAJA por la
acción de pulsar el botón.
*/

void loop() {
//  digitalWrite(LedPin, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(LedPin, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);   
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonApin) == LOW){
    digitalWrite(LedPin, HIGH);
  };
  if (digitalRead(buttonBpin) == LOW){
    digitalWrite(LedPin, LOW);
  };
}
