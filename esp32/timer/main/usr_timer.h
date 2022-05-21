#ifndef __USR_TIMER_H
#define __USR_TIMER_H

#define DEBUG               1


#define dbg_msg(fmt, ##args)        \
    do {                            \
        if (DEBUG)                  \
            printf(fmt, ##args);    \
    } while(0)

#endif