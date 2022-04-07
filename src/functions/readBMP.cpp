#ifndef BMP_FUNCTION
#define BMP_FUNCTION

// incluide arduino library
#include <Arduino.h>
//include bmp library
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
//include config file
#include "../config/config.h"
//include enums file
#include "../config/enums.h"

//extern bmp object
extern Adafruit_BMP280 bmp;
//extern struct for bmp sensor
extern SensorBMP_t gSensorBMP_t;
//extern struct for display values
extern DisplayValues gDisplayValues;

//prototype function for bmp sensor
void readBMP(void);

//function for bmp sensor
void readBMP(void)
{
  //read bmp sensor
  gSensorBMP_t.pressure = bmp.readPressure();
  gSensorBMP_t.temperature = bmp.readTemperature();
  gSensorBMP_t.altitude = bmp.readAltitude(1017);

  //check if sensor is working
  if (gSensorBMP_t.pressure == 0)
  {
    Serial.println("BMP sensor is not working");
  }
  else
  {
    Serial.println("Sensor BMP Values:");
    Serial.print(F("Temperature = "));
    Serial.print(gSensorBMP_t.temperature);
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(gSensorBMP_t.pressure);
    Serial.println(" Pa");

    Serial.print(F("Altitude = "));
    Serial.print(gSensorBMP_t.altitude);
    Serial.println(" m");
  }
}

#endif // BMP_FUNCTION
