# Asmodeus
Arduino robot car with a powerbank and a flamethrower.

## Dependencies and libraries
Implements [wire] to establish communication between two boards.  
Uses [ESP8266] to recieve and send data over Wi-Fi.  
App for controling is made with [Blynk].  

**Master:** Recieves data from `Slave` and controls the motors:
- 4 motors for driving
- 1 servo motor for grabbing hook
- 2 servos for flamethrower

**Slave:** Uses ESP8266 and Blynk to send information to `Master`

[wire]: https://github.com/arduino/ArduinoCore-avr/tree/master/libraries/Wire
[ESP8266]: https://github.com/esp8266/Arduino
[Blynk]: https://blynk.io/
