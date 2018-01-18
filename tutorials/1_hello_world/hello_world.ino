int val;
int ledpin=13;
void setup() {
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop() {
  
  val = Serial.read();
  
  if(val=='R') {
    digitalWrite(ledpin,HIGH);
    delay(500);
    digitalWrite(ledpin,LOW);
    delay(500);
    Serial.println("Hello World!");
  }
  
  if(val=='F') {
    for(int i = 0; i <= 5; i++) {
      digitalWrite(ledpin,HIGH);
      delay(30);
      digitalWrite(ledpin,LOW);
      delay(30);
      Serial.println("Flashin baby");
    }
  }
}
