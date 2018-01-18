int ledpin=11;// initialize pin 11
int inpin=7;// initialize pin 7
int val;// define val

void setup()
{
  pinMode(ledpin,OUTPUT);
  pinMode(inpin,INPUT);
  
  digitalWrite(ledpin,HIGH);
  delay(3000);
  digitalWrite(ledpin,LOW);
}

void loop()
{
  val=digitalRead(inpin);// read the level value of pin 7 and assign if to val
  if(val==LOW)// check if the button is pressed, if yes, turn on the LED
  { digitalWrite(ledpin,LOW);}
  else
  { digitalWrite(ledpin,HIGH);}
}
