#include <IRremote.h>

#define IR_RECIEVE_PIN 5
#define IR_BUTTON_PLAY_PAUSE 5
#define IR_BUTTON_0 12
#define IR_BUTTON_1 16
#define IR_BUTTON_2 17


void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECIEVE_PIN);
}

void loop() {
  if(IrReceiver.decode()){
  	IrReceiver.resume();
    
    int command = IrReceiver.decodedIRData.command;
    
    switch (command){
      case IR_BUTTON_0:
        Serial.println("Button 0 was pressed");
      	break;
      case IR_BUTTON_1:
      	Serial.println("Button 1 was pressed");
      	break;
      case IR_BUTTON_PLAY_PAUSE:
      	Serial.println("Play was pressed");
      	break;
      default:
      	Serial.println("Please press another button");
    }
    
  }
}