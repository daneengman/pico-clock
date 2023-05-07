#ifndef RTC_DRIVER
#define RTC_DRIVER

#include <stdio.h>
#include "hardware/i2c.h"

// clock reset
/**
 * @brief 
 * 
 * @return int 0 upon success, -1 upon failure
 */
int8_t rtc_reset();

// clock set time
// make a fancier one that knows how to interact with shell script
// my goodness i am quite tired
/**
 * @brief 
 * 
 * @return int 0 upon success, -1 upon failure
 * // axe this in an embedded environment?
 */
// add date? does it have smart rollover and stuff? read the docs
int8_t rtc_set(uint8_t hour, uint8_t minute, uint8_t second);



// clock read time

// other features???
void rtc_read();
// what return type should we use for this?
#endif