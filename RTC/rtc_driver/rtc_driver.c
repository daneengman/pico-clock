#include "rtc_driver.h"
#include "hardware/timer.h"

#define RTC_ADDRESS 0x68

int8_t rtc_init() {
  // rtc_seconds = 13;
  // rtc_minutes = 0;
  // rtc_hours = 0;

  i2c_init(i2c_default, 100 * 1000);
  gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
  gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
  gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
  gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
}

// clock reset
/**
 * @brief 
 * 
 * @return int 0 upon success, -1 upon failure
 */
int8_t rtc_reset() {
  // rtc_seconds = 0;
  // rtc_minutes = 0;
  // rtc_hours = 0;
  // need to actually like transmit stuff
}

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
int8_t rtc_set(uint8_t hour, uint8_t minute, uint8_t second) {
  return -1;
}



// clock read time

// other features???
int8_t rtc_read(uint8_t time[3]) {
  uint8_t data;
  // printf("read %i\n", rtc_seconds);
  uint8_t address = 0x00; // location of seconds
  i2c_write_blocking_until(i2c_default, RTC_ADDRESS, &address, 1, false, make_timeout_time_ms(100));
  i2c_read_blocking_until(i2c_default, RTC_ADDRESS, &data, 1, false, make_timeout_time_ms(100));
  time[0] = (data >> 4) * 10 + (data & 0b1111);

  address = 0x01; // location of seconds
  i2c_write_blocking_until(i2c_default, RTC_ADDRESS, &address, 1, false, make_timeout_time_ms(100));
  i2c_read_blocking_until(i2c_default, RTC_ADDRESS, &data, 1, false, make_timeout_time_ms(100));
  time[1] = (data >> 4) * 10 + (data & 0b1111);

  address = 0x02; // location of seconds
  i2c_write_blocking_until(i2c_default, RTC_ADDRESS, &address, 1, false, make_timeout_time_ms(100));
  i2c_read_blocking_until(i2c_default, RTC_ADDRESS, &data, 1, false, make_timeout_time_ms(100));
  
  time[2] = (data & 0x40) ? ((data >> 4) & 0b1) * 10 + (data & 0b1111) : ((data >> 4) & 0b11) * 10 + (data & 0b1111); // LHS is 12 hour mode RHS side is 24

  return 0; // add something about timeout, etc?
  // how to do define debugs, etc?
}
// what return type should we use for this?