# add_subdirectory(masks)

add_library( rtc_driver
    rtc_driver.h
    rtc_driver.c
    )

# pico_generate_pio_header(display_driver ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_link_libraries(rtc_driver PRIVATE pico_stdlib hardware_i2c)
# target_link_libraries(mcp9808_i2c pico_stdlib hardware_i2c)

target_include_directories(rtc_driver PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
# target_include_directories(masks PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")