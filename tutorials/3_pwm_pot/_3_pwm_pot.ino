int potpin = 0; 
int ledpin = 11;
int val = 0;

void setup() {
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  val = analogRead(potpin);// read the analog value from the sensor and assign it to val
  Serial.println(val);
  analogWrite(ledpin,val/4);// turn on LED and set up brightness ( maximum output of PWM is 255)
  delay(10);// wait for 0.01 second
}
