#define PHOTORESISTOR_PIN A0
#define THRESHOLD 930
#define RED_LED 12
#define GREEN_LED 10

void setup(){
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  int photoresistorValue =  analogRead(PHOTORESISTOR_PIN);
  if(photoresistorValue < THRESHOLD){
    digitalWrite(RED_LED, HIGH);
  }else {
    digitalWrite(RED_LED, LOW);
  }
  int brightness = 255 - photoresistorValue / 4;
  analogWrite(GREEN_LED, brightness);
}
