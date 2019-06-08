# CARduino
Arduino-driven car display

### HARDWARE:

- Arduino or compatible
- RTC clock module (DS3231)
- Bluetooth module (HC-05 or ZS-040 with TTL level converter)
- LED & 220 Ω resistor
- 40x2 LCD display (HD44780 4002; Optrex PWB 40218)

### WIRING:

#### Clock module:

PIN20(SDA) -> SDA
PIN21(SCL) -> SCL
GND        -> GND
5V         -> VCC

#### Bluetooth module:

PIN18(RX)  -> TX
PIN19(TX)  -> RX
GND        -> GND
5V         -> VCC

#### LED:

PIN22      -> resistor on LED cathode
GND        -> LED anode

#### Display:

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
