#ifndef MASKS
#define MASKS

#include <stdio.h>

typedef const uint8_t mask_array_t;
typedef const struct {
  const uint8_t height; 
  const uint8_t width; 
  const mask_array_t *mask_array;
} mask_t;


static mask_array_t mask_array_zero[] = {0b10010110, 0b10011001, 0b10011001, 0b0110, };
static mask_t mask_zero = {7, 4, mask_array_zero};

static mask_array_t mask_array_one[] = {0b01100100, 0b01000100, 0b01000100, 0b0100, };
static mask_t mask_one = {7, 4, mask_array_one};

static mask_array_t mask_array_two[] = {0b10010110, 0b10001000, 0b00100100, 0b1111, };
static mask_t mask_two = {7, 4, mask_array_two};

static mask_array_t mask_array_three[] = {0b10010110, 0b01001000, 0b10011000, 0b0110, };
static mask_t mask_three = {7, 4, mask_array_three};

static mask_array_t mask_array_four[] = {0b11001000, 0b11111010, 0b10001000, 0b1000, };
static mask_t mask_four = {7, 4, mask_array_four};

static mask_array_t mask_array_five[] = {0b00011111, 0b01110001, 0b10011000, 0b0110, };
static mask_t mask_five = {7, 4, mask_array_five};

static mask_array_t mask_array_six[] = {0b01001000, 0b01110010, 0b10011001, 0b0110, };
static mask_t mask_six = {7, 4, mask_array_six};

static mask_array_t mask_array_seven[] = {0b10001111, 0b10001000, 0b00100100, 0b0001, };
static mask_t mask_seven = {7, 4, mask_array_seven};

static mask_array_t mask_array_eight[] = {0b10010110, 0b01101001, 0b10011001, 0b0110, };
static mask_t mask_eight = {7, 4, mask_array_eight};

static mask_array_t mask_array_nine[] = {0b10010110, 0b11101001, 0b00100100, 0b0001, };
static mask_t mask_nine = {7, 4, mask_array_nine};


static const struct {
    mask_t *const mask;
    const char *name;
} mask_table[] = {
    {&mask_zero, "zero"},
    {&mask_one, "one"},
    {&mask_two, "two"},
    {&mask_three, "three"},
    {&mask_four, "four"},
    {&mask_five, "five"},
    {&mask_six, "six"},
    {&mask_seven, "seven"},
    {&mask_eight, "eight"},
    {&mask_nine, "nine"},
};

#endif