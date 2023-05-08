

// can I get rid of this?
#include <stdio.h>

#include "pico/stdlib.h"

#include <rtc_driver.h>

int main() {
    //set_sys_clock_48(); // what?
    stdio_init_all();
    printf("Set the current time using serial in\n");

    rtc_init();
    uint8_t time[3];
    uint8_t prev;
    char buf[255];
    char *curr_buf = buf;
    uint8_t val = 0;
    size_t i = 0;
    while(1) {
      uint8_t val = getchar_timeout_us(0);
      if (val != prev) {
        printf("%i\n", val);
        printf("%i\n", (val == 255) || (val < 58));
      }
      if (val != prev && val != 255) {
        *curr_buf = val;
        curr_buf++;
      }
      prev = val;
      if (!((val == 255) || (val < 58))) break;
    }
    *curr_buf = '\0';

    printf("Hi\n");

    printf("The buffer is %s\n\n", buf);

    time[0] = atoi(buf);

    printf("Current time: %i : %i : %i\n\n", time[2], time[1], time[0]);

    

    // uint8_t time[3];
    uint8_t previous = time[0];
    while(1) {
        rtc_read(time);
        if (time[0] != previous) {
            // printf("Current time: %i : %i : %i\n", time[2], time[1], time[0]);
        }
        previous = time[0];
        
    }
}
