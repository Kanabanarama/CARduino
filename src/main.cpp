#include <Arduino.h>
#include <Wire.h>

#include "ClockLib.h"
#include "DisplayLib.h"
#include "BluetoothLib.h"

/*
 *  CARduino
 *  @file: main.cpp
 *  @author: Kana (René Lantzsch)
 *  @website: https://www.eskana.de
 */

ClockClass Clock;
DisplayClass Display;
BluetoothClass Bluetooth;

#define LED_PIN 22 // Uno: 13

void setup() {
	Serial.begin(115200);
  Serial.println("Hello");

  Clock.setTime();

  Display.start();
  Display.printText("Hallo Kana -o-", 0, 0);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

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

  if(Bluetooth.isConnected()) {
    Display.printSymbol(DisplayClass::BLUETOOTH, 0, 1);
  }

  if(Bluetooth.getValue() == '1') {
    Serial.print("@bluetooth signal on\n");
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.print("@bluetooth signal off\n");
    digitalWrite(LED_PIN, LOW);
  }

	delay(1000);
}
