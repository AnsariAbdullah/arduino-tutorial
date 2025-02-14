#define ECHO_PIN 3
#define TRIGGER_PIN 4

unsigned long lastTimeSensorTriggered = millis();
unsigned long sensorTriggerDelay = 100;

void triggerSensor() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}

double getUltrasonicDistance() {
  double durationMicros = pulseIn(ECHO_PIN, HIGH);
  double distance = durationMicros / 58.0;
  // divide duration by 58.0 for getting distance in cm
  // divide duration by 148.0 for getting distance in inches
  // user are using .0 because duration is in double
  return distance;
}

void setup() {
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
}

void loop() {
  unsigned long timeNow = millis();
  if(timeNow - lastTimeSensorTriggered > sensorTriggerDelay){
    lastTimeSensorTriggered += timeNow;
    triggerSensor();
    Serial.println(getUltrasonicDistance());
  }
}