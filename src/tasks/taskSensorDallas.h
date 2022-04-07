/* task for dallas sensor */
#ifndef TASK_SENSOR_DALLAS
#define TASK_SENSOR_DALLAS

// include config e enum files
#include "config\config.h"
#include "..\config\enums.h"

// include functions files
#include "..\functions\read18B20.h"

/*                   Libraries: freeRTOS                                      */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

/*                   Libraries: dallas                                        */
#include <OneWire.h>
#include <DallasTemperature.h>

// include sensor dallas objects

extern DallasTemperature sensors;

/* task for dallas sensor */
void TaskSensorDallas(void *pvParameters)
{
  while (1)
  {
    readDS18B20();                         // read dallas sensor
    vTaskDelay(2000 / portTICK_PERIOD_MS); // delay 2 seconds
  }
}

#endif