#define POTENTIO_METER A2

void setup()
{
  Serial.begin(9600);
}

void loop()
{
	// this code print the value from potentio meter
	// a potentio meter gives value between 0 - 1023
  Serial.println(analogRead(POTENTIO_METER));
  delay(100);
}

// refer to led-fade-with-potentiometer.png from circuits to understand connection