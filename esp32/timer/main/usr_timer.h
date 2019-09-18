#ifndef __USR_TIMER_H
#define __USR_TIMER_H

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


#define DEBUG               1


#define dbg_msg(fmt, ##args)        \
    do {                            \
        if (DEBUG)                  \
            printf(fmt, ##args);    \
    } while(0)

#endif