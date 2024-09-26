// C++ code
//
void setup()
{
  pinMode(13, OUTPUT);
	Serial.begin(9600);
  Serial.println("Hello Arduino");
}

void loop()
{
	Serial.println("LED on");
  digitalWrite(13, HIGH);

  delay(1000); // Wait for 1000 millisecond(s)
  Serial.println("LED off");
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}