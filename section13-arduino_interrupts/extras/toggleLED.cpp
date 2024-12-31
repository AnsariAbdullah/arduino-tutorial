#define BUTTON_PIN 2
#define LED_PIN 12

volatile bool buttonPressedState = false;

volatile unsigned long lastButtonToggle = millis();
unsigned long debounceDelay = 50;


void buttonToggleInterrupt(){
  unsigned long timeNow = millis();
  if(timeNow - lastButtonToggle > debounceDelay){
    lastButtonToggle = timeNow;
    buttonPressedState = digitalRead(BUTTON_PIN);
  }
}


void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),
                 buttonToggleInterrupt,
                 CHANGE);
}

void loop() {
  if(buttonPressedState){
  	digitalWrite(LED_PIN, HIGH);
  }else{
  	digitalWrite(LED_PIN, LOW);
  }
}