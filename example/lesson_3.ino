/*
标题: 光敏电阻控制led
时间: 2014/1/14
作者: rhapsodyzs
 */


int photocellPin = 1;    //定义变量photocellsh=2，为电压读取端口。
int ledPin = 12;   //定义变量ledPin=12，为led电平输出端口
int val = 0;       //定义val变量的起始值
 
 
void setup() { 
  Serial.begin(9600);//设置串口波特率为9600kbps
  pinMode(ledPin, OUTPUT);  //使ledPin为输出模式
} 
 
void loop() { 
  val = analogRead(photocellPin);
  delay(100);
  Serial.println(val);  //从传感器读取值
  if(val>950){      //想让传感器敏感一些的时候，把数值调低点，想让传感器迟钝的时候把数值调高。
    digitalWrite(ledPin, HIGH); //
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}