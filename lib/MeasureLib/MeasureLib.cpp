#include <Arduino.h>
#include <Wire.h>
#include <SparkFunBME280.h>

#include "MeasureLib.h"

/**
 * @file MeasureLib.cpp
 * @author Kana (René Lantzsch)
 * @version 1.1
 */

float sensor_temperature, sensor_humidity, sensor_pressure, sensor_altitude;

BME280 bme;

MeasureClass::MeasureClass() {
  Wire.begin();
	bme.setI2CAddress(0x76);
}

void MeasureClass::start() const {
	while(!bme.beginI2C())
	{
		Serial.println("Could not find BME280 sensor.");
		delay(1000);
	}
}

float MeasureClass::getTemperature() const {
	//sensor_temperature = mySensor.readTempF();
	sensor_temperature = bme.readTempC();

	return sensor_temperature;
}

float MeasureClass::getHumidity() const {
	sensor_humidity = bme.readFloatHumidity();

	return sensor_humidity;
}

float MeasureClass::getPressure() const {
	sensor_pressure = bme.readFloatPressure();

	return sensor_pressure;
}

float MeasureClass::getAltitude() const {
	//sensor_altitude = bme.readFloatAltitudeFeet();
	sensor_altitude = bme.readFloatAltitudeMeters();

	return sensor_altitude;
}
