# add_subdirectory(masks)
add_library( masks
    masks.h
    masks.c
    )

add_library( display_driver
    display_driver.h
    display_driver.c
    )

pico_generate_pio_header(display_driver ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_link_libraries(display_driver PRIVATE pico_stdlib hardware_pio)

target_include_directories(display_driver PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
# target_include_directories(masks PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")