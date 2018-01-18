#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

// Led vars
int led_1 = 9;
int led_2 = 10;
int led_bright = 5;
int led_dimm = 1;
int led_off = 0;
int led_rate_fast = 30;

void setup() {
  
  // Setup Led
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  analogWrite(led_1, led_dimm);
  analogWrite(led_2, led_dimm);
  
  // Setup LCD
  lcd.begin(16, 2);
  lcd.clear();
}


void flashWhite() {
  analogWrite(led_1, led_bright);  
  delay(led_rate_fast);             
  analogWrite(led_1, led_dimm);
}

void flashRed() {
  analogWrite(led_2, led_bright);  
  delay(led_rate_fast);             
  analogWrite(led_2, led_dimm);
}


void loop() {
  flashWhite();
  lcd.print("Helloooo There!");
  delay(2000);
  lcd.clear();
  flashRed();
  lcd.print("How you doing?");
  delay(2000);
  lcd.clear();
}
