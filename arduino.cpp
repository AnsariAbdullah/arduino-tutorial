// defining a constant variable
#define INTERNAL_LED 13

// defining a varibale
int EXT_LED = 12;

// defining an Array
int temp[3] = {21, 22, 23};
// 3 here defined the size of the array

void setup()
{
  pinMode(INTERNAL_LED, OUTPUT);
  pinMode(EXT_LED, OUTPUT);
	Serial.begin(9600);
	
	// accessing value of array
	Serial.println(temp[1]);

	// changing the value at an index
	temp[1] = 30;
	Serial.println(temp[1]);

	// using for loop to print all items of array
	for(int i=0; i<3; i++){
    Serial.println(temp[i]);
  }
}

void loop()
{
  digitalWrite(EXT_LED, HIGH);
  digitalWrite(INTERNAL_LED, HIGH);
  delay(1000);
  digitalWrite(EXT_LED, LOW);
  digitalWrite(INTERNAL_LED, LOW);
  delay(1000);
}