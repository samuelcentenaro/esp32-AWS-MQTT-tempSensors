// include main.h file
#ifndef _MAIN_H_
#define _MAIN_H_

/*                   Libraries: basics                                        */
#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*                   Libraries: freeRTOS                                      */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

/*                   Libraries: features                                      */
#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>
#include <HTTPClient.h>
#include <PubSubClient.h>
#include "DHT.h"
#include "OneWire.h"
#include "DallasTemperature.h"
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>

/*                Include files for configuration                             */
#include "config/config.h"
#include "config/enums.h"

/*                Include files for task                                      */
#include "tasks/taskLCDdisplay.h"
#include "tasks/taskSensorDHT.h"
#include "tasks/taskSensorBMP.h"
#include "tasks/taskSensorDallas.h"
#include "tasks/taskWifi.h"

/*                Include files for functions                                 */
#include "functions/setupHardware.h" // Setup hardware
#include "functions/readBMP.h"       // Read BMP280
#include "functions/readDHT.h"       // Read DHT22
#include "functions/read18B20.h"     // Read DS18B20
#include "functions/wifiFunction.h"  // Wifi function

#endif //_MAIN_H_
