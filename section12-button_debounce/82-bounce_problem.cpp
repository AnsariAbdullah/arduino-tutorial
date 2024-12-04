#define BUTTTON_PIN 2

byte buttonState = LOW;

void setup()
{
  Serial.begin(115200);
  pinMode(BUTTTON_PIN, INPUT);
}

void loop()
{
  byte newButtonState = digitalRead(BUTTTON_PIN);
  
  if(newButtonState != buttonState){
  	buttonState = newButtonState;
    if(buttonState == HIGH){
      Serial.println("Button pressed");
    }else{
      Serial.println("Button released");
    }
  }
}