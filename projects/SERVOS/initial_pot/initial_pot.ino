#include <Servo.h>
Servo myservo;
int potpin = 0;
int input = 0;
float factor = 5.68;
int output;

int leftBtn = 6;
int rightBtn = 7;
int left;
int right;

void setup() {
  Serial.begin(9600);

  pinMode(leftBtn,INPUT);
  pinMode(rightBtn,INPUT);
  myservo.attach(9);
}

void loop() {  

  //  Serial.print("Pot reading, in:");
  //  Serial.print(input, DEC);
  //  Serial.print(", out:");
  //  Serial.println(output, DEC);

  left = digitalRead(leftBtn);
  right = digitalRead(rightBtn);
  if (left == HIGH) {
    Serial.println("Left btn pressed");
    myservo.write(0);
  } 
  else if (right == HIGH) {
    Serial.println("Right btn pressed");
    myservo.write(180);
  } 
  else {
    input = analogRead(potpin);
    output = abs(float(input) / factor);  
    myservo.write(output); 
    //myservo.write(90);
  }

  delay(30);
}




