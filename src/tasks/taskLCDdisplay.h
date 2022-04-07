#ifndef TASK_LCD
#define TASK_LCD

#include "..\config\config.h"

/*                   Libraries: freeRTOS                                      */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;
extern DisplayValues gDisplayValues;

void TaskDisplay(void *pvParameters)
{
  while (1)
  {
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Sensor DHT22:");
    lcd.setCursor(0, 1);
    char str[16];
    sprintf(str, "T%.1f-U%.0f-HI%.1f", gDisplayValues.sDHT22_t, gDisplayValues.sDHT22_h, gDisplayValues.sDHT22_HI);
    lcd.print(str);

    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

#endif