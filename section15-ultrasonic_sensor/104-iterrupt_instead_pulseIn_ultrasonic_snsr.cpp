#define ECHO_PIN 3
#define TRIGGER_PIN 4

unsigned long lastTimeSensorTriggered = millis();
unsigned long sensorTriggerDelay = 100;

volatile unsigned long pulseInTimeBegin;
volatile unsigned long pulseInTimeEnd;
volatile bool newDistanceAvailable = false;

void triggerSensor() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}

double getUltrasonicDistance() {
  double durationMicros = pulseInTimeEnd - pulseInTimeBegin;
  double distance = durationMicros / 58.0;
  return distance;
}

void echoPointInterrupt(){
  if(digitalRead(ECHO_PIN) == HIGH){ //start measuring
  	pulseInTimeBegin = micros();
  }else{ //stop measuring
  	pulseInTimeEnd = micros();
    newDistanceAvailable = true;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ECHO_PIN),
                 echoPointInterrupt,
                 CHANGE);
}

void loop() {
  unsigned long timeNow = millis();
  if(timeNow - lastTimeSensorTriggered > sensorTriggerDelay){
    lastTimeSensorTriggered += timeNow;
    triggerSensor();
  }
  
  if(newDistanceAvailable){
  	newDistanceAvailable = false;
    double distance = getUltrasonicDistance();
    Serial.println(distance);
  }
}