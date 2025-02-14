#include <IRremote.h>
#include <LiquidCrystal.h>

// LCD
#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_DB4_PIN 6
#define LCD_DB5_PIN 7
#define LCD_DB6_PIN 8
#define LCD_DB7_PIN 9

// LED Pins
#define RED_LED 12
#define YELLOW_LED 11
#define GREEN_LED 10

// LED Size
#define LED_ARRAY_SIZE 3

// IR Pin
#define IR_RECIEVE_PIN 5

// remote buttons
#define IR_BUTTON_0 12
#define IR_BUTTON_1 16
#define IR_BUTTON_2 17
#define IR_BUTTON_3 18
#define IR_BUTTON_FUNC_STOP 2

byte LEDArray[LED_ARRAY_SIZE] = {RED_LED, YELLOW_LED, GREEN_LED};
byte LEDStateArray[LED_ARRAY_SIZE] = {LOW, LOW, LOW};

void initLEDModes(){
  for(int i=0; i<LED_ARRAY_SIZE; i++){
    pinMode(LEDArray[i], OUTPUT);
  }
}

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_DB4_PIN,
                 LCD_DB5_PIN, LCD_DB6_PIN, LCD_DB7_PIN);

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECIEVE_PIN);
  initLEDModes();
  lcd.begin(16, 2);
}

void powerOffAllLEDs(){
  for(int i=0; i<LED_ARRAY_SIZE; i++){
    LEDStateArray[i] = LOW;
    digitalWrite(LEDArray[i], LOW);
  }
}

void toggleLEDFromIndex(int index){
  if(index >= LED_ARRAY_SIZE){
    return;
  }
  if(LEDStateArray[index] == HIGH){
    LEDStateArray[index] = LOW;
  }else {
    LEDStateArray[index] = HIGH;
  }
  digitalWrite(LEDArray[index], LEDStateArray[index]);
}

void printCommandOnLCD(int command){
  lcd.setCursor(0, 0);
  lcd.print(command);
  lcd.print("      ");
}

void printActionOnLCD(String action){
  lcd.setCursor(0, 1);
  lcd.print(action);
}


void loop() {
  if(IrReceiver.decode()){
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    
    switch(command){
      case IR_BUTTON_0:
      	Serial.println("Zero pressed");
      	powerOffAllLEDs();
        printCommandOnLCD(command);
        printActionOnLCD("Power off LEDs. ");
      	break;
      case IR_BUTTON_1:
      	//Serial.println("One pressed");
      	toggleLEDFromIndex(0);
      	printCommandOnLCD(command);
      	printActionOnLCD("Toggle LED 1.   ");
      	break;
      case IR_BUTTON_2:
      	//Serial.println("Two pressed");
      	toggleLEDFromIndex(1);
      	printCommandOnLCD(command);
      	printActionOnLCD("Toggle LED 2.   ");
      	break;
      case IR_BUTTON_3:
      	//Serial.println("Three pressed");
      	toggleLEDFromIndex(2);
      	printCommandOnLCD(command);
      	printActionOnLCD("Toggle LED 3.   ");
      	break;
      case IR_BUTTON_FUNC_STOP:
      	//Serial.println("Function pressed");
      	lcd.clear();
      	break;
      default:
      	//Serial.println("Incorrect button");
      	printCommandOnLCD(command);
      	printActionOnLCD("Not recognized. ");
    }
  }
}