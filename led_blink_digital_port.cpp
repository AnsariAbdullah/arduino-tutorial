// on using digital pins for blinking LED

#define LED_PORT 12

void setup()
{
  pinMode(LED_PORT, OUTPUT);
  digitalWrite(LED_PORT, HIGH);
  delay(3000);
}

void loop()
{
  digitalWrite(LED_PORT, LOW);
  delay(500);
  digitalWrite(LED_PORT, HIGH);
  delay(500);
}