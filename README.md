# Raion Automatic Fan Control
## Diagram
![Diagram](https://raw.githubusercontent.com/leductan-nguyen/Automatic-Fan-Control/master/docs/diagram.png)
#### 1. Arduino <---> DHT11 
There are 2 types of DHT11 sensor : 4 pins and 3 pins. Here are the infomations on the pins :
![DHT11 pinout](https://raw.githubusercontent.com/leductan-nguyen/Automatic-Fan-Control/master/docs/DHT11–Temperature-Sensor-Pinout.jpg)
- VCC(1) ---> Arduino 5V
- DATA (2) ---> Arduino PIN 2
- GND (4) ---> Arduino GND
#### 2. Arduino <---> OLED
- VCC ---> Arduino 5V
- GND ---> Arduino GND
- SCL ---> Arduino A5
- SDA ---> Arduino A4

**!!! Be careful OLED pins positions are not the same on different versions**
#### 3. Arduino <---> Relay
- VCC ---> Arduino VCC
- GND ---> Arduino GND
- S (Signal) ---> Arduino PIN 3
#### 4. Fan <---> Relay


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE2MjMxMDU3MjksMTI2Mjg5NzgzN119
-->