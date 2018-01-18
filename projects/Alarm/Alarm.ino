/*
 Basic alarm program, using buttons for now
 */

//int sensorPin = A0;    // select the input pin for the potentiometer
int armedLed = A0;    // select the input pin for the potentiometer
int ledPin = 13;       // select the pin for the LED
int armCounter = 0;    // how many intervals to hold to arm it
int alarmArmDisarmThreshold = 4;

int buzzer = 8;

int zone1 = 7; 
int zone2 = 6;
int zone3 = 5;
int zone4 = 4;

//int sensorValue = 0;   // variable to store the value coming from the sensor
boolean ARMED = false; // Whether or not the alarm is armed

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
  pinMode(armedLed, OUTPUT); 
  pinMode(zone1, INPUT_PULLUP);
  pinMode(zone2, INPUT_PULLUP);
  pinMode(zone3, INPUT_PULLUP);
  pinMode(zone4, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void beep_armed() {
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
}

void beep_disarmed() {
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  delay(50);
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  delay(50);
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
}

void arm_disarm() {
   if (digitalRead(zone1) == HIGH || digitalRead(zone2) == HIGH || digitalRead(zone3) == HIGH || digitalRead(zone4) == HIGH) {
     armCounter = 0;
     return;
   }
   
   if (armCounter < alarmArmDisarmThreshold) {
     armCounter++;
     return;
   }
     
   ARMED = (ARMED == true ) ? false: true;
   if (ARMED == true) {
     Serial.println("ALARM ARMED");
     beep_armed();
   } else {
     Serial.println("ALARM DISARMED");
     beep_disarmed();
   }
   armCounter = 0; 
}

void loop() {
  digitalWrite(ledPin, (ARMED == true) ? HIGH : LOW);
  digitalWrite(armedLed, (ARMED == true) ? HIGH : LOW);
  
  Serial.print("Z1:");
  Serial.print(digitalRead(zone1));
  Serial.print(", Z2:");
  Serial.print(digitalRead(zone2));
  Serial.print(", Z3:");
  Serial.print(digitalRead(zone3));
  Serial.print(", Z4:");
  Serial.println(digitalRead(zone4));
  
  arm_disarm();    
  
// read the value from the sensor:
//  sensorValue = analogRead(sensorPin);    
//  // turn the ledPin on
//  digitalWrite(ledPin, HIGH);  
//  // stop the program for <sensorValue> milliseconds:
//  delay(sensorValue);          
//  // turn the ledPin off:        
//  digitalWrite(ledPin, LOW);   
//  // stop the program for for <sensorValue> milliseconds:
//  delay(sensorValue);    
  delay(250);
}
