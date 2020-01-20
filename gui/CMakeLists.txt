set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

get_target_property(XXFFI_LIB_NAME xxffi LIB_NAME)
get_target_property(XXFFI_LIB_DIR xxffi LIB_LOCATION)

link_directories(
    ${XXFFI_LIB_DIR}
    )

file(
    GLOB_RECURSE
    ALL_FILES
    src/*
    )

add_executable(
    gui
    ${ALL_FILES}
    )

target_link_libraries(
    gui
    Qt5::Widgets
    ${XXFFI_LIB_DIR}/${XXFFI_LIB_NAME}
    )

add_dependencies(gui xxffi)
