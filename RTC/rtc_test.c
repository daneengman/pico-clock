/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// can I get rid of this?
#include <stdio.h>

#include "pico/stdlib.h"

#include <rtc_driver.h>

int main() {
    //set_sys_clock_48(); // what?
    stdio_init_all();
    printf("Test of basic RTC communication features\n");

    
}
