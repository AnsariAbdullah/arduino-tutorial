// analog pins can be used as digital pins if pinMode is used as OUTPUT.
// this normally is done when all digital pins are used and more are needed so we can use unsued analog pins as digital pins
// these pins cannot be used as PWM pins

#define LED_PIN A5

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}