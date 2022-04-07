/*******************************************************************************
 * Project: Application for MQTT+NODE-RED+INFLUXDB+GRAFANA test
 * Features: ESP32, DHT22, BMP280, Dallas , LCD Display I2C
 * AWS E2C Linux Ubunto -> MQTT Mosquitto + node-red + influxdb + grafana
 * uC: ESP32-WROOM-32D
 * FreeRTOS
 * IDE: PlatformIO + VSCode 
 * Framework: Arduino
 * Author: Samuel Centenaro de Oliveira
 * Data: 05/03/2022
 ******************************************************************************/

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

/*                        FreeRTOS definition                                 */
xTaskHandle task01; // taskhandle for task01
xTaskHandle task02; // taskhandle for task02
xTaskHandle task03; // taskhandle for task03
xTaskHandle task04; // taskhandle for task04
xTaskHandle task05; // taskhandle for task05

SensorDHT22_t gSensorDHT22_t;      // struct for DHT22
SensorBMP_t gSensorBMP_t;          // struct for BMP280
SensorDS18B20_t gSensorDSs18B20_t; // struct for DS18B20
DisplayValues gDisplayValues;      // struct for LCD display

/*                    Task prototypes                                         */
void TaskDisplay(void *pvParameters);
void TaskSensorDHT(void *pvParameters);
void TaskSensorBMP(void *pvParameters);
void TaskSensorDallas(void *pvParameters);
void TaskWifiManager(void *pvParameters);

//drivers for sensors
LiquidCrystal_I2C lcd(0x27, 16, 2); // driver for LCD

DHT dht(DHTPIN, DHTTYPE); // driver for DHT22

Adafruit_BMP280 bmp;                                     // driver for BMP280
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();  // bmp temperature sensor simple
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor(); // bmp pressure sensor simple

OneWire oneWire(ONE_WIRE_BUS);       //driver for DS18B20
DallasTemperature sensors(&oneWire); //Pass our oneWire reference to Dallas Temperature.

WiFiManager wifiManager; //object to wifi manager

void setup()
{
    // Setup hardware functions
    prvSetupHardware();

    // callback to AP mode config
    wifiManager.setAPCallback(configModeCallback);
    // callback to work in station mode
    wifiManager.setSaveConfigCallback(saveConfigCallback);

    // task for display LCD
    xTaskCreatePinnedToCore(
        TaskDisplay,
        "TaskDisplay",
        4096,
        NULL,
        1,
        &task01, 1);

    // task for sensor DHT22
    xTaskCreatePinnedToCore(
        TaskSensorDHT,
        "TaskSensorDHT",
        10000,
        NULL,
        2,
        &task02, 1);

    //task for sensor BMP280
    xTaskCreatePinnedToCore(
        TaskSensorBMP,
        "TaskSensorBMP280",
        10000,
        NULL,
        3,
        &task03, 1);

    //task for sensor Dallas
    xTaskCreatePinnedToCore(
        TaskSensorDallas,
        "TaskSensorDallas",
        10000,
        NULL,
        4,
        &task04, 1);

    //task for wifi
    xTaskCreatePinnedToCore(
        TaskWifiManager,
        "TaskWifiManager",
        10000,
        NULL,
        10,
        &task05, 1);
}

void loop()
{
    vTaskDelay(10 / portTICK_PERIOD_MS); // delay 10 ms
}