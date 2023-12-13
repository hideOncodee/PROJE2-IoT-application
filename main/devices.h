/*
 * devices.h
 *
 * Created on: Dec 03, 2023
 * Author: Paulo Henrique Langone Miranda
*/

#ifndef MAIN_RGB_LED_H_
#define MAIN_RGB_LED_H

#include "freertos/FreeRTOS.h"

// Devices GPIOs
#define DEVICE_1_GPIO 4        //> lamp1
#define DEVICE_2_GPIO 16        //> lamp2
#define DEVICE_3_GPIO 17        //> fan

// Device selected from HTTP server 
extern char device_selected_str[50];

/**
 * Toggling the device status occurs after the on/off button on the web page is pressed.  
*/
void toggle_device_status_task_start(void);

#endif /* MAIN_DEVICES_H_*/