/*
  This is a play on the original Blink. But creates a police siren using 3 leds.
  
  Pin setup
=====================================

  Pin6 - White LED
  Pin11 - Red LED 
  Pin10 - Blue LED
 */

// PINS
int white = 6;
int red = 11;
int blue = 10;
 
// RATES
int rate = 30;
int rateSlow = 150;
int rateStrobe = 8;

// PWM Brightness
int bright = 255;
int light = 30;
int off = 0;

void start() {
  analogWrite(white, light / 4);
  analogWrite(red, light);
  analogWrite(blue, light);
}


void fast() {
  analogWrite(blue, light);  
  delay(rate);             
  analogWrite(red, off); 
  delay(rate);          
  analogWrite(blue, off);  
  delay(rate);          
  analogWrite(red, light);   
  delay(rate);
}


void slow() {
  analogWrite(blue, light);  
  delay(rateSlow);            
  analogWrite(red, off);    
  delay(rateSlow);            
  analogWrite(blue, off);   
  delay(rateSlow);            
  analogWrite(red, light);    
  delay(rateSlow);
}


void normal(int count = 1) {
  for (int i=0; i <= count; i++){
      slow();
      fast();
   }
}


void strobe(int count = 1) {
  for (int i=0; i <= count; i++){
      analogWrite(white, light / 4);
      delay(rateStrobe);
      analogWrite(red, off);  
      delay(rateStrobe);  
      analogWrite(blue, off);
      delay(rateSlow);
      analogWrite(white, bright / 4);
      delay(rateStrobe);
      analogWrite(red, bright);
      delay(rateStrobe);  
      analogWrite(blue, bright);
      delay(rateStrobe);
   } 
}


// INI
void setup() {  
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(white, OUTPUT);
}


// THE LOOP
void loop() { 

  // Reset
  start(); 
  
  // Normal, fast -> slow operation
  normal(10);
    
  // Strobe 
  strobe(20); 
}
