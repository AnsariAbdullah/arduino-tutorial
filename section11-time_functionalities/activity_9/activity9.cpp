#define LED_PIN 12
int LED_state = LOW;

unsigned long LED_blinkTime = millis();
unsigned long delayOf = 500;

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(LED_PIN, OUTPUT);
  
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
    if(LED_state == LOW){
      LED_state = HIGH;
    }else{
   	 LED_state = LOW;
    }
    digitalWrite(LED_PIN, LED_state);
    LED_blinkTime += delayOf;
  }
}