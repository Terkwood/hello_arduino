#define TEMP_PIN      2
#define PIEZO_PIN     3    // PWM-capable pin

#define WAIT        100    // millis between beeps

#define HOT_C        26    
#define COLD_C       20

#define HOT_PITCH   255
#define COLD_PITCH  128
#define HAPPY_PITCH 100

float temp_voltage = 0;
float temp_sensor  = 0;
float temp_celsius = 0;

void setup() {
  pinMode(PIEZO_PIN, OUTPUT);
}

void loop() {
  analogWrite(PIEZO_PIN, 128);  // 50 percent duty cycle tone to the piezo
  delay(WAIT);
  digitalWrite(PIEZO_PIN, LOW);
  delay(WAIT);
}
