#define RED_LED 12
#define YELLOW_LED 11
#define GREEN_LED 10
#define BUTTON_PIN 2

int LEDBlinkState = 1;
byte LEDPinArray[3] = {
  RED_LED,
  YELLOW_LED,
  GREEN_LED
};

void setLEDPinModes(){
  for(int i=0; i<3; i++){
    pinMode(LEDPinArray[i], OUTPUT);
  }
}

void turnOffAllLEDs(){
  for(int i=0; i<3; i++){
  	digitalWrite(LEDPinArray[i], LOW);
  }
}

void toggleLEDs(){
  if(LEDBlinkState == 1){
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    LEDBlinkState = 2;
  }else{
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    LEDBlinkState = 1;
  }
}

void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  setLEDPinModes();
  turnOffAllLEDs();
}

void loop()
{
  if(digitalRead(BUTTON_PIN) == LOW){
    toggleLEDs();
    delay(300);
  }  
}