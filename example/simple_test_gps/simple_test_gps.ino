void setup()
{
   Serial.begin(9600);
   pinInit();
   //delay(5000);
}

void pinInit()
{
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   delay(1000);
   //Serial.print("start");
   digitalWrite(5, HIGH);
   delay(1500);
   digitalWrite(5, LOW);
   //Serial.print("start2");
   digitalWrite(3,LOW);//Enable GSM mode
   digitalWrite(4,HIGH);//Disable GPS mode
  
   Serial.println("AT");
   delay(2000);
   Serial.println("AT");
   delay(2000);
   Serial.println("AT+CGPSIPR=9600");
   delay(2000);
   Serial.println("AT+CGPSPWR=1");
   delay(2000);
   Serial.println("AT+CGPSRST=1");
   delay(2000);
   digitalWrite(3,HIGH);//Disable GSM mode
   digitalWrite(4,LOW);//Enable GPS mode
}

void loop()
{
  if (Serial.available()){
          while(Serial.available()>0){
          char c = Serial.read();
          Serial.write(c);
          delay(50); 
          }    
        Serial.println();  
  }
  else 
  {
    Serial.println("not ok");
    delay(500);
  }   
}