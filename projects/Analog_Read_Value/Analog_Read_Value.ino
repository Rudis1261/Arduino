int potpin = 0;
int ledpin = 13;
int val = 0;

void setup()
{
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(ledpin, HIGH);
  delay(50);
  digitalWrite(ledpin, LOW);
  delay(250);
  
  val = analogRead(potpin);
  Serial.print("VAL: ");
  Serial.println(val);
}
