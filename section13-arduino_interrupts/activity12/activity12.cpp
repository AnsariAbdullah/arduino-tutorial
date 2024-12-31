#define BUTTON_PIN 2

volatile bool buttonPressedState = false;
int counter = 0;

volatile unsigned long lastTimeButtonPressed = millis();
unsigned long debounceTime = 50;

void buttonPressedInterrupt () {
  unsigned long timeNow = millis();
  if(timeNow - lastTimeButtonPressed > debounceTime){
  	 lastTimeButtonPressed = timeNow;
     buttonPressedState = true;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),
                 buttonPressedInterrupt,
                 RISING);
}

void loop() {
  if(buttonPressedState){
  	buttonPressedState = false;
    counter++;
    Serial.println(counter);
  }
}