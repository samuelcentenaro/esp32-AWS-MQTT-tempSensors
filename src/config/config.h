/*----------------------------General config----------------------------------*/
#ifndef CONFIG
#define CONFIG

/*WiFi Config*/
const char *ssid = "CLARO_2G5EE5ED"; //wifi ssid
const char *password = "125EE5ED";   //wifi password

/* MQTT */
const char *mqtt_broker = "IP";       // IP address of your MQTT broker
#define REPORT_MQTT_SEPARATE true     // Report each value to its own topic
#define REPORT_MQTT_JSON true         // Report all values in a JSON message
const char *status_topic = "events";  // MQTT topic to report startup
#define mqtt_user "mqtt_username"     // username
#define mqtt_password "mqtt_password" // password

/* Use WiFi. If this is off, MQTT won't run */
#define ENABLE_WIFI true

/* Serial */
#define SERIAL_BAUD_RATE 115200 // Speed for USB serial console

/* Debug */
#define DEBUG true

/* Display Enable */
#define DISPLAY_ENABLE true

/* DHT 22*/
#define DHTTYPE DHT22
#define DHTPIN 26

/* BMP 280 enable */
#define BMP_ENABLE true
#define BMP_SDA_PIN 21
#define BMP_SCL_PIN 22

/* Dallas Temperature config and enable */
#define TEMPERATURE_ENABLE true
#define ONE_WIRE_BUS 4

/* LED built in ESP32 */
#ifndef LED
#define LED 2 // LED PIN number
#endif

// Button built in ESP32 in GPIO36
#define BUTTON 36

#endif
