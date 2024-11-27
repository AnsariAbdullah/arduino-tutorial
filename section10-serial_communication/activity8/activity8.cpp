#define LED_PIN 12
int delayOf = 100;
int LED_state = LOW;

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
    if((delayValue >= 100) && (delayValue <= 1000)){
      Serial.println(delayValue);
      delayOf = delayValue;
    }
  }
  
  if(LED_state == LOW){
    LED_state = HIGH;
  }else{
  	LED_state = LOW;
  }
  
  digitalWrite(LED_PIN, LED_state);
  delay(delayOf);
	// delayMicroseconds() - this can alo be used. this takes value of microsecods as params instead of milisecond like delay()
	// 1 sec = 1000 mili seconds
	// 1 mili second = 1000 microseconds
}