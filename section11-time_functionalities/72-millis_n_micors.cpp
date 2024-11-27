
void setup()
{
  Serial.begin(115200);
  delay(1000);
  unsigned long timeValue = millis();
  Serial.println(timeValue);
}

void loop()
{
  
  Serial.println(millis());
  delay(1000);
}

// millis is used to give us time in mili seconds.
// it gives us time since the arduino started and not of todays current date and time.
// so when the board starts it gives us time from 0 and gives times.
// we can also use macros() which returns time in microseconds