/*
 * rgb_led.h
 *
 * Created on: Nov 27, 2023
 * Code created based on the "Iot Application Development with the ESP32 Using the ESP-IDF" course from Kevin Aguilar at Udemy
 * Available at: "https://www.udemy.com/course/iot-application-development-with-the-esp32-using-the-esp-idf/"
*/

#ifndef MAIN_RGB_LED_H_
#define MAIN_RGB_LED_H

// RGB LED GPIOs
#define RGB_LED_RED_GPIO 12
#define RGB_LED_GREEN_GPIO 13
#define RGB_LED_BLUE_GPIO 14

// RGB LED color channels
#define RGB_LED_CHANNEL_NUM 3

// RGB LED configuration
typedef struct {
    int channel;
    int gpio;
    int mode;
    int timer_index;
} ledc_info_t;

/*
 * Color to indicate WiFi application has started.
 */
void rgb_led_wifi_app_started(void);

/*
 * Color to indicate HTTP server has started.
 */
void rgb_led_http_server_started(void);

/*
 * Color to indicate that the ESP32 is connected to an access point.
 */
void rgb_led_wifi_connected(void);

#endif /* MAIN_RGB_LED_H_*/
