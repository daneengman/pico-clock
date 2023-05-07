#include <stdio.h>


#include "pico/stdlib.h"

#include "display_driver.h"
#include "ws2812.pio.h"

// typedef const uint8_t mask_array_t;
// typedef const struct {
//   const uint8_t height; 
//   const uint8_t width; 
//   const mask_array_t mask_array[4];
// } mask_t;


// // mask_array_t mask_array_one[] = ;
// // mask_t mask_one = {7, 4, {0b11001000, 0b10001000, 0b10001000, 0b1000, }};

// // // mask_array_t mask_array_two[] = {0b10010110, 0b10001000, 0b00100100, 0b1111, };
// // mask_t mask_two = {7, 4, {0b10010110, 0b10001000, 0b00100100, 0b1111, }};

// // // mask_array_t mask_array_three[] = {0b10010110, 0b01001000, 0b10011000, 0b0110, };
// // mask_t mask_three = {7, 4, {0b10010110, 0b01001000, 0b10011000, 0b0110, }};


// const struct {
//     mask_t mask;
//     const char *name;
// } mask_table[] = {
//     {{7, 4, {0b10010110, 0b10011001, 0b10011001, 0b0110, }}, "zero"},
//     {{7, 4, {0b11001000, 0b10001000, 0b10001000, 0b1000, }}, "one"},
//     {{7, 4, {0b10010110, 0b10001000, 0b00100100, 0b1111, }}, "two"},
//     {{7, 4, {0b10010110, 0b01001000, 0b10011000, 0b0110, }}, "three"},
// };

static inline uint32_t format(pixel_t pixel) {
  return
    (((uint32_t) (pixel.red) << 8) |
     ((uint32_t) (pixel.green) << 16) |
     (uint32_t) (pixel.blue)) << 8U;
}

static inline void put_pixel(pixel_t pixel) {
    pio_sm_put_blocking(pio0, 0, format(pixel));
}

/**
 * @brief Reset the global display to be off
 * 
 * is there a way to do this faster?
 */
void reset_display() {
  for (dim_t r = 0; r < HEIGHT; r++) {
    for (dim_t c = 0; c < WIDTH; c++) {
      display[r][c].red = 0;
      display[r][c].green = 0;
      display[r][c].blue = 0;
    }
  }
}

void apply_mask(int mask_num, dim_t r_start, dim_t c_start) {
  mask_t mask = *(mask_table[mask_num].mask);
  dim_t r, c;
  for (dim_t r_mask = 0; r_mask < mask.height; r_mask++) {
    for (dim_t c_mask = 0; c_mask < mask.width; c_mask++) {
      r = r_start + r_mask;
      c = c_start + c_mask;
      uint8_t i = r_mask * mask.width + c_mask;
      // printf("Row: %i Col: %i Index: %i\n", r, c, i);
      bool transfer = (mask.mask_array[i/8] >> (i%8)) & 1;
      // printf("Transfer: %i", transfer);
      if(transfer) display[r][c] = fill[r][c];
      // pretty sure this is wrong
      // #ifdef Debug
      // if (r >= WIDTH || c >= HEIGHT) printf("WARNING: Mask is out of bounds\n");
      // #endif
    }
  }
}

void update_fill(uint8_t red, uint8_t green, uint8_t blue) {
  for (dim_t r = 0; r < HEIGHT; r++) {
    for (dim_t c = 0; c < WIDTH; c++) {
      fill[r][c].red = red;
      fill[r][c].green = green;
      fill[r][c].blue = blue;
    }
  }
}

void write_display() {
  for (dim_t r = 0; r < HEIGHT; r++) {
    if (r%2 == 0) {
        for (dim_t c = 0; c < WIDTH; c++) {
            put_pixel(display[r][c]);
        }
    } else {
        for (dim_t c = WIDTH; c > 0;) {
            c--;
            put_pixel(display[r][c]);
        }
    }
  }
  puts("Wrote to display\n"); 
}

void display_init() {
  PIO pio = pio0;
  int sm = 0;
  uint offset = pio_add_program(pio, &ws2812_program);

  ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

  for (dim_t r = 0; r < HEIGHT; r++) {
    for (dim_t c = 0; c < WIDTH; c++) {
      fill[r][c].red = 64;
      fill[r][c].green = 0;
      fill[r][c].blue = 64;
    }
  }
}