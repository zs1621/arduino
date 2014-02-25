/*
标题: 通过循环语句控制pwm来达到呼吸灯效果
时间: 2014/1/13
作者: 极客工坊
 */

#define LED=11; //在 uno 布局中，只有3,5,6,9,11有PWM功能， 可以将此常量改为12试试
void setup ()
{
  pinMode(11, OUTPUT);//only  pwd output
}

void loop ()
{
  for (int a=0; a<=225; a++)
  {
    analogWrite(11, a);
    delay(8);
  }
  for (int a=225; a>=0; a--)
  {
    analogWrite(11, a);
    delay(8);
  }
  delay(800);
}
