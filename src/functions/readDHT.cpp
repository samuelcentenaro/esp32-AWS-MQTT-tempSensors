#ifndef DHT22_FUNCTION
#define DHT22_FUNCTION

#include <Arduino.h>
#include "dht.h"

/*                   Include files for configuration                          */
#include "../config/config.h"
#include "../config/enums.h"

extern DHT dht;
extern SensorDHT22_t gSensorDHT22_t;
extern DisplayValues gDisplayValues;
void readDHT(void);

void readDHT()
{

  float h = dht.readHumidity();    // Read temperature as Celsius (the default)
  float t = dht.readTemperature(); // Read temperature as Fahrenheit (isFahrenheit = true)

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  else
  {
    gSensorDHT22_t.temperature = t;
    gSensorDHT22_t.humidity = h;
    gSensorDHT22_t.heatIndex = dht.computeHeatIndex(gSensorDHT22_t.temperature, gSensorDHT22_t.humidity, false);
    gDisplayValues =
        {.sDHT22_t = gSensorDHT22_t.temperature,
         .sDHT22_h = gSensorDHT22_t.humidity,
         .sDHT22_HI = gSensorDHT22_t.heatIndex};

    Serial.println(F("DHT 22 Values"));
    Serial.print(F("Temperature = "));
    Serial.print(gSensorDHT22_t.temperature);
    Serial.println(" *C");

    Serial.print(F("Humidity = "));
    Serial.print(gSensorDHT22_t.humidity);
    Serial.println(" %");

    Serial.print(F("Heat Index = "));
    Serial.print(gSensorDHT22_t.heatIndex);
    Serial.println(" *C");
  }
}

#endif // DHT22