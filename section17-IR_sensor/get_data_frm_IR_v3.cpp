#include <IRremote.h>

#define IR_RECIEVE_PIN 5


void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECIEVE_PIN);
}

void loop() {
  if(IrReceiver.decode()){
  	IrReceiver.resume();
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    Serial.println(IrReceiver.decodedIRData.command);
    Serial.println("---");
  }
}