#include <OneWire.h>
#include <DallasTemperature.h>

#define TEMP_PIN      2
#define PIEZO_PIN     3    // PWM-capable pin

// create oneWire instance to talk to any OneWire devices.
// in our case, we only have an 1820B temp sensor
OneWire oneWire(TEMP_PIN);
// inform dallas temp of our oneWire reference
DallasTemperature sensors(&oneWire);

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
  
  // init serial port
  Serial.begin(9600);
  Serial.println("Hello Sensor World");
  
  // start up dallas temp library
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); 
  Serial.print("Temp: ");
  Serial.print(sensors.getTempCByIndex(0)); // 0 is the first IC on the bus
  
  /*analogWrite(PIEZO_PIN, 128);  // 50 percent duty cycle tone to the piezo
  delay(WAIT);
  digitalWrite(PIEZO_PIN, LOW);
  delay(WAIT);*/
}
