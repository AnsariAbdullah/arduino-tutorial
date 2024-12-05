#include <LiquidCrystal.h>

// Ultrasonic sensor pins
#define ECHO_PIN 3
#define TRIGGER_PIN 4

// LCD pins 
#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_DB4_PIN 6
#define LCD_DB5_PIN 7
#define LCD_DB6_PIN 8
#define LCD_DB7_PIN 9

unsigned long lastTimeSensorTriggered = millis();
unsigned long sensorTriggerDelay = 60;

volatile unsigned long pulseInTimeBegin;
volatile unsigned long pulseInTimeEnd;
volatile bool newDistance = false;

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_DB4_PIN,
                 LCD_DB5_PIN, LCD_DB6_PIN, LCD_DB7_PIN);

void triggerSensor() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}

double getUltrasonicDistance() {
  double durationMicros = pulseInTimeEnd - pulseInTimeBegin;
  double distance = durationMicros / 58.0;
  return distance;
}

void echoPointInterrupt(){
  if(digitalRead(ECHO_PIN) == HIGH){ //start measuring
  	pulseInTimeBegin = micros();
  }else{ //stop measuring
  	pulseInTimeEnd = micros();
    newDistance = true;
  }
}

//lcd.setCursor(0, 1);

void printDistanceOnLCD(double distance){
  lcd.setCursor(0,1);
  lcd.print("Distance :");
  lcd.print(distance);
  lcd.print("  ");
}

void setup() {
  lcd.begin(16, 2);
  lcd.print("Rate ");
  lcd.print(sensorTriggerDelay);
  lcd.print(" ms");
  
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ECHO_PIN),
                 echoPointInterrupt,
                 CHANGE);
}

void loop() {
  unsigned long timeNow = millis();
  if(timeNow - lastTimeSensorTriggered > sensorTriggerDelay){
  	lastTimeSensorTriggered += timeNow;
    triggerSensor();
  }
  
  if(newDistance){
    newDistance = false;
    double distance = getUltrasonicDistance();
    printDistanceOnLCD(distance);
  }
  
}