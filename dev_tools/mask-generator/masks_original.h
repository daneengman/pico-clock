#include <stdio.h>

typedef const uint8_t mask_array_t;
typedef const struct {
  const uint8_t height; 
  const uint8_t width; 
  mask_array_t *mask_array;
} mask_t;

mask_array_t mask_one[] = {1, 2, 3};
mask_t one = {8, 4, &mask_one[0]};

const struct {
    mask_t filter;
    const char *name;
} mask_table[] = {
        {one,  "One"},
};