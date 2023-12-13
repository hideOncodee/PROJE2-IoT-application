/**
 * http_server.h
 *
 * Created on: Nov 29, 2023
 * Code created based on the "Iot Application Development with the ESP32 Using the ESP-IDF" course from Kevin Aguilar at Udemy
 * Available at: "https://www.udemy.com/course/iot-application-development-with-the-esp32-using-the-esp-idf/"
*/

#ifndef HTTP_SERVER_H_
#define HTTP_SERVER_H_

#include "freertos/FreeRTOS.h"

/**
 * Messages for the HTTP monitor
*/
typedef enum http_server_message
{
    HTTP_MSG_WIFI_CONNECT_INIT = 0,
    HTTP_MSG_WIFI_CONNECT_SUCCESS,
    HTTP_MSG_WIFI_CONNECT_FAIL,
} http_server_message_e;

/**
 * Structure for the message queue.
*/
typedef struct http_server_queue_message
{
    http_server_message_e msgID;
} http_server_queue_message_t;

/**
 * Sends a message to the queue
 * @param msgID message ID from the http_server_message_e.
 * @return pdTRUE if an item was successfully sent to the queue, otherwise pdFALSE.
 * @note Expand the parameter list based on the application
*/
BaseType_t http_server_monitor_send_message(http_server_message_e msgID);

/**
 * Starts the HTTP server
*/
void http_server_start(void);

/**
 * Stops the HTTP server
*/
void http_server_stop(void);

#endif /* MAIN_HTTP_SERVER_H_*/