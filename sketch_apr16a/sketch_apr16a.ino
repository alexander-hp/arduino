// Incluye la librería Servo
#include <SoftwareSerial.h>
#include <Servo.h>
  SoftwareSerial BT (13,12);
 
  // Defines Tirg y Echo del Ultrasonic Sensor

  const int trigPin = 10;
  const int echoPin = 11;

  // Variables para la duración y distancia

long duration;
int distance;

// calcular distancia

int calculateDistance(){ 

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // leer el echoPin, retorna la honda ultrasónica
  distance= duration*0.034/2;
  return distance;

}



Servo myServo; // Creas una variable servo
void setup() {
  
  pinMode(trigPin, OUTPUT); // Sets el trigPin como un Output
  pinMode(echoPin, INPUT); // Sets el echoPin como uun Input
  Serial.begin(9600);
  BT.begin(9600);
  myServo.attach(12); // Defines los pines del servo
}

void loop() {

  if (BT.available())
    {
      Serial.write(BT.read());
    }
    if (Serial.available()){
      BT.write(Serial.read()) ; 
      Serial.print("RADAR");
  // rotacion del servo de  15 a 165 grados

  for(int i=15;i<=165;i++){  

    myServo.write(i);

    delay(30);

    distance = calculateDistance();// calcular distancia
    Serial.print(i); // (inglés)Sends the current degree into the Serial Port
    Serial.print(","); // (inglés)Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance); //(inglés) Sends the distance value into the Serial Port
    Serial.print("."); // (inglés)Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }

  // repetición

  for(int i=165;i>15;i--){  

    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");

    BT.print("Distancia: ");
    BT.print(distance);
    BT.println(" metros ");

  }

  }
}