add_library( masks
    masks.h
    masks.c
    )

target_link_libraries(masks PRIVATE pico_stdlib)

target_include_directories(masks PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

