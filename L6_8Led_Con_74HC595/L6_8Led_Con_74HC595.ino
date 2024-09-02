nt latchPin = 4; // Pin 12 (RCLK) del registro de desplazamientoal pin 4 en Arduino – esto se denominará “pin de seguridad”int clockPin = 5; // Pin 11 (SRCLK) del registro de desplazamientoal pin 5 en Arduino – esto se denominará “pin de reloj”
int dataPin = 2; // Pin 14 (SER) del registro de desplazamientoal
// pin 2 en Arduino – esto se denominará “pin de datos”

byte leds = 0; // Se define una variable denominada “leds”. Estose utilizará para guardar el patrón de los LED que estánactualmente encendidos o apagados. Los datos del tipo“byte”representan números usando ocho bits. Cada bit puedeestarencendido o apagado, así que esto es perfecto para mantenerun registro de cuáles de nuestros ocho LED están encendidosoapagados.

int currentLED = 0;
void setup() {
  // put your setup code here, to run once:
  // La función “configuración” simplemente configuralostres pines que estamos utilizando como salidas digitales. pinMode(latchPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  leds = 0;
}

void loop() {
  // put your main code here, to run repeatedly:

  // ?En el método de bucle, despejamos los bits de lavariable“leds” al inicio de cada repetición para que todos los bitsesténen 0 ya que solo queremos encender un LED cada vez. Después
  // ?de esto, incrementaremos o reiniciaremos la variableLEDactual para iluminar a continuación el LED correcto.
  leds = 0;

  if (currentLED == 7){
    currentLED = 0;
  } else {
    currentLED++;
  }

  bitSet(leds, currentLED);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(250);
}
