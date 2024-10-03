#define LED_PORT 11

void setup()
{
  pinMode(LED_PORT, OUTPUT);
}

void loop()
{
  for(int i=0; i<=255; i++){
    analogWrite(LED_PORT, i);
  	delay(5);
  }
  
  for(int i=255; i>=0; i--){
    analogWrite(LED_PORT, i);
    delay(5);
  }
}

// refer the same circuit of led_blink_digital_pwm_port