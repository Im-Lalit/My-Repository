#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 2, 3)

int a = A0;

void setup()
{
  lcd.begin(20, 4);
  pinMode(A5, INPUT_PULLUP);
}

void loop()
{
  a = analogRead(5);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  analogReader()  ");
  lcd.setCursor(0,1);
  lcd.print(" value is :");
  lcd.print(a);
  delay(250);
}

