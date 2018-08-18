/*
 * The thermistor-specific code in this repo 
 * was provided by 
 * http://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/
 * Thank you!
 */

#define THERMISTOR_PIN 0
#define PIEZO_PIN      3 // PWM-capable pin
#define HOT_F         90
#define COLD_F        32
#define BUZZ_DELAY   100

int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  pinMode(PIEZO_PIN, OUTPUT);
  Serial.begin(9600);
}

void buzz_temp(int tf) {
  int pitch = 1; // stay quiet if temp is normal
  
  if (tf > HOT_F) {
    pitch = 255; // shrill and horrible
  } else if (tf <= COLD_F) {
    pitch = 128; // obstreperous
  }

  for (int i = 10; i < tf; i += 10) {
    analogWrite(PIEZO_PIN, pitch);
    delay(BUZZ_DELAY);
    digitalWrite(PIEZO_PIN, LOW);
    delay(BUZZ_DELAY);
  }
}

void loop() {

  Vo = analogRead(THERMISTOR_PIN);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0)/ 5.0 + 32.0; 

  Serial.print("Temperature: "); 
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");   

  buzz_temp(Tf);

  delay(1000);
}

