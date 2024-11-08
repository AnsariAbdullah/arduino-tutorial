#define RED_LED 12
#define YELLOW_LED 11
#define GREEN_LED 10
#define BUTTON_PIN 2

int LEDBlinkState = 1;

void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

void loop()
{
  if(digitalRead(BUTTON_PIN) == LOW){
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
    delay(300);
  }  
}