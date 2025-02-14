#include <IRremote.h>
#define IR_RECIEVE_PIN 5

IRrecv irrecv(IR_RECIEVE_PIN);
decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
}