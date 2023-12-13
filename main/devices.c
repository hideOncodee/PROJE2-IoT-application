/*
 * devices.c
 *
 * Created on: Dec 03, 2023
 * Author: Paulo Henrique Langone Miranda
*/
#include <string.h>
#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "devices.h"
#include "tasks_common.h"

// Tag used for ESP serial console messages
static const char TAG[] = "devices_control";

// Device selected from http server
char device_selected_str[50] = "";

/**
 * Setup for devices GPIOs
*/
void setup_for_gpios(void)
{
    // Setup for GPIOs
    gpio_set_direction(DEVICE_1_GPIO, GPIO_MODE_INPUT_OUTPUT);
    gpio_set_direction(DEVICE_2_GPIO, GPIO_MODE_INPUT_OUTPUT);
    gpio_set_direction(DEVICE_3_GPIO, GPIO_MODE_INPUT_OUTPUT);
}
	
/**
 * Toggle selected device status
*/
void toggle_device_status_task(void *pvParamaters)
	{
    // Configure devices GPIOS
    setup_for_gpios();

    while(1)
    {

        if (strcmp(device_selected_str, "lamp1") == 0)
        {
            gpio_set_level(DEVICE_1_GPIO, !gpio_get_level(DEVICE_1_GPIO));
            ESP_LOGI(TAG, "LAMP 1 Status: %d", gpio_get_level(DEVICE_1_GPIO));
            device_selected_str[0] = '\0';
        }   
        else if (strcmp(device_selected_str, "lamp2") == 0)
        {
            gpio_set_level(DEVICE_2_GPIO, !gpio_get_level(DEVICE_2_GPIO));
            ESP_LOGI(TAG, "LAMP 2 Status: %d", gpio_get_level(DEVICE_2_GPIO));
            device_selected_str[0] = '\0';
        }     
        else if (strcmp(device_selected_str, "fan") == 0)
        {
            gpio_set_level(DEVICE_3_GPIO, !gpio_get_level(DEVICE_3_GPIO));
            ESP_LOGI(TAG, "Fan Status: %d", gpio_get_level(DEVICE_3_GPIO));
            device_selected_str[0] = '\0';            
        }
        else
        {
            //ESP_LOGI(TAG, "Waiting the user to select the device");
        }

        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

/**
 * Task for toggle selected device status
 * @param *device pointer to device_selected_str from devicesControl.json
*/
void toggle_device_status_task_start(void)
{
    // Start toggle device status task
    xTaskCreatePinnedToCore(&toggle_device_status_task, "toggle_device_status_task", DEVICES_CONTROL_TASK_STACK_SIZE, NULL, DEVICES_CONTROL_TASK_PRIORITY, NULL, DEVICES_CONTROL_TASK_CORE_ID);
}