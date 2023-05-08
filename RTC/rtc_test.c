

// can I get rid of this?
#include <stdio.h>

#include "pico/stdlib.h"

#include <rtc_driver.h>

int main() {
    //set_sys_clock_48(); // what?
    stdio_init_all();
    printf("Test of basic RTC communication features\n");

    rtc_init();
    printf("hi\n");
    uint8_t time[3];
    uint8_t previous = time[0];
    while(1) {
        rtc_read(time);
        if (time[0] != previous) {
            printf("Current time: %i : %i : %i\n", time[2], time[1], time[0]);
        }
        previous = time[0];
        
    }
}
