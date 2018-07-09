#define PIEZO 3 // PWM-capable pin
int d = 100;

void setup() {
  pinMode(PIEZO, OUTPUT);
}

void loop() {
  analogWrite(PIEZO, 128);  // 50 percent duty cycle tone to the piezo
  delay(d);
  digitalWrite(PIEZO, LOW);
  delay(d);
}
