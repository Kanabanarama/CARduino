#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#include "DisplayLib.h"

/**
 * @file DisplayLib.cpp
 * @author Kana (René Lantzsch)
 * @version 1.0
 */

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DisplayClass::DisplayClass() {
  lcd.createChar (0, block);
  lcd.createChar (1, clock1);
  lcd.createChar (2, clock2);
  lcd.createChar (3, thermometer);
}

void DisplayClass::start() const {
  lcd.begin(40, 2);
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
    default:
      lcd.print (char(0));
      break;
  }
}
