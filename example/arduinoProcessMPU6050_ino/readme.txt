具体 教程 见[网站](http://www.cnblogs.com/wzc0066/archive/2013/03/08/2950214.html)


需要注意几点:

在运行 processing 时可能会报错
1. 端口选择有问题(最方便的是把所有串口都拔掉只留一个和arduino通信的串口， 然后代码选择serial.list[0]， 这样就不会错了)
2. 字体加载错误可能报 nullPoint 错， 字体直接放在程序同目录下的data里就好了


运行 arduino程序时  
库可以自己下载， 【http://pan.baidu.com/s/1gduYMen】
[http://pan.baidu.com/s/1eQefPB0] 加到库里