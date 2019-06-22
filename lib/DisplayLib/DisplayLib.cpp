#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "DisplayLib.h"

/**
 * @file DisplayLib.cpp
 * @author Kana (René Lantzsch)
 * @version 1.2
 */

LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

byte block[] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
byte clock1[] = {
  0b00011,
  0b00100,
  0b01001,
  0b01001,
  0b01001,
  0b01000,
  0b00100,
  0b00011
};
byte clock2[] = {
  0b11000,
  0b00100,
  0b00010,
  0b00010,
  0b11010,
  0b00010,
  0b00100,
  0b11000
};
byte thermometer[] = {
  0b00100,
  0b01010,
  0b01010,
  0b01110,
  0b01110,
  0b11111,
  0b11111,
  0b01110
};
byte bluetooth[] = {
  0b00100,
  0b10110,
  0b01101,
  0b00110,
  0b00110,
  0b01101,
  0b10110,
  0b00100
};
byte heart[] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};
byte calendar[] = {
  0b00000,
  0b11110,
  0b11110,
  0b10010,
  0b11110,
  0b10010,
  0b11110,
  0b00000
};
byte rain[] = {
  0b01001,
  0b10010,
  0b00100,
  0b11001,
  0b11010,
  0b00100,
  0b11001,
  0b11010
};

char clearstring[SCREEN_LENGTH];


DisplayClass::DisplayClass() {}

void DisplayClass::start() const {
  lcd.begin(40, 2);

  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(LED_ON);

  lcd.createChar (0, block);
  lcd.createChar (1, clock1);
  lcd.createChar (2, clock2);
  lcd.createChar (3, thermometer);
  lcd.createChar (4, bluetooth);
  lcd.createChar (5, heart);
  lcd.createChar (6, calendar);
  lcd.createChar (7, rain);

  lcd.clear();

  lcd.backlight();
}

void DisplayClass::printText(char* text, int x, int y) const {
  lcd.setCursor ( x, y );
  lcd.print(text);
}

void DisplayClass::printSymbol(int symbol, int x, int y) const {
  lcd.setCursor ( x, y );
  switch(symbol) {
    case CLOCK:
      lcd.print (char(1));
      lcd.print (char(2));
      break;
    case THERMOMETER:
      lcd.print (char(3));
      break;
    case BLUETOOTH:
      lcd.print (char(4));
      break;
    case HEART:
      lcd.print (char(5));
      break;
    case CALENDAR:
      lcd.print (char(6));
      break;
    case RAIN:
      lcd.print (char(7));
      break;
    default:
      lcd.print (char(0));
      break;
  }
}

void DisplayClass::clear(int line = -1, char fill = ' ') const {
  if(line >= 0) {
    lcd.setCursor(0, line);
    memset (clearstring, fill, SCREEN_LENGTH);
    lcd.print(clearstring);
  } else {
    lcd.clear();
  }
}
