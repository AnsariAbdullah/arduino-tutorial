#define POTENTIO_METER A2
#define LED_PIN 11

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
	// use analogWrite to light LED
	// use analogRead to read value coming from potentiomete
	// the LED has to be connected to PWM digital pin
	// since LED connected to PWD pin accepts value between 0-255 and potentiometer provides value between 0-1023 we have to divide the value coming from potentiometer by 4
	// because 1023 is rougly 4 times 255. 1023/4 = 255.75 which. so every value has to be divided by 4

	int potentiometerValue = analogRead(POTENTIO_METER);
  int LEDBrigtness = potentiometerValue / 4;
  // Serial.println(LEDBrigtness);
  analogWrite(LED_PIN, LEDBrigtness);
}

// refer to led-fade-with-potentiometer.png to understadn circuit