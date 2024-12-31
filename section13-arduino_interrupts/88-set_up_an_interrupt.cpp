#define BUTTON_PIN 2
#define LED_PIN 12

byte LEDState = LOW;
// when using global variables in itterupt function use volatile keyword before it
// this lets arduino handle it better
volatile bool buttonReleased = false;

void toggleLED(){
  if(LEDState == LOW){
  	LEDState = HIGH;
  }else{
  	LEDState = LOW;
  }
  digitalWrite(LED_PIN, LEDState);
}

//inrruprt function should not return anything
//i.e. it should be void
// it should also not take any parameters
void buttonReleasedInterrupt(){
  buttonReleased = true;
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),
                  buttonReleasedInterrupt,
                  FALLING);
}

void loop() {
  if(buttonReleased){
  	buttonReleased = false;
    toggleLED();
  }
}