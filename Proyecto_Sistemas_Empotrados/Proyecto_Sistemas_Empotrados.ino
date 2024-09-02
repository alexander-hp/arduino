#include <SoftwareSerial.h>

SoftwareSerial BT(9, 10); // RX, TX del módulo Bluetooth
int trigPin = 11;
int echoPin = 12;
int LedPin1 = 8; // Primer LED
int LedPin2 = 7; // Segundo LED
const int tiltSensorPin = 5; // Pin del sensor de inclinación
char CharIN = ' ';


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LedPin1, OUTPUT); // Inicializa el primer LED como una salida
  pinMode(LedPin2, OUTPUT); // Inicializa el segundo LED como una salida
  pinMode(tiltSensorPin, INPUT); // Inicializa el pin del sensor de inclinación como entrada
  BT.begin(9600); // Inicia la comunicación con el módulo Bluetooth
  Serial.begin(9600); // Puerto serial para depuración
}

void loop() {

  if(BT.available()){
    CharIN = BT.read();
    Serial.println(CharIN);
  }

  // Leer el valor del sensor de inclinación
  int tiltValue = analogRead(tiltSensorPin);

  // Emitir un pulso ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medir el tiempo de vuelo del eco ultrasónico
  long duration = pulseIn(echoPin, HIGH);

  // Calcular la distancia en centímetros
  int distance_cm = duration * 0.034 / 2; // Distancia = (tiempo * velocidad del sonido) / 2

  // Imprimir la distancia en el puerto serial
  Serial.print("Distancia: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // Si la distancia es menor que 10 cm o si se detecta inclinación, activar la alarma
  if (tiltValue > 1000) {
    digitalWrite(LedPin2, LOW); // Apagar el segundo LED
  } else {
    BT.println("¡ALERTA!inclinación en la caja/armario."); // Enviar alerta por Bluetooth
    digitalWrite(LedPin2, HIGH); // Encender el segundo LED
  }

  if(distance_cm > 10){
    digitalWrite(LedPin1, LOW); // Apagar el primer LED
  } else {    
    BT.println("¡ALERTA!  Se ha detectado movimiento."); // Enviar alerta por Bluetooth
    digitalWrite(LedPin1, HIGH); // Encender el primer LED
  }

  // Esperar un tiempo antes de tomar otra lectura
  delay(1000);
}
