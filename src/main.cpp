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

char welcomeMessage[] = "Hallo Kana -o-";
char bluetoothMessage[] = "Submit something to change the LCD text.\n";

#define LED_PIN 13

void setup() {
	Serial.begin(9600); //115200
  Serial.println("Starting...");

  Clock.setTime();

  Display.start();
  Display.printText(welcomeMessage, 0, 0); // Testamendvordrucke im Handschuhfach.

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Bluetooth.sendValue(bluetoothMessage);
}

int padLeft = 0;
int textLen = 0;
int temperature;
unsigned long currentMillis;
char btData[42];
char temperatureStr[2];
char* runningTime = malloc(sizeof(char)*4);

void loop() {
  // display bluetooth messages
  strcpy(btData, Bluetooth.getValue());
  if(btData[0] != '\0') {
    Display.clear(0);
    textLen = strlen(btData);
    if(textLen < 40) {
      padLeft = (40 - textLen) / 2;
      //if(padLeft % 2) padLeft--;
    }
    Display.printText(btData, padLeft, 0);
  }

  // display bluetooth status
  Display.printSymbol(DisplayClass::BLUETOOTH, 0, 1);

  if(Bluetooth.isConnected()) {
    Display.printText("on ", 1, 1);
    digitalWrite(LED_PIN, HIGH);
  } else {
    Display.printText("off", 1, 1);
    digitalWrite(LED_PIN, LOW);
  }

  // display temperature
  Display.printSymbol(DisplayClass::THERMOMETER, 6, 1);

  temperature = (int)round(Clock.getTemperature());
  itoa(temperature, temperatureStr, 10);
  //sprintf(temperatureStr, "%i", temperature);
  Display.printText(temperatureStr, 7, 1);
  Display.printText("\xDF", 9, 1);
  Display.printText("C ", 10, 1);

  // display duration
  Display.printSymbol(DisplayClass::HEART, 12, 1);

  currentMillis = millis()/1000;
  sprintf(runningTime, "%04lu", currentMillis);
  Display.printText(runningTime, 13, 1);

  // display date
  Display.printSymbol(DisplayClass::CALENDAR, 18, 1);

  Display.printText(Clock.getLocalDate(ClockClass::LOCALE_DE), 19, 1);

  // display time
  Display.printSymbol(DisplayClass::CLOCK, 30, 1);

  Display.printText(Clock.getFormattedTime(), 32, 1);

	delay(1000);
}
