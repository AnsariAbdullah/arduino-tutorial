#include <LiquidCrystal.h>

#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN,
                 LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

void setup() {
  lcd.begin(16,2);
  //use to set column and row where to start
  //both values start with 0
  //since we use 16X2 we have colum from 0-15 and row 0-1
  //lcd.setCursor(0,0) is default
  lcd.setCursor(2,0);
  lcd.print("Hello world!");
  
  lcd.setCursor(0,1);
  lcd.print("Hola!");
  
  delay(1000);
  lcd.print("Arduino");
}

void loop() {
}