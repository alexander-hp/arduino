int redPin = 3;// color rojo al pin 3 en el Arduino
int greenPin = 5;// color Verde a la clavija 5 en el Arduino
int BluePin = 6;// color azul a la patilla 6 en el Arduino

void setup() {
  // put your setup code here, to run once:
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (BluePin, OUTPUT);
}

/*Estos argumentos representan el brillo de los LEDs o el ciclo
de trabajo de la señal PWM que se crea mediante la función
analogWrite(). Estos valores pueden variar de 0 a 255
representando el ciclo de trabajo del 100% de la señal PWM o
el brillo máximo de LED.
*/

void loop() {
  // put your main code here, to run repeatedly:
  setColor (255, 0, 0); // Color rojo
   delay(1000);
   
   setColor (0, 255, 0); // Color verde
   delay(1000);
   setColor (0, 0, 255); // Color azul
   delay(1000);
   setColor (255, 255, 255); // Color blanco
   delay(1000);
   setColor (180, 0, 255); // Color púrpura
   delay(1000);
}

/* 
 *  En la parte inferior del dibujo tenemos esta función
personalizable, llamado setColor(), cual toma 3 argumentos
diferentes: redValue, greenValue y blueValue.
*/
void setColor (int redValue, int greenValue, int blueValue) {
 analogWrite (redPin, redValue);
 analogWrite (greenPin, greenValue);
 analogWrite (BluePin, blueValue);
}
