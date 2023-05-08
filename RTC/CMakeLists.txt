add_subdirectory(rtc_driver)

# file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)

add_executable(rtc_test)
# add_library(utils utils.h)
# add_library(ut)

# generate the header file into the source tree as it is included in the RP2040 datasheet
# pico_generate_pio_header(pio_ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(rtc_test PRIVATE rtc_test.c)

target_link_libraries(rtc_test PRIVATE pico_stdlib rtc_driver)
pico_add_extra_outputs(rtc_test)

add_executable(set_time)
target_sources(set_time PRIVATE set_time.c)
target_link_libraries(set_time PRIVATE pico_stdlib rtc_driver)
pico_add_extra_outputs(set_time)

# # add url via pico_set_program_url
# example_auto_set_url(pio_ws2812)