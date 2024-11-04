#define RED_LED 12
#define YELL_LED 11
#define GREEN_LED 10
#define BUTTON_PIN 2

unsigned long ledBlinkTime = millis();
unsigned long blinkWait = 1000;
unsigned long lastButtonStateChange = millis();
unsigned long debounceTime = 50;
byte buttonState = LOW;

int greenLEDState = LOW;

int RED_LIGHT = HIGH;
int YELL_LIGHT = LOW;

void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(YELL_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(RED_LED, RED_LIGHT);
}

void blinkLed (){
  if(greenLEDState == LOW){
    greenLEDState = HIGH;
  }else{
    greenLEDState = LOW;
  }
  digitalWrite(GREEN_LED, greenLEDState);
}

void toggleLEDs(){
  if(buttonState == HIGH){
    RED_LIGHT = LOW;
    YELL_LIGHT = HIGH;
    digitalWrite(RED_LED, RED_LIGHT);
    digitalWrite(YELL_LED, YELL_LIGHT);
  }else{
    RED_LIGHT = HIGH;
    YELL_LIGHT = LOW;
    digitalWrite(RED_LED, RED_LIGHT);
    digitalWrite(YELL_LED, YELL_LIGHT);

  }
}

void loop()
{
  unsigned long timeNow = millis();
  
  //make LED blink every 1000 ms (1 sec)
  if(timeNow - ledBlinkTime >= blinkWait){
  	ledBlinkTime += blinkWait;
    blinkLed();
  }
  
  //toggle LEDs on button press
  if(timeNow - lastButtonStateChange > debounceTime){
  	byte newButtonState = digitalRead(BUTTON_PIN);
    if(newButtonState != buttonState){
      lastButtonStateChange+= timeNow;
      buttonState = newButtonState;
      toggleLEDs();
    }
  } 
}