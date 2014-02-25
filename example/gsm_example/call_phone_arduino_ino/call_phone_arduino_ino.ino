// Product name: GPS/GPRS/GSM Module V3.0
// # Product SKU : TEL0051
// # Version     : 0.1
 
// # Description:
// # The sketch for driving the gsm mode via the Arduino board
 
// # Steps:
// #        1. Turn the S1 switch to the Prog(right side)
// #        2. Turn the S2 switch to the Arduino side(left side)
// #        3. Take off the GSM/GPS jumper caps from the Uart select
// #        4. Upload the sketch to the Arduino board
// #        5. Turn the S1 switch to the comm(left side) 
// #        6. Plug the jumper caps back to GSM side
// #        7. RST the board 
 
// #        wiki link- http://www.dfrobot.com/wiki/index.php/GPS/GPRS/GSM_Module_V3.0_(SKU:TEL0051)
 
byte gsmDriverPin[3] = {
  3,4,5};//The default digital driver pins for the GSM and GPS mode
//If you want to change the digital driver pins
//or you have a conflict with D3~D5 on Arduino board,
//you can remove the J10~J12 jumpers to reconnect other driver pins for the module!
 
void setup()
{    
 //Init the driver pins for GSM function
  for(int i = 0 ; i < 3; i++){
    pinMode(gsmDriverPin[i],OUTPUT);
  }
  digitalWrite(5,HIGH);//Output GSM Timing 
  delay(1500);
  digitalWrite(5,LOW);  
  digitalWrite(3,LOW);//Enable the GSM mode
  digitalWrite(4,HIGH);//Disable the GPS mode
  delay(2000);
  Serial.begin(9600); //set the baud rate
  delay(5000);//call ready
  delay(5000);
  delay(5000);
}
  
void loop()
{  
   Serial.println("AT");//Send AT command     
   delay(2000);
   Serial.println("AT");   
   delay(2000);
  //Make a phone call
   Serial.println("ATD18621793072;");//Change the receiver phone number 
  delay(2000); 
   while(1);
}
