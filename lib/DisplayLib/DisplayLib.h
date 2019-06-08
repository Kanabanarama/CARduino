#ifndef _CARDUINO_DISPLAY_LIB_
#define _CARDUINO_DISPLAY_LIB_

/**
 * @file DisplayLib.h
 * @author Kana (René Lantzsch)
 * @version 1.0
 */

#include <Arduino.h>
#include <Wire.h>

#include <LiquidCrystal.h>

class DisplayClass {

	public:

    static const int BLOCK = 0;
    static const int CLOCK = 1;
    static const int THERMOMETER = 2;

		DisplayClass();

    void DisplayClass::start() const;
		void printText(char* text, int x=0, int y=0) const;
    void printSymbol(int symbol=0, int x=0, int y=0) const;

	private:

    byte block[8] = {
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111
    };
    byte clock1[8] = {
    	0b00011,
    	0b00100,
    	0b01001,
    	0b01001,
    	0b01001,
    	0b01000,
    	0b00100,
    	0b00011
    };
    byte clock2[8] = {
    	0b11000,
    	0b00100,
    	0b00010,
    	0b00010,
    	0b11010,
    	0b00010,
    	0b00100,
    	0b11000
    };
    byte thermometer[8] = {
    	0b00100,
    	0b01010,
    	0b01010,
    	0b01110,
    	0b01110,
    	0b11111,
    	0b11111,
    	0b01110
    };

};

#endif
