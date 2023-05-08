add_subdirectory(display_driver)

# file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)

add_executable(pio_ws2812)
# add_library(utils utils.h)
# add_library(ut)

# generate the header file into the source tree as it is included in the RP2040 datasheet
# pico_generate_pio_header(pio_ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(pio_ws2812 PRIVATE ws2812.c)

target_link_libraries(pio_ws2812 PRIVATE pico_stdlib display_driver)
pico_add_extra_outputs(pio_ws2812)



add_executable(basic_clock)
# add_library(utils utils.h)
# add_library(ut)

# generate the header file into the source tree as it is included in the RP2040 datasheet
# pico_generate_pio_header(pio_ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(basic_clock PRIVATE basic_clock.c)

target_link_libraries(basic_clock pico_stdlib display_driver rtc_driver)
pico_add_extra_outputs(basic_clock)

# # add url via pico_set_program_url
# example_auto_set_url(pio_ws2812)