/**
*敏二极管控制led
* 光敏电路连接[fritzing](http://pan.baidu.com/share/link?shareid=2141310824&uk=1426543175)  这个电路图没有显示  发光二极管的电路
* 
* 光敏二极管短端接负极
* 
* 原理见链接[yuai](http://www.ic61.com/circuit/2008-4/200842410384431187.html)
*/

int photocellPin = 5;    //定义变量photocellsh=2，为电压读取端口。
int ledPin = 2;   //定义变量ledPin=12，为led电平输出端口
int val = 0;       //定义val变量的起始值
 
 
void setup() { 
  Serial.begin(9600);//设置串口波特率为9600kbps
  pinMode(ledPin, OUTPUT);  //使ledPin为输出模式
} 
 
void loop() { 
  val = analogRead(photocellPin);
  delay(1000);
  Serial.println(val);  //从传感器读取值
  if(val>900){      //想让传感器敏感一些的时候，把数值调低点，想让传感器迟钝的时候把数值调高。
    digitalWrite(ledPin, HIGH); //
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}
