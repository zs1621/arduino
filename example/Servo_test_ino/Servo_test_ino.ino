#include <Servo.h>

Servo myservo;
int potpin = 0;
int val;
void setup ()
{
  myservo.attach(9);
  myservo.write(0);
  
}

void loop(){
  myservo.write(179);
  delay(1000);
  myservo.write(0);
  delay(5000);
//  val = analogRead(potpin);
//  val = map(val, 0, 1023, 0, 179);
//  myservo.write(val);
//  delay(15);
}
