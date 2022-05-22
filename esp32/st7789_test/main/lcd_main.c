
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#include "../st7789_test/board_gpio_def.h"
#include "../st7789_test/board_gpio_def.h"
#include "../st7789_test/st7789_draw.h"


#define BLINK_TASK_NAME				"led_blink"
#define REFRESH_LCD_ST7789		    "refresh_lcd"


void blink_task(void * param);
void st7789_refresh_task(void * param);

static unsigned int usr_ticks;

void app_main()
{
	vTaskDelay(pdMS_TO_TICKS(200));			//等待系统初始化

	gpio_pad_select_gpio(LED_GPIO);
	/* Set the GPIO as a push/pull output */
	gpio_pad_pullup(LED_GPIO);
	gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

	// 任务栈的大小 小于 1024 报错, 制定cpu创建task
	// configMINIMAL_STACK_SIZE
	xTaskCreatePinnedToCore(blink_task, BLINK_TASK_NAME, 2048, BLINK_TASK_NAME, 7, NULL, tskNO_AFFINITY);
	xTaskCreate(st7789_refresh_task, REFRESH_LCD_ST7789, 1024 * 6, REFRESH_LCD_ST7789, 5, NULL);
}

void blink_task(void * param)
{

	while(1) {
		printf("LED loop, In task: %s,\n", (char *)param);
		gpio_set_level(LED_GPIO, 1);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
		gpio_set_level(LED_GPIO, 0);
		vTaskDelay(1500 / portTICK_PERIOD_MS);
	}

}
void st7789_refresh_task(void * param)
{
	while(1) {
		printf("In st7789_refresh_task, param: %s,\n", (char *)param);
		LedTaskEntry();
	}
}

