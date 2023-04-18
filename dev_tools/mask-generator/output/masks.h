#include <stdio.h>

typedef const uint8_t mask_array_t;
typedef const struct {
  const uint8_t height; 
  const uint8_t width; 
  mask_array_t *mask_array;
} mask_t;


mask_array_t mask_array_one[] = {0b11001000, 0b10001000, 0b10001000, 0b1000, };
mask_t mask_one = {7, 4, &mask_array_one[0]};

mask_array_t mask_array_two[] = {0b10010110, 0b10001000, 0b00100100, 0b1111, };
mask_t mask_two = {7, 4, &mask_array_two[0]};

mask_array_t mask_array_three[] = {0b10010110, 0b01001000, 0b10011000, 0b0110, };
mask_t mask_three = {7, 4, &mask_array_three[0]};


const struct {
    mask_t mask;
    const char *name;
} mask_table[] = {
    {mask_one, "one"},
    {mask_two, "two"},
    {mask_three, "three"},
};