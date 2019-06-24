# CARduino
Arduino-driven car display

### HARDWARE:

- Arduino Nano or compatible
- Bluetooth module (HC-05/HC-06 with TTL level converter)
- DHT22 temperature/humidity sensor
- RTC clock module (DS3231)
- 40x2 LCD display (HD44780 4002), optional with FC-113 TWI module for I²C interface

### WIRING:

#### Bluetooth module:

GND        -> GND
5V         -> VCC
PIN18(RX)  -> TX
PIN19(TX)  -> RX

#### Clock module:

GND        -> GND
5V         -> VCC
A4         -> SDA
A3         -> SCL

#### DHT22 sensor:

GND        -> GND
5V         -> VCC
D9         -> DATA

#### Display connected via FC-113:

5V         -> VCC
GND        -> GND
A4         -> SDA
A3         -> SCL

#### Display connected directly:

5V         -> 1
GND        -> 2

PIN12      -> 3
PIN11      -> 5

GND        -> 6 <- potentiometer GND pin / potentiometer output pin -> 4

Data pins:

PIN2       -> 14
PIN3       -> 13
PIN4       -> 12
PIN5       -> 11
