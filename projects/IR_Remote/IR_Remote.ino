#include <IRremote.h>

int RECV_PIN = 11;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
long power = 0x00FFA25D;
long on1 = 0x00FF30CF;
long on2 = 0x00FF18E7;
long on3 = 0x00FF7A85;
long on4 = 0x00FF10EF;
long on5 = 0x00FF38C7;
long on6 = 0x00FF5AA5;
long strobe = 0x00FFC23D;

IRrecv irrecv(RECV_PIN);
decode_results results;

void dump(decode_results *results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN)
  {
    Serial.println("Could not decode message");
  }
  else
  {
    if (results->decode_type == NEC)
    {
      Serial.print("Decoded NEC: ");
    }
    else if (results->decode_type == SONY)
    {
      Serial.print("Decoded SONY: ");
    }
    else if (results->decode_type == RC5)
    {
      Serial.print("Decoded RC5: ");
    }
    else if (results->decode_type == RC6)
    {
      Serial.print("Decoded RC6: ");
    }
    Serial.print(results->value, HEX);
    Serial.print(" (");
    Serial.print(results->bits, DEC);
    Serial.println(" bits)");
  }
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");
  for (int i = 0; i < count; i++)
  {
    if ((i % 2) == 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    }
    else
    {
      Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println("");
}

void setup()
{
  pinMode(RECV_PIN, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

int on = 0;
unsigned long last = millis();

void loop()
{
  if (irrecv.decode(&results))
  {
    // If it's been at least 1/4 second since the last
    // IR recved, toggle the relay
    if (millis() - last > 250)
    {
      on = !on;
      //
      digitalWrite(8, on ? HIGH : LOW);
      digitalWrite(13, on ? HIGH : LOW);
      dump(&results);
    }
    if (results.value == power ){
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
    }  
    if (results.value == strobe ){
      for(int i = 0; i <= 3; i++) {
    digitalWrite(LED1, LOW);
    delay(200);
    digitalWrite(LED2, LOW);
    delay(200);
    digitalWrite(LED3, LOW);
    delay(200);
    digitalWrite(LED4, LOW);
    delay(200);
    digitalWrite(LED5, LOW);
    delay(200);
    digitalWrite(LED6, LOW);
    delay(200);
    digitalWrite(LED1, HIGH);
    delay(200);
    digitalWrite(LED2, HIGH);
    delay(200);
    digitalWrite(LED3, HIGH);
    delay(200);
    digitalWrite(LED4, HIGH);
    delay(200);
    digitalWrite(LED5, HIGH);
    delay(200);
    digitalWrite(LED6, HIGH);
    delay(200);
  }
    }  
    if (results.value == on1 )
      digitalWrite(LED1, HIGH);
    if (results.value == on2 )
      digitalWrite(LED2, HIGH);
    if (results.value == on3 )
      digitalWrite(LED3, HIGH);
    if (results.value == on4 )
      digitalWrite(LED4, HIGH);
    if (results.value == on5 )
      digitalWrite(LED5, HIGH);
    if (results.value == on6 )
      digitalWrite(LED6, HIGH);
    last = millis();
    irrecv.resume(); // Receive the next value
  }
}
