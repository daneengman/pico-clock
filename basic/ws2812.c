/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
// #include "hardware/pio.h"
#include "hardware/clocks.h"
// #include "ws2812.pio.h"

// #include "masks.h"

#include "display_driver.h"

// #ifdef PICO_DEFAULT_WS2812_PIN
// #define WS2812_PIN PICO_DEFAULT_WS2812_PIN
// #else
// default to pin 2 if the board doesn't have a default WS2812 pin defined

// #endif

static void inline write_two() {
    // generate the array
    // for (uint8_t i = 0; i < 7; i++) {
    //     for (uint8_t j = 0; j < 19; j++) {
    //         if (j >= 4) {
    //             display[i][j] = 0;
    //             continue;
    //         }
    //         uint8_t index = i * 4 + j;
    //         uint8_t reverse_index = 4*7 - 1 - index;
    //         if ((two_mask >> reverse_index) & 1) display[i][j] = urgb_u32(32, 0, 32);
    //         else display[i][j] = 0;
    //         printf("%i", display[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\ndisplay calculated\n");

    // // write the array
    // for (uint8_t i = 0; i < 7; i++) {
    //     if (i%2 == 0) {
    //         for (uint8_t j = 0; j < 19; j++) {
    //             // printf("putting pixel backwards\n");
    //             put_pixel(display[i][j]);
    //         }
    //     } else {
    //         for (uint8_t j = 19; j > 0;) {
    //             j--;
    //             // printf("putting pixel\n");
    //             put_pixel(display[i][j]);
    //         }
    //     }
        
    // }
    // puts("put row\n");
}

// void pattern_snakes(uint len, uint t) {
//     for (uint i = 0; i < len; ++i) {
//         uint x = (i + (t >> 1)) % 64;
//         if (x < 10)
//             put_pixel(urgb_u32(0xff, 0, 0));
//         else if (x >= 15 && x < 25)
//             put_pixel(urgb_u32(0, 0xff, 0));
//         else if (x >= 30 && x < 40)
//             put_pixel(urgb_u32(0, 0, 0xff));
//         else
//             put_pixel(0);
//     }
// }

// void pattern_random(uint len, uint t) {
//     if (t % 8)
//         return;
//     for (int i = 0; i < len; ++i)
//         put_pixel(rand());
// }

// void pattern_sparkle(uint len, uint t) {
//     if (t % 8)
//         return;
//     for (int i = 0; i < len; ++i)
//         put_pixel(rand() % 16 ? 0 : 0xffffffff);
// }

// void pattern_greys(uint len, uint t) {
//     int max = 100; // let's not draw too much current!
//     t %= max;
//     for (int i = 0; i < len; ++i) {
//         put_pixel(t * 0x10101);
//         if (++t >= max) t = 0;
//     }
// }

// const uint8_t masks[] = {1, 2, 3};

// typedef void (*pattern)(uint len, uint t);
// const struct {
//     pattern pat;
//     const char *name;
// } pattern_table[] = {
//         {pattern_snakes,  &masks},
//         {pattern_random,  "Random data"},
//         {pattern_sparkle, "Sparkles"},
//         {pattern_greys,   "Greys"},
// };

int main() {
    //set_sys_clock_48(); // what?
    stdio_init_all();
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    // BARF
    // todo get free sm
    display_init();

    reset_display();
    update_fill(64, 0, 64);
    apply_mask(0, 0, 0);
    apply_mask(1, 0, 5);
    apply_mask(2, 0, 10);
    apply_mask(3, 0, 15);

    int t = 0;
    uint8_t red_p = 0;
    uint8_t green_p = 0;
    uint8_t blue_p = 0;
    while (1) {
        // int pat = rand() % count_of(pattern_table);

        int dir = (rand() >> 30) & 1 ? 1 : -1;
        // puts(pattern_table[pat].name);
        // puts(dir == 1 ? "(forward)" : "(backward)");
        uint8_t red = rand();
        uint8_t blue = rand();
        uint8_t green = rand();
        int cycles = 5;
        for (int c = 0; c < cycles; c++) {
            reset_display();
            update_fill(red_p + (red-red_p)*c/cycles, green_p + (green-green_p)*c/cycles, blue_p + (blue-blue_p)*c/cycles);

            apply_mask((t/1000)%10, 0, 0);
            apply_mask((t/100)%10, 0, 5);
            apply_mask((t/10)%10, 0, 10);
            apply_mask(t%10, 0, 15);
            
            write_display();

            sleep_ms(1);
        }
        ++t;
        red_p = red;
        blue_p = blue;
        green_p = green;
        

        
    }
}
