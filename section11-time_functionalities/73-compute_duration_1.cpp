
void setup()
{
  Serial.begin(115200);
  unsigned long timeBegin = millis();
  delay(1000); // inseatd of delay we can cehck a functionality here and see how long does it takes to perform it
  unsigned long timeEnd = millis();
  unsigned long duration = timeEnd - timeBegin;
  Serial.print("The time duration is: ");
  Serial.println(duration);
}

void loop()
{
  
}