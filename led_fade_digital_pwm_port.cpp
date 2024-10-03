#define LED_PORT 11

//for using an PWM port use value of low and high voltage
//value varies from 0 to 255

void setup()
{
  pinMode(LED_PORT, OUTPUT);
  //analogWrite(LED_PORT, 200); // for high volatage
  analogWrite(LED_PORT, 20); //for low voltage
}

void loop()
{
}