#ifndef DISPLAY_DRIVER
#define DISPLAY_DRIVER

#include <stdio.h>
#include "masks.h"

#define WS2812_PIN 15
#define IS_RGBW false
#define NUM_PIXELS 133

// add a white value? can't rlly use a union at present...
typedef struct {
  uint8_t green;
  uint8_t red;
  uint8_t blue;
} pixel_t;

// left as a typedef in case you have a massive display
typedef uint8_t dim_t;

#define HEIGHT 7
#define WIDTH 19

static pixel_t display[HEIGHT][WIDTH];
static pixel_t fill[HEIGHT][WIDTH];

void display_init();

/**
 * @brief Reset the global display to be off
 * 
 * is there a way to do this faster?
 */
void reset_display();

void apply_mask(int mask_num, dim_t r_start, dim_t c_start);

void update_fill(uint8_t r, uint8_t g, uint8_t b);

void write_display();

#endif