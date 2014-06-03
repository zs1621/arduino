

char incoming = NULL;
String response;
int metritis = 0;
int data_length = 0;
char areg[50] = "";

char temp = NULL;
char read_data[200];

void init_mode () {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  delay(1500);
  digitalWrite(5, LOW);
}

void restart () {
  digitalWrite(5, HIGH);
  delay(1500);
  digitalWrite(5, LOW);
}

void start_gsm () {
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
}

void onSwitchSim908 () {
  digitalWrite(onSwitchSimPin, HIGH);
}

void flushSim () {
  while(Serial1.available () > 0) {
    Serial1.read();
  }
}

void showSerial() {
  while(Serial1.available () > 0) {
    Serial.write(Serial1.read());
  }
}

void powerONGPRSModem () {
  uint32_t start_time = millis ();
  while ( Serial1.available () == 0 ) {
    if ( millis() - start_time > 1500 ) {
      Serial.println("restart SIM ...");
      restart ();
      delay(5000);
      start_gsm ();
      delay(4000);
    }
  };
  onSwitchSim908 ();
  flushSim();
}

struct Tuple {
    int string_number;
    char string_value[100];
};
  
struct Tuple read_gsm_value () {  
  char a[100] = "";
  int i = 0;
  while(Serial1.available () > 0) {
    a[i] = Serial1.read();
    i ++;
  }
  struct Tuple r;
  r.string_number = i;
  strcpy(r.string_value, a);
  return r;
}


void print_res (int num) {  
  delay(num);
  showSerial();
  flushSim();
}

void initSimModule () {  
  Serial1.println("AT");
  print_res(200);
  Serial1.println("AT+CSQ");
  print_res(500);
  Serial1.println("AT+CREG?");
  delay(500);
  Serial.println("creg:");
  
  struct Tuple creg_value;
  creg_value = read_gsm_value();
  Serial.println(creg_value.string_value);
  Serial.println(creg_value.string_number);
  char creg_status[100] = "";  
  memcpy(creg_status, creg_value.string_value, creg_value.string_number);
  int i=0;
  int creg_status_value = 0;
  char creg_res[10] = "";
  int j = 0;
  for (i=0; i < creg_value.string_number; i++) {
    if ( creg_status[i] == ':' ) {
      for (; j < 6; j++) {
        creg_res[j] = creg_status[i+j];
      }      
//      Serial.println(creg_res[4]);
      if (creg_res[4] == '1') {
        Serial.println(creg_res[4]);
        creg_status_value = 1;
      }
    }
  }
//  Serial.println(creg_status_value);
  if ( !creg_status_value ) {
    Serial.println("restart Serial1");
    restart();
    delay(4000);
    start_gsm();
    delay(2000);
    initSimModule ();
  }
}

void initGPRSMode () {
  Serial1.println("AT+SAPBR=3, 1, \"CONTYPE\", \"GPRS\"");
  print_res(200);
  Serial1.println("AT+SAPBR=1,1");
  print_res(200);
  Serial1.println("AT+SAPBR=2,1");
  print_res(200);
  Serial1.println("AT+HTTPINIT");
  print_res(200);
  Serial1.println("AT+HTTPPARA=\"CID\", 1");
  print_res(200);
}

void send_gprs ( char *url) {
//  Serial1.println("AT+HTTPPARA=\"URL\", \"http://baidu.com\"");
  Serial1.println(url);
  print_res(500);
  Serial1.println("AT+HTTPACTION=0");;
  delay(5000);
}

int check_send_success () {
  struct Tuple gprs_res;
  gprs_res = read_gsm_value();
  int i,j, send_status = 0;
  char res_value[100] = "";
  char http_code[10] = "";
  memcpy(res_value, gprs_res.string_value, gprs_res.string_number);
  for (; i < gprs_res.string_number; i ++ ) {
    if ( res_value[i] == ':' ) {
      for (; j < 10; j++) {
        http_code[j] = res_value[i+j];
      }
//      Serial.println(http_code);
//      Serial.println("ddddddd");
//      Serial.println(http_code[3]);
      if (http_code[3] == '2') {
        send_status = 1;
      }
      break; 
    }
  }
  return send_status;
}

