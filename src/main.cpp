#include <Arduino.h>
#include <Wire.h>

#include "ClockLib.h"
#include "DisplayLib.h"

/*
 *  CARduino
 *  @file: main.cpp
 *  @author: Kana (René Lantzsch)
 *  @website: https://www.eskana.de
 */

ClockClass Clock;
DisplayClass Display;

void setup() {
	Serial.begin(115200);
  Serial.println("Hello");

  Clock.setTime();

  Display.start();
  Display.printText("Hallo Kana -o-", 0, 0);

  Serial.println("Bye");
}

void loop() {
  // display time
  Display.printSymbol(DisplayClass::CLOCK, 29, 0);
  Display.printText(Clock.getFormattedTime(), 32, 0);

  // display temperature
  Display.printSymbol(DisplayClass::THERMOMETER, 34, 1);
  int temperature = (int)round(Clock.getTemperature());
  char tstr[2];
  itoa(temperature, tstr, 10);
  Display.printText(tstr, 36, 1);
  Display.printText("\xDF", 38, 1);
  Display.printText("C", 39, 1);

	delay(1000);
}
