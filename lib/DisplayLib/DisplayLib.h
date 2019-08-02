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
    static const int BLUETOOTH = 3;
		static const int HEART = 4;
		static const int CALENDAR = 5;
		static const int RAIN = 6;
		static const int ARROW = 7;

		DisplayClass();

    void start() const;
		void printText(char* text, int x=0, int y=0) const;
    void printSymbol(int symbol=0, int x=0, int y=0) const;
	  void clear(int line = -1, char fill = ' ') const;

	private:

		#define I2C_ADDR    0x27

		#define BACKLIGHT_PIN  3
		#define LED_OFF 1
		#define LED_ON  0

		#define En_pin  2
		#define Rw_pin  1
		#define Rs_pin  0
		#define D4_pin  4
		#define D5_pin  5
		#define D6_pin  6
		#define D7_pin  7

		#define SCREEN_LENGTH 40

};

#endif
