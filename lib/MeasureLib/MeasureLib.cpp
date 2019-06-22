#include <Arduino.h>
#include <Wire.h>
#include <dht.h>

#include "MeasureLib.h"

/**
 * @file MeasureLib.cpp
 * @author Kana (René Lantzsch)
 * @version 1.0
 */

#define DHT22_PIN 9

dht DHT;

MeasureClass::MeasureClass() {}

float MeasureClass::getTemperature() const {
	DHT.read22(DHT22_PIN);

  return DHT.temperature;
}

float MeasureClass::getHumidity() const {
	DHT.read22(DHT22_PIN);

  return DHT.humidity;
}
