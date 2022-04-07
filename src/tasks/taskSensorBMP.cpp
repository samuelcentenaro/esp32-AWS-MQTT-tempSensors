//create task for sensor bmp280
// Compare this snippet from src\tasks\taskSensorBMP.h:
#ifndef SENSOR_BMP
#define SENSOR_BMP

//include all header files
#include "config\config.h"
#include "..\config\enums.h"

//include sensor bmp280 header file
#include "..\functions\readBMP.h"

//include rtos header files
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

//include external libraries
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>

//include extern files
extern Adafruit_BMP280 bmp;
extern SensorBMP_t gSensorBMP_t;
extern DisplayValues gDisplayValues;

//create task for sensor bmp280
void TaskSensorBMP(void *pvParameters);

//task for sensor bmp280
void TaskSensorBMP(void *parameter)
{
  while (1)
  {
    readBMP();
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

#endif //SENSOR_BMP