unsigned long timeBegin;
void setup()
{
  Serial.begin(115200);
  timeBegin = millis();
}

void loop()
{
  delay(1000);
  unsigned long timeEnd = millis();
  unsigned long duration = timeEnd - timeBegin;
  Serial.println(duration);
}