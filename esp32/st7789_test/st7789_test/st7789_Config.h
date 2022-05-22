//
// Created by quan on 2022/3/18.
//

#ifndef st7789_Config.h
#define st7789_Config.h
#ifdef __cplusplus
extern "C" {
#endif

// esp32
#include <esp_log.h>

#define ST7789_DEBUG_FLAG           true
#define TAG "ST7789: "
#define st7789_logError(fmt, args...)   ESP_LOGE( TAG, format, ... )
#define st7789_logInfo(fmt, args...)    do {                                    \
											if(ST7789_DEBUG_FLAG)               \
                                                ESP_LOGI( TAG, format, ... )    \
											}while(0)

/***
 * screen info :
 * 	wm-size: 240x280
 * 	ph-size:1.69 inch
 * 	buy: https://item.taobao.com/item.htm?spm=a1z0d.6639537.1997196601.71.58717484RFy9Mn&id=666505851661
 */

// jiangquan , enable mannual
// cofing for st7789v2
// chip spi flash size 4M
#define CONFIG_WIDTH  240
#define CONFIG_HEIGHT 280
#define CONFIG_MOSI_GPIO 23
#define CONFIG_SCLK_GPIO 18
#define CONFIG_CS_GPIO 26
#define CONFIG_DC_GPIO 27
#define CONFIG_RESET_GPIO 33
#define CONFIG_BL_GPIO 32
#define CONFIG_OFFSETX 0    // X 轴偏移
#define CONFIG_OFFSETY 19   // Y 轴偏移

#ifdef __cplusplus
}
#endif

#endif //st7789_Config
