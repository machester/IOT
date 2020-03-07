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
#include "esp_types.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "soc/timer_group_struct.h"
#include "driver/timer.h"
#include "esp_timer.h"
#include "driver/periph_ctrl.h"


/* Can run 'make menuconfig' to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO 		CONFIG_BLINK_GPIO

const char timer_name[] = "fw_timer"; 
uint8_t args_transfer[] = "timer args transfer";

esp_timer_handle_t fw_timer_handler = 0;

static uint32_t recall_cnt;

void fw_timer_callback(void *args)
{
	uint8_t * param_transfer_in = (uint8_t *)args;
	printf("Transfer in param is: %s\n", param_transfer_in);

	// 获取时间戳
	int64_t ticks = esp_timer_get_time();
	printf("---> timer cnt = %lld \n", ticks);

	if(ticks > (300 * 1000 * 1000)) { // stop counter afer 50 seconds
		printf("timer stop protocal\n");
		esp_timer_stop(fw_timer_handler);
		esp_timer_delete(fw_timer_handler);
		
		// reboot system
		esp_restart();
	}
	// blink led
	gpio_set_level(BLINK_GPIO, (recall_cnt % 2));
	recall_cnt++;
}



void app_main()
{
	vTaskDelay(pdMS_TO_TICKS(100));			//等待系统初始化
	
	gpio_pad_select_gpio(BLINK_GPIO);
	/* Set the GPIO as a push/pull output */
	gpio_pad_pullup(BLINK_GPIO);
	gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

	/** start: create timer ------------------------------*/

	esp_timer_create_args_t timer_fill = {
		.callback = &fw_timer_callback,
		// .arg = NULL;
		.arg = (void *)args_transfer,
		.name = timer_name				// timer name
	};

	esp_err_t err = esp_timer_create(&timer_fill, &fw_timer_handler);
	if(err != ESP_OK) {
		printf("timer create failed \n");
		return;
	}
	err = esp_timer_start_periodic(fw_timer_handler, (0.5 * (1000 * 1000))); // recall every 0.5 sec
	if(err != ESP_OK) {
		printf("timer start period failed \n");
		return;
	} else {
		printf("timer create succeed, timer name: %s.\n", timer_name);
	}
	
	/** end: create timer ------------------------------*/


}

