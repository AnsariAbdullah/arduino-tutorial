// this program is an example where you can use millis instead of delay to perform multiple actions at the same time

#define LED_RED 12
#define LED_YELLOW 11
#define LED_GREEN 10
unsigned long previousTimeRedBlink = millis();
unsigned long timeIntervalRedBlink = 500;

unsigned long previousTimeYellowBlink = millis();
unsigned long timeIntervalYellowBlink = 1000;

int RED_LED_state = LOW;
int YELLOW_LED_state = LOW;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  
  digitalWrite(LED_GREEN, HIGH);
  delay(2000);
  digitalWrite(LED_GREEN, LOW);
}

void loop()
{
  //current time
  unsigned long timeNow = millis();
  
  //action 1
  if(timeNow - previousTimeRedBlink >= timeIntervalRedBlink){
    if(RED_LED_state == LOW){
      RED_LED_state = HIGH;
    }else{
    	RED_LED_state = LOW;
    }
    digitalWrite(LED_RED, RED_LED_state);
    previousTimeRedBlink += timeIntervalRedBlink;
  }
  
  //action 2
  if(timeNow - previousTimeYellowBlink >= timeIntervalYellowBlink){
    if(YELLOW_LED_state == LOW){
      YELLOW_LED_state = HIGH;
    }else{
      YELLOW_LED_state = LOW;
    }
    digitalWrite(LED_YELLOW, YELLOW_LED_state);
    previousTimeYellowBlink += timeIntervalYellowBlink;
  }
}