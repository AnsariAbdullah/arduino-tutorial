#define BUTTTON_PIN 2

byte buttonState = LOW;

unsigned long lastTimeBttonChanged = millis();
unsigned long buttonDebounce = 50;

void setup()
{
  Serial.begin(115200);
  pinMode(BUTTTON_PIN, INPUT);
}

void loop()
{
  
  unsigned long timeNow = millis();
  if(timeNow - lastTimeBttonChanged > buttonDebounce){  
    byte newButtonState = digitalRead(BUTTTON_PIN);
    
    if(newButtonState != buttonState){
      lastTimeBttonChanged = timeNow;
  	  buttonState = newButtonState;
      if(buttonState == HIGH){
        Serial.println("Button pressed");
      }else{
        Serial.println("Button released");
      }
    }
  } 
}