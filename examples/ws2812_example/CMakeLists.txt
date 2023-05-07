add_executable(example_pio_ws2812)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)

# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_generate_pio_header(example_pio_ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(example_pio_ws2812 PRIVATE ws2812.c)

target_link_libraries(example_pio_ws2812 PRIVATE pico_stdlib hardware_pio)
pico_add_extra_outputs(example_pio_ws2812)

# # add url via pico_set_program_url
# example_auto_set_url(example_pio_ws2812)