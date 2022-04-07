// function to read the temperature from the DS18B20
#ifndef DS18B20_FUNCTION
#define DS18B20_FUNCTION
// include arduino library
#include <Arduino.h>

// include ds18b20 and dallas library for temperature sensor
#include <OneWire.h>
#include <DallasTemperature.h>

// include config file
#include "../config/config.h"

// include enums file
#include "../config/enums.h"

// extern ds18b20 object
extern OneWire oneWire;
extern DallasTemperature sensors; // ds18b20 object

// extern struct for ds18b20 sensor
extern SensorDS18B20_t gSensorDSs18B20_t;

// extern struct for display values
extern DisplayValues gDisplayValues;

// prototype function for ds18b20 sensor
void readDS18B20(void);

// function for ds18b20 sensor

void readDS18B20(void)
{
  // read ds18b20 sensor
  sensors.requestTemperatures();
  gSensorDSs18B20_t.temperature = sensors.getTempCByIndex(0);
  // gDisplayValues =
  //     {.sDS18B20_t = gSensorDSs18B20_t.temperature};

  // check if sensor is working
  if (gSensorDSs18B20_t.temperature == 0)
  {
    Serial.println("DS18B20 sensor is not working");
  }
  else
  {
    Serial.println("Sensor DS18B20 Values:");
    Serial.print(F("Temperature = "));
    Serial.print(gSensorDSs18B20_t.temperature);
    Serial.println(" *C");
  }
}
#endif // DS18B20_FUNCTION
