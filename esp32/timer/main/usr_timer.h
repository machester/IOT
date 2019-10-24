#ifndef __USR_TIMER_H
#define __USR_TIMER_H

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

#define DEBUG               1


#define dbg_msg(fmt, ##args)        \
    do {                            \
        if (DEBUG)                  \
            printf(fmt, ##args);    \
    } while(0)

#endif