unsigned long previousTimeSerialPrint = millis();
unsigned long timeIntervalSerialPrint = 500;
void setup()
{
  Serial.begin(115200);
  
}

void loop()
{
  unsigned long timeNow = millis();
  if(timeNow - previousTimeSerialPrint >= timeIntervalSerialPrint){
  	Serial.println("Hello");
    previousTimeSerialPrint += timeIntervalSerialPrint;
    //Serial.println(previousTimeSerialPrint);
  }
}