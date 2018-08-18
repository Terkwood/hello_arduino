// uses the LCD setup described in https://www.sunfounder.com/learn/Super-Kit-V2-0-for-Arduino/lesson-8-lcd1602-super-kit.html
// ...and adds a thermistor reading on pin A0

#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

/*********************************************************/
void setup()
{
  lcd.begin(16, 2); // set number of columns and rows
  lcd.clear();
}
/*********************************************************/
void loop()
{
    Vo = analogRead(ThermistorPin);
    R2 = R1 * (1023.0 / (float)Vo - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    Tc = T - 273.15;
    Tf = (Tc * 9.0)/ 5.0 + 32.0;
    lcd.setCursor(5,0);
    lcd.print(Tf);
    lcd.print("F");
    lcd.setCursor(5,1);
    lcd.print(Tc);
    lcd.print("C");

    delay(5000);
}
/************************************************************/
