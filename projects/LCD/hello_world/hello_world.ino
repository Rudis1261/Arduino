#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  lcd.print("Ardiuno");
  delay(3000);
  
  lcd.setCursor(2, 1);
  lcd.print("LCD Tutorial");
  delay(3000);  
  
  lcd.clear();
  
  lcd.blink();
  delay(3000);
  
  lcd.setCursor(7, 1);
  delay(3000);
  
  lcd.noBlink();
  
  lcd.cursor();
  delay(3000);
  
  lcd.noCursor();
  lcd.clear();
}
