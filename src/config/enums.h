/* general definitios*/

#ifndef ENUMS
#define ENUMS

#include <Arduino.h>

/* struct for DHT22 sensor*/
typedef struct
{
  float temperature;
  float humidity;
  float heatIndex;
} SensorDHT22_t;

/* struct for BMP sensor*/
typedef struct
{
  float pressure;
  float temperature;
  float altitude;
  float sealevel;
  float humidity;
  float heatIndex;
} SensorBMP_t;

/* struct for Dallas sensor*/
typedef struct
{
  float temperature;
} SensorDS18B20_t;

/* struct for show display values */
struct DisplayValues
{
  float sDHT22_t;
  float sDHT22_h;
  float sDHT22_HI;
  float sBMP_t;
  float sBMP_p;
  float sBMP_h;
  float sBMP_HI;
  float sDS18B20_t;
};

/* struct for MQTT message*/
struct MQTT_reports
{
  float sDHT22_topic_temperature;
  float sDHT22_topic_humidity;
  float sDHT22_topic_heatIndex;
};

typedef struct
{
  uint8_t ucChipRev;      //ESP32 chip revision
  uint8_t uiCpuFreq;      //CPU frequency value
  uint8_t uiFreeHeapSize; //Free heap memory uiFreeHeapSize
  uint8_t ulMac;          //MAC adrees of ESP32
} SysStatus_t;

#endif
