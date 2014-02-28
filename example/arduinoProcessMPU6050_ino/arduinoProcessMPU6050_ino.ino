/**
* 电路连接: bluno v1.5 ;mpu6050/GY-521 [芯片具体见网站](http://item.taobao.com/item.htm?spm=a230r.1.0.0.9Qtw2q&id=21390500926）
*  Vcc <-> 3.3v ,gnd <-> gnd, scl <-> 模拟口A5, sda <-> 模拟口A4
*/

#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
  
MPU6050 accelgyro;
  
int16_t ax, ay, az;
int16_t gx, gy, gz;
  
char str[512];
  
void setup() {
    Wire.begin();
    Serial.begin(9600);
    accelgyro.initialize();
}
  
void loop() {
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    sprintf(str, "%d,%d,%d,%d,%d,%d,%d", ax, ay, az, gx, gy, gz);  
    Serial.print(str);
    Serial.write(byte(10));
    delay(20);
}
