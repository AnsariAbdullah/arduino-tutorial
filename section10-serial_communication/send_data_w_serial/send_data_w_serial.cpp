// sending data means sending some value to arduino using serial i.e. making it print something

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int num = 7;
  
  Serial.print("This int value is: ");
  Serial.print(num);
  Serial.println(".");
  delay(1000);
}