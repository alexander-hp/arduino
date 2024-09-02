
int LedPin = 8;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LedPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LedPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LedPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
