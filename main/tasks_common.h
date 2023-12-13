/**
 * tasks_common.h
 * 
 * Created on: Nov 28, 2023
 * Code created based on the "Iot Application Development with the ESP32 Using the ESP-IDF" course from Kevin Aguilar at Udemy
 * Available at: "https://www.udemy.com/course/iot-application-development-with-the-esp32-using-the-esp-idf/"
*/

#ifndef MAIN_TASKS_COMMON_H_
#define MAIN_TASKS_COMMON_H_

// WiFi application task
#define WIFI_APP_TASK_STACK_SIZE        4096
#define WIFI_APP_TASK_PRIORITY          5
#define WIFI_APP_TASK_CORE_ID           0

// HTTP Server task
#define HTTP_SERVER_TASK_STACK_SIZE     8192
#define HTTP_SERVER_TASK_PRIORITY       4
#define HTTP_SERVER_TASK_CORE_ID        0

// HTTP Server monitor task
#define HTTP_SERVER_MONITOR_STACK_SIZE  4096
#define HTTP_SERVER_MONITOR_PRIORITY    3
#define HTTP_SERVER_MONITOR_CORE_ID     0

// DHT Sensor task
#define DHT_TASK_STACK_SIZE           4096
#define DHT_TASK_PRIORITY             5
#define DHT_TASK_CORE_ID              1

// Devices control task
#define DEVICES_CONTROL_TASK_STACK_SIZE 4096
#define DEVICES_CONTROL_TASK_PRIORITY   3
#define DEVICES_CONTROL_TASK_CORE_ID    1

#endif/* MAIN_TASKS_COMMON_H_ */