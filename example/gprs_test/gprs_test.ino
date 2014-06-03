/**
*  test gprs   ���⴮��10,11����¼log
**/
#include <SoftwareSerial.h>
SoftwareSerial Serial1(10, 11);
#define baudRate 9600
#define onSwitchSimPin 2
#define ledPin 13
#define gpsGsm1 3
#define gpsGsm2 4
#define gpsGsm3 5

#include "cook_gprs.h"

void setup () {
  init_mode ();
  Serial.begin(baudRate);
  Serial1.begin(baudRate);
  Serial.println("wait switch on Serial1908");
  powerONGPRSModem();
  Serial.println("initialize GPRS");
}

void loop () {
  initSimModule ();
  Serial1.println("AT+CPIN?");
  print_res(200);
  initGPRSMode();
  char request_url[100] = "AT+HTTPPARA=\"URL\", \"http://baidu.com\"";
  send_gprs(request_url);
  int a = check_send_success ();
  if ( a ) {
    Serial.println("send successs");
  } else {
    Serial.println("send fail");
  }  
}  
