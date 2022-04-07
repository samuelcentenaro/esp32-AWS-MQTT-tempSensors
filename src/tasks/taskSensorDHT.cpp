#ifndef SENSOR_DHT
#define SENSOR_DHT

#include "config\config.h"
#include "..\config\enums.h"

#include "..\functions\readDHT.h"

/*                   Libraries: freeRTOS                                      */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

#include "dht.h"

extern DHT dht;
extern SensorDHT22_t gSensorDHT22_t;

void TaskSensorDHT(void *pvParameters);

void TaskSensorDHT(void *parameter)
{
  dht.begin();
  while (1)
  {
    readDHT();
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

#endif