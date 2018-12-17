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
 - VCC ---> Arduino 5V
 - GND ---> Arduino GND
 - S (Signal) ---> Arduino PIN 3
#### 4. Power <----> Fan <---> Relay
Detail abour power input jack :
![enter image description here](https://github.com/leductan-nguyen/Automatic-Fan-Control/raw/master/docs/DC_power_input_jack.jpg =100x)
- Power Neutral ---> Fan Neutral
- Power Line ---> Relay C
- Relay NC or NO ---> Fan Line

Depends on which behavior that you want : 

 - **always ON** 
![enter image description here](https://github.com/leductan-nguyen/Automatic-Fan-Control/raw/master/docs/always_on.PNG)

 - **always OFF**
![enter image description here](https://github.com/leductan-nguyen/Automatic-Fan-Control/raw/master/docs/always_off.PNG)


<!--stackedit_data:
eyJoaXN0b3J5IjpbMTI2ODQ3ODc2MiwxNTY4NjUxNjA4LC0xMT
c5OTk0NDkxLDE4MzE2MTQ0OSwxMjYyODk3ODM3XX0=
-->