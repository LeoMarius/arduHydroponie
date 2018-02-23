# makers'pot

### Software
Code is split between [feather huzzah with ESP8266](https://learn.adafruit.com/adafruit-io-basics-esp8266-arduino?view=all) and [trinket pro 5v](https://learn.adafruit.com/introducing-pro-trinket?view=all) boards.  
[SimpleTimer](https://playground.arduino.cc/Code/SimpleTimer#Download) library is required.  
Feather Huzzah's internet and adafruit.io connections have to be configured in `code_feather/config.h`.

### Circuit
![](montage.png)

An L7805CV is used as voltage regulator for powering the Feather Huzzah.
![](https://img4.hostingpics.net/pics/157328regulateur5v.png)
