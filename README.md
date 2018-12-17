# Raion Automatic Fan Control

- PDF version : [download](https://github.com/leductan-nguyen/Automatic-Fan-Control/raw/master/dist/README.pdf)
- Arduino IDE files : [download](https://github.com/leductan-nguyen/Automatic-Fan-Control/raw/master/dist/automatic_fan_control.zip)

## Diagram
![Diagram](https://raw.githubusercontent.com/leductan-nguyen/Automatic-Fan-Control/master/docs/diagram.png)
#### 1. Arduino <---> DHT11 
There are 2 types of DHT11 sensor : 4 pins and 3 pins. Here are the infomations on the pins :
<img src="https://raw.githubusercontent.com/leductan-nguyen/Automatic-Fan-Control/master/docs/DHT11–Temperature-Sensor-Pinout.png" width="400" height="350" alt="DHT11 pinout">

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

<img src="https://github.com/leductan-nguyen/Automatic-Fan-Control/raw/master/docs/DC_power_input_jack.png" width="500" height="420" alt="input_jack">

- Power Neutral ---> Fan Neutral
- Power Line ---> Relay C
- Relay NC or NO ---> Fan Line

Depends on which behavior that you want : 

 - **always ON** 

![Always behavior](https://github.com/leductan-nguyen/Automatic-Fan-Control/raw/master/docs/always_on.PNG)

 - **always OFF**

![Always OFF behavior](https://github.com/leductan-nguyen/Automatic-Fan-Control/raw/master/docs/always_off.PNG)

## Important parameters in code
- **DHT11_PIN** : set the Arduino PIN for reading data signal from DHT sensor
- **TEMP_THRESHOLD** : define temperature at which we turn on the fan
- **relay** : define Arduino PIN for control state of the relay


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTgxNzk0NDgwNCwyNzc4MTMwMTAsLTEwMz
c2ODk2MDMsMjg4ODk2NjIxLDE1Njg2NTE2MDgsLTExNzk5OTQ0
OTEsMTgzMTYxNDQ5LDEyNjI4OTc4MzddfQ==
-->