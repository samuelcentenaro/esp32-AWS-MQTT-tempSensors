/* Create function to Wifi manager and add functions to it */
#ifndef WIFI_FUNCTION_H
#define WIFI_FUNCTION_H

/*                   Include files for configuration                          */
#include "../config/config.h"
#include "../config/enums.h"

/*                   Include all necessary libraries                          */
#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>
#include <HTTPClient.h>
#include <PubSubClient.h>

// extern object to wifiManager
extern WiFiManager wifiManager;

// create prototype for function callback AP mode
void callbackAPmode(WiFiManager *myWiFiManager);
// create prototype for function callback STA mode
void callbackSTAmode(WiFiManager *myWiFiManager);
//create prototype for wifiManager function
void wifiManagerFunction(void);

//callback que indica que o ESP entrou no modo AP
void configModeCallback(WiFiManager *myWiFiManager)
{
  Serial.println("Entrou no modo de configuração");
  Serial.println(WiFi.softAPIP());                      //imprime o IP do AP
  Serial.println(myWiFiManager->getConfigPortalSSID()); //imprime o SSID criado da rede
}

//Callback que indica que salvamos uma nova rede para se conectar (modo estação)
void saveConfigCallback()
{
  Serial.println("Configuração salva");
}

void wifiManagerFunction()
{
  // test if button is pressed
  if (digitalRead(BUTTON) == HIGH)
  {
    Serial.println("Open WIFI Manager website in any device");
    // blink led to indicate that wifi manager is open  in any device
    for (int i = 0; i < 5; i++)
    {
      digitalWrite(LED, HIGH);
      delay(300);
      digitalWrite(LED, LOW);
      delay(100);
    }

    //clear network saved
    wifiManager.resetSettings();
    if (!wifiManager.startConfigPortal("ESP32-CONFIG", "12345678"))
    {
      Serial.println("Not connected to wifi");
      ESP.restart();
    }
    else
    {
      Serial.println("Connected to wifi");
      ESP.restart();
    }
  }
  //test if wifi is connected and blink led, if not, wifi auto connect and blink led 5 times
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Connected to wifi");
    for (int i = 0; i < 2; i++)
    {
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
    }
  }
  else
  {
    //blink led 5 times
    for (int i = 0; i < 5; i++)
    {
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
    }
    //auto connect to wifi
    Serial.println("Auto connect to wifi");
    wifiManager.autoConnect();
  }
}

#endif // WIFI_FUNCTION_H
