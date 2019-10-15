#include <Arduino.h>
#include <Wire.h>

#include "ClockLib.h"
#include "MeasureLib.h"
#include "DisplayLib.h"
#include "BluetoothLib.h"
#include "CanbusLib.h"

/*
 *  CARduino
 *  @file: main.cpp
 *  @author: Kana (René Lantzsch)
 *  @website: https://www.eskana.de
 */

ClockClass Clock;
MeasureClass Measuring;
DisplayClass Display;
BluetoothClass Bluetooth;
CanbusClass Canbus;

char welcomeMessage[] = "*----------- Hallo Kana -o- -----------*"; //
char bluetoothMessage[] = "Submit something to change the LCD text.\n";

void setup() {
	Serial.begin(9600);

  Clock.setTime();
	Measuring.start();
  Display.start();
  Display.printText(welcomeMessage, 0, 0);

	Bluetooth.start();
	Bluetooth.sendValue(bluetoothMessage);

	Canbus.start(Bluetooth);
}

int padLeft = 0;
int textLen = 0;
float temperature;
float humidity;
float altitude;
unsigned long currentMillis;
char btData[42];
char temperatureStr[2];
char humidityStr[2];
char altitudeStr[4];
char* runningTime = malloc(sizeof(char)*4);

void loop() {
	// read can data and send it over bluetooth
	Canbus.receiveMessage(Bluetooth);

  // display bluetooth messages
  strcpy(btData, Bluetooth.getValue());
  if(btData[0] != '\0') {
    Display.clear(0);
    textLen = strlen(btData);
    if(textLen < 40) {
      padLeft = (40 - textLen) / 2;
    }
    Display.printText(btData, padLeft, 0);
  }

  // display bluetooth status
  /*if(Bluetooth.isConnected()) {
		Display.printSymbol(DisplayClass::BLUETOOTH, 0, 1);
		Display.printText("  ", 1, 1);
  } else {
		//Display.printText("off", 1, 1);
  }*/

	// display altitude
	Display.printSymbol(DisplayClass::ARROW, 0, 1);

	altitude = Measuring.getAltitude();
	itoa((int)round(altitude), altitudeStr, 10);
	Display.printText("m", 4, 1);
	Display.printText(altitudeStr, 1, 1);

  // display temperature
  Display.printSymbol(DisplayClass::THERMOMETER, 6, 1);

	temperature = Measuring.getTemperature();
	itoa((int)round(temperature), temperatureStr, 10);
	Display.printText(temperatureStr, 7, 1);
	Display.printText("\xDF", 9, 1);
  Display.printText("C ", 10, 1);

	// display humidity
  Display.printSymbol(DisplayClass::RAIN, 12, 1);

	humidity = Measuring.getHumidity();
	itoa((int)round(humidity), humidityStr, 10);
	Display.printText(humidityStr, 13, 1);
	Display.printText("%", 15, 1);

  // display duration
  Display.printSymbol(DisplayClass::HEART, 17, 1);

  currentMillis = millis()/1000;
	if(currentMillis > 9999) currentMillis = 0;
  sprintf(runningTime, "%04lu", currentMillis);
  Display.printText(runningTime, 18, 1);

  // display date
  Display.printSymbol(DisplayClass::CALENDAR, 23, 1);

  Display.printText(Clock.getLocalDate(ClockClass::LOCALE_SHORT_DE), 24, 1);

  // display time
  Display.printSymbol(DisplayClass::CLOCK, 30, 1);

  Display.printText(Clock.getFormattedTime(), 32, 1);

	delay(1000);
}
