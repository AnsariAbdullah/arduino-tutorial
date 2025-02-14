#define ECHO_PIN 3
#define TRIGGER_PIN 4
#define R_LED 12
#define Y_LED 11
#define G_LED 10

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

void powerOnLED(double distance){
  if(distance >= 100){
    digitalWrite(G_LED, HIGH);
    digitalWrite(Y_LED, LOW);
    digitalWrite(R_LED, LOW);
  }else if (distance >= 15){
    digitalWrite(G_LED, LOW);
    digitalWrite(Y_LED, HIGH);
    digitalWrite(R_LED, LOW);
  }else {
    digitalWrite(G_LED, LOW);
    digitalWrite(Y_LED, LOW);
    digitalWrite(R_LED, HIGH);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(R_LED, OUTPUT);
  pinMode(Y_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
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
    powerOnLED(distance);
    Serial.println(distance);
  }
}