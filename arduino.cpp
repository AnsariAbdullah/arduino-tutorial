#define INTERNAL_LED 13
int EXT_LED = 12;

void setup()
{
  pinMode(INTERNAL_LED, OUTPUT);
  pinMode(EXT_LED, OUTPUT);
}

void loop()
{
  digitalWrite(EXT_LED, HIGH);
  digitalWrite(INTERNAL_LED, HIGH);
  delay(1000);
  digitalWrite(EXT_LED, LOW);
  digitalWrite(INTERNAL_LED, LOW);
  delay(1000);
}