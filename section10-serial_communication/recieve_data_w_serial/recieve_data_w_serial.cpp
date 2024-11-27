// we can recieve data sent from computer to arduino 

void setup()
{
  Serial.begin(9600); // one can also decrease the baud rate for faster communication between serial and computer. 115200 is used in many programs
	Serial.setTimeout(10); // sets the maximum milliseconds to wait for serial data 
}

void loop()
{
  if(Serial.available() > 0){ // Serial.available() gets the stored bytes from the serial port that are available for reading
  	int variable = Serial.parseInt(); // Serial.parseInt() returns the next valid number in the incoming serial

		// to send a long value use long instead of int -> int variable = Serial.parseInt();
		// to send a decimal value use double and parseFloat() -> double variable = Serial.parseFloat();
		// to send a string value use String and readString() -> String variable = Serial.readString();

		// Serial.parseInt(), Serial.parseFloat() & Serial.readString() uses one second to wait for serial data.
		// this time can be reduced using Serial.setTimeout like it is done in the setup. It takes the variable as parameter.

    Serial.println(variable);
  }
}
