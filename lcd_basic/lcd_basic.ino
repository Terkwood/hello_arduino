// from https://www.sunfounder.com/learn/Super-Kit-V2-0-for-Arduino/lesson-8-lcd1602-super-kit.html

#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
/*********************************************************/
void setup()
{
  lcd.begin(16, 2); // set number of columns and rows
  lcd.clear();
}
/*********************************************************/
void loop()
{
   lcd.setCursor(0,0);
   lcd.print("Hello Arduino");
   lcd.setCursor(0,1);
   lcd.print("Hello Buddy");

  delay(1000);
}
/************************************************************/
