/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

/* Can run 'make menuconfig' to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO_Index 		2
	


void blink_task(void * param);
	

	
void app_main()
{
	xTaskCreate(blink_task, "blink_task", 512, NULL, 10, NULL);

	while(1){
		vTaskDelay(1500 / portTICK_PERIOD_MS);
	}
}

void blink_task(void * param)
{
	gpio_pad_select_gpio(BLINK_GPIO_Index);
	/* Set the GPIO as a push/pull output */
	gpio_pad_pullup(BLINK_GPIO_Index);
	gpio_set_direction(BLINK_GPIO_Index, GPIO_MODE_OUTPUT);

	while(1) {
		printf("LED loop\n");	
		gpio_set_level(BLINK_GPIO_Index, 1);
		vTaskDelay(100 / portTICK_PERIOD_MS);
		gpio_set_level(BLINK_GPIO_Index, 0);
		vTaskDelay(100 / portTICK_PERIOD_MS);
		gpio_set_level(BLINK_GPIO_Index, 1);
		vTaskDelay(100 / portTICK_PERIOD_MS);
		gpio_set_level(BLINK_GPIO_Index, 0);
		vTaskDelay(100 / portTICK_PERIOD_MS);
		gpio_set_level(BLINK_GPIO_Index, 1);
		vTaskDelay(100 / portTICK_PERIOD_MS);

		gpio_set_level(BLINK_GPIO_Index, 0);
		vTaskDelay(1500 / portTICK_PERIOD_MS);
	}

}

