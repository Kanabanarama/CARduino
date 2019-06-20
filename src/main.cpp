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

#define LED_PIN 13

void setup() {
	Serial.begin(9600); //115200
  Serial.println("Starting...");

  Clock.setTime();

  Display.start();
  Display.printText("Hallo Kana -o-", 0, 0);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
}

char *runningTime = malloc(sizeof(char)*4);
unsigned long currentMillis;
char tstr[2];
int temperature;

void loop() {
  // display bluetooth status
  Display.printSymbol(DisplayClass::BLUETOOTH, 0, 1);

  if(Bluetooth.isConnected()) {
    Display.printText("on ", 1, 1);
  } else {
    Display.printText("off", 1, 1);
  }

  // display temperature
  Display.printSymbol(DisplayClass::THERMOMETER, 5, 1);

  temperature = (int)round(Clock.getTemperature());
  itoa(temperature, tstr, 10);
  Display.printText(tstr, 6, 1);
  Display.printText("\xDF", 8, 1);
  Display.printText("C", 9, 1);

  // display duration
  Display.printSymbol(DisplayClass::HEART, 11, 1);

  currentMillis = millis()/1000;
  sprintf(runningTime, "%05d", currentMillis);
  Display.printText(runningTime, 12, 1);

  // display date
  Display.printSymbol(DisplayClass::CALENDAR, 18, 1);

  Display.printText("20.05.2019", 19, 1);

  // display time
  Display.printSymbol(DisplayClass::CLOCK, 30, 1);

  Display.printText(Clock.getFormattedTime(), 32, 1);

  // test bluetooth
  if(Bluetooth.getValue() == '1') {
    Serial.print("@bluetooth signal on\n");
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.print("@bluetooth signal off\n");
    digitalWrite(LED_PIN, LOW);
  }

	delay(1000);
}
