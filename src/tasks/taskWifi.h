/*          create a task for wifi connections - config and maneger           */
#ifndef WIFI_MANAGER
#define WIFI_MANAGER
// include all header files
#include "..\config\config.h"
#include "..\config\enums.h"

// include all functions files
#include "..\functions\wifiFunction.h"

/*                  Libraries: freeRTOS                                      */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

/*                  Libraries: WiFiManager                                    */
#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>
#include <HTTPClient.h>
#include <PubSubClient.h>

extern WiFiManager wifiManager;

/* task for wifimanager */
void TaskWifiManager(void *pvParameters);

void TaskWifiManager(void *parameter)
{
  while (1)
  {
    wifiManagerFunction();
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

#endif
