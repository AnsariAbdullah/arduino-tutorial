#define PHOTORESISTOR_PIN A0
#define LUMINOSITY_SAMPLE_SIZE 100

int luminositySamples[LUMINOSITY_SAMPLE_SIZE] = {0};
int indexCounter = 0;


unsigned long lastTimeReadLuminosity = millis();
unsigned long luminositySampleDelay = 50;

int computeAverageLuminosity(){
  long sum;
  for(int i = 0; i<LUMINOSITY_SAMPLE_SIZE; i++){
  	sum += luminositySamples[i];
  }
  return sum / LUMINOSITY_SAMPLE_SIZE;
}

void printAverageLuminosity(){
  int average = computeAverageLuminosity();
  Serial.println("");
  Serial.print("Average luminosity for ");
  Serial.print(LUMINOSITY_SAMPLE_SIZE);
  Serial.print(" samples, taken every ");
  Serial.print(luminositySampleDelay);
  Serial.print(" milliseconds ");
  Serial.println(average);
}

void setup(){
  Serial.begin(115200);
}

void loop() {
  unsigned long timeNow = millis();
  if(timeNow - lastTimeReadLuminosity > luminositySampleDelay){
  	lastTimeReadLuminosity += luminositySampleDelay;
    if(indexCounter == LUMINOSITY_SAMPLE_SIZE){
      indexCounter = 0;
      printAverageLuminosity();
    }
    luminositySamples[indexCounter] = analogRead(PHOTORESISTOR_PIN);
    indexCounter++;
    Serial.print(".");
  }

}
