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
// #include "sdkconfig.h"

/* Can run 'make menuconfig' to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO_Index 		2
	


void blink_task(void * param);
	

static unsigned int usr_ticks;

void app_main()
{
	vTaskDelay(pdMS_TO_TICKS(100));			//等待系统初始化
	// 任务栈的大小 小于 1024 报错
	xTaskCreatePinnedToCore(blink_task, "blink_task", 2048, "blink_task", 5, NULL, tskNO_AFFINITY);
    while(1) {
		/* Blink off (output low) */
		printf("Ticks: %d\n", usr_ticks);
		vTaskDelay(1500 / portTICK_PERIOD_MS);
		usr_ticks++;
    }
}

void blink_task(void * param)
{
	gpio_pad_select_gpio(BLINK_GPIO_Index);
	/* Set the GPIO as a push/pull output */
	gpio_pad_pullup(BLINK_GPIO_Index);
	gpio_set_direction(BLINK_GPIO_Index, GPIO_MODE_OUTPUT);

	while(1) {
		printf("LED loop, In task: %s,\n", (char *)param);	
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

