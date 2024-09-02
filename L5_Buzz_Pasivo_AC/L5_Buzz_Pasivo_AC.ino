//El propósito del experimento es generar ocho diferentes sonidos, 
//cada sonido durará 1 segundos: desde Do (262Hz),
//Re (294Hz), Mi (330Hz), Fa (349Hz), Sol (392Hz), La
//(440Hz), Si (494Hz) hasta Do Agudo (524Hz)//

int Do = 262, Re = 294, Mi = 330, Fa = 349, Sol = 392,
 La = 440, Si = 494, Do2 = 524;

int buzz = 12; //¡¡¡No es necesario un pin PWM, cualquier pin digital funcionará!!!
int wait = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(buzz, OUTPUT);//Inicializa el pin del zumbador como una salida
}

void loop() {
  // put your main code here, to run repeatedly:
  wait = 500;
  tone(buzz, Do, wait);
  delay(1000);
  tone(buzz, Re, wait);
  delay(1000);
  tone(buzz, Mi, wait);
  delay(1000);
  tone(buzz, Fa, wait);
  delay(1000);
  tone(buzz, Sol, wait);
  delay(1000);
  tone(buzz, La, wait);
  delay(1000);
  tone(buzz, Si, wait);
  delay(1000);
  tone(buzz, Do2, wait);
  delay(1000);

  noTone(buzz); // Para la tonada
}
