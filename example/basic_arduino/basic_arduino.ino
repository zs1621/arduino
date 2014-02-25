/*
标题:熟悉pidMode analogRead digitalWrite等函数
时间: 2014/1/13
作者: rhapsodyzs
 */

#define SERSOR 0 //
#define LED 9 //定义D9为LED正极口，将LED灯连接到板子上D12引脚
#define VOICE 8 // voice d8
int val = 0;
void setup(){
  pinMode(LED, OUTPUT);  //定义D9为输出模式, 这里如果定义为INPUT模式，灯就很微弱的闪亮，因为定义为INPUT模式会触发上拉电阻。
  pinMode(VOICE, OUTPUT); // 定义D8为输出模式
  Serial.begin(9600); // 
  }
void loop(){
  val = analogRead(0);
  Serial.println(val * 0.488125);
  if (val * 0.488125 > 24) { //检测到lm35温度传感器温度大于24度就报警否则让LED灯闪
    digitalWrite(VOICE, HIGH);
    delay(1000);
    digitalWrite(VOICE, LOW);
    delay(1000);
  } else {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  }
//  Serial.print(val);
  delay(1000);
}
