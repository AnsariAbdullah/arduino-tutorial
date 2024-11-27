#define RED_PIN 12
#define YELL_PIN 11
#define GREEN_PIN 10
#define POTENTIOMETER A2
#define BUTTTON 2

int RED_PIN_STATE = LOW;
int YELL_PIN_STATE = LOW;
int GREEN_PIN_STATE = LOW;

unsigned long LED_blinkTime = millis();
unsigned long delayOf = 500;

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELL_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUTTTON, INPUT);
}

void loop()
{
  if(Serial.available() > 0){
    int delayValue = Serial.parseInt();
    if((delayValue >= 100) && (delayValue <= 4000)){
      Serial.println(delayValue);
      delayOf = delayValue;
    }
  }
  
  unsigned long timeNow = millis();
  
  if(timeNow - LED_blinkTime >= delayOf){
    if(RED_PIN_STATE == LOW){
      RED_PIN_STATE = HIGH;
    }else{
   	 RED_PIN_STATE = LOW;
    }
    digitalWrite(RED_PIN, RED_PIN_STATE);
    LED_blinkTime += delayOf;
  }
  
  // potentiometer
  int potentiometerValue = analogRead(POTENTIOMETER);
  int LED_Brightness = potentiometerValue / 4;
  analogWrite(YELL_PIN, LED_Brightness);
  
  // button
  if(digitalRead(BUTTTON) == HIGH){
    digitalWrite(GREEN_PIN, HIGH);
  }else{
    digitalWrite(GREEN_PIN, LOW);
  }
  
}