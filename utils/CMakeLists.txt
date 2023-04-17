add_executable(pio_ws2812_2)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)

# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_generate_pio_header(pio_ws2812_2 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(pio_ws2812_2 PRIVATE ws2812.c)

target_link_libraries(pio_ws2812_2 PRIVATE pico_stdlib hardware_pio)
pico_add_extra_outputs(pio_ws2812_2)

# # add url via pico_set_program_url
# example_auto_set_url(pio_ws2812_2)