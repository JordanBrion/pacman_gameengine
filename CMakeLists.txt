cmake_minimum_required(VERSION 3.13)
project(pacman-editor)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    )

add_subdirectory(xxffi)
add_subdirectory(gui)

