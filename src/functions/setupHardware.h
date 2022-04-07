#ifndef SETUP_HARDWARE
#define SETUP_HARDWARE

#include <Arduino.h>
#include "../config/enums.h"
#include "../config/config.h"

/*                   Libraries: freeRTOS                                      */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

SysStatus_t stSysStatus =
    {
        .ucChipRev = 0,
        .uiCpuFreq = 0,
        .uiFreeHeapSize = 0,
        .ulMac = 0};

void prvSetupHardware(void); // prototype function

void prvSetupHardware(void)
{
  /*                 Initialize and enable serial communication               */
#if DEBUG == true
  Serial.begin(115200);
  delay(500);
#endif

/*                 Initialize button                                         */
#ifdef BUTTON
  pinMode(BUTTON, INPUT);
#endif

/*                    Initialize and enable the LCD                           */
#if DISPLAY_ENABLE == true
  lcd.init(); // initialize the lcd
  lcd.backlight();
#endif

/*                        Initialize and enable the BMP280                    */
#if BMP_ENABLE == true
  unsigned status;
  //status = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
  status = bmp.begin();
  if (!status)
  {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                     "try a different address!"));
    Serial.print("SensorID was: 0x");
    Serial.println(bmp.sensorID(), 16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1)
      delay(10);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

#endif

/*                        Initialize and enable the Dallas 1-wire           */
#if TEMPERATURE_ENABLE == true
  sensors.begin();
#endif

  /*                             GPIO Configuration                             */
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  /*                    Getting ESP32 system informations                     */
  stSysStatus.ucChipRev = ESP.getChipRevision();
  stSysStatus.uiCpuFreq = ESP.getCpuFreqMHz();
  stSysStatus.uiFreeHeapSize = ESP.getFreeHeap();
  stSysStatus.ulMac = ESP.getEfuseMac();

  /*                    Bootscreen for ESP32                                  */
  Serial.printf("##########################################################\n");
  Serial.printf("#  IoT Test Plataform - MQTT, influxDB, NODE-RED, grafana#\n");
  Serial.printf("*************** Samuel Centenaro de Oliveira**************\n");
  Serial.printf("**************** ESP32 + FreeRTOS + sensors **************\n");
  Serial.printf("**********************************************************\n");
  Serial.printf("----------------------------------------------------------\n");
  Serial.printf("**********************************************************\n");
  Serial.printf("*************** ESP32 SYSTEM INFORMATION *****************\n");
  Serial.printf("**********************************************************\n");
  Serial.printf("Chip revision -----------: %d", stSysStatus.ucChipRev);
  Serial.printf("CPU frequency ------ %d (MHz):", stSysStatus.uiCpuFreq);
  Serial.printf("Free Heap Size ------- %d (B):", stSysStatus.uiFreeHeapSize);
  Serial.printf("MAC address -------------:");
  //vPrintHex((uint16_t)(stSysStatus.ulMac >> 32));
  //vPrintHex(stSysStatus.ulMac);
  Serial.printf("\nWi-Fi -------------------: OK");
  Serial.printf("\nIP ----------------------: ");
  //Serial.println(WiFi.localIP());
  Serial.printf("****************************************************\n");
  Serial.printf("########################################################\n\n");
}

#endif