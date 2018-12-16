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

> !!! Be careful pins positions are not the same 

`

<!--stackedit_data:
eyJoaXN0b3J5IjpbMTUyMTU1NTA2MiwxMjYyODk3ODM3XX0=
-->