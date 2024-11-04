#define RED_LED 12
#define YELL_LED 11
#define GREEN_LED 10
#define BUTTON_PIN 2

unsigned long ledBlinkTime = millis();
unsigned long blinkWait = 1000;
int greenLEDState = LOW;

unsigned long lastButtonStateChange = millis();
unsigned long debounceTime = 50;
byte buttonState = LOW;

int toggleLEDState = 1;


int RED_LIGHT = HIGH;
int YELL_LIGHT = LOW;

void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(YELL_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
	buttonState = digitalRead(BUTTON_PIN);
  digitalWrite(RED_LED, RED_LIGHT);
}

void loop()
{
  unsigned long timeNow = millis();
  
  //make LED blink every 1000 ms (1 sec)
  if(timeNow - ledBlinkTime >= blinkWait){
  	ledBlinkTime += blinkWait;
    if(greenLEDState == LOW){
      greenLEDState = HIGH;
    }else{
      greenLEDState = LOW;
    }
    digitalWrite(GREEN_LED, greenLEDState);
  }
  
  //toggle LEDs on button press
  if(timeNow - lastButtonStateChange > debounceTime){
  	byte newButtonState = digitalRead(BUTTON_PIN);
    if(newButtonState != buttonState){
      lastButtonStateChange = timeNow;
      buttonState = newButtonState;
      if(buttonState == HIGH){
				if(toggleLEDState == 1){
					toggleLEDState = 2;
					digitalWrite(RED_LED, LOW);
        	digitalWrite(YELL_LED, HIGH);
				}else{
					toggleLEDState = 1;
					digitalWrite(RED_LED, HIGH);
        	digitalWrite(YELL_LED, LOW);
				}        
      }else{
        RED_LIGHT = HIGH;
        YELL_LIGHT = LOW;
        digitalWrite(RED_LED, RED_LIGHT);
        digitalWrite(YELL_LED, YELL_LIGHT);
        
      }
    }
  } 
}