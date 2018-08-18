// thanks to arduino forums user dfvr1994 for this
// https://forum.arduino.cc/index.php?PHPSESSID=pus4sfuvv8l714hlv790qt8822&topic=488814.15

#define WAIT_SECS   60

const byte pirPin =  12;
const byte relayPin = 2;

const byte calibrationTime = 20;
boolean alarmState = 0;
int countDown = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  digitalWrite(relayPin, 1); // high before pinMode stops relay chattering during bootup
  pinMode(relayPin, OUTPUT);
  Serial.print(F("calibrating sensor "));
  for (int i = 0; i < calibrationTime; i++)
  {
    Serial.print(F("."));
    delay(1000);
  }
  Serial.println(F(" done"));
  Serial.println(F("SENSOR ACTIVE"));
  Serial.println(F("-------------"));
}

void loop() {
  if (digitalRead(pirPin) && !alarmState)
  { // PIR active and no alarm
    digitalWrite(relayPin, HIGH);
    Serial.println("motion detected");
    Serial.println("Relay ON");
    countDown = WAIT_SECS * 100; // 10-ms chunks
    alarmState = HIGH; // remember it
  }
  if (countDown == 0 && alarmState)
  { // end of countdown and alarm
    digitalWrite(relayPin, LOW);
    Serial.println(F("Relay OFF"));
    Serial.println(F("---------"));
    alarmState = LOW; // remember it
  }


  if (countDown > 0)
  {
    if (digitalRead(pirPin) == HIGH)
    { countDown = WAIT_SECS * 100; // 10-ms chunks
      digitalWrite(relayPin, HIGH); // relay on   
      Serial.println(F("motion detected"));
    }
    
    // if countdown is still running
    Serial.println(countDown);
    delay(10); 
    countDown --; // -1
  }
}

