set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(ROOT_BUILD_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/..)

include_directories(
    ${ROOT_BUILD_DIRECTORY}
    )

link_directories(
    ${ROOT_BUILD_DIRECTORY}/xxffi/debug/debug/
    )

set(
    ALL_FILES
    main.cpp
    )

add_executable(
    gui
    ${ALL_FILES}
    )

target_link_libraries(
    gui
    Qt5::Widgets
    )

target_link_libraries(
    gui
    ${ROOT_BUILD_DIRECTORY}/xxffi/debug/debug/libxxffi.so
    )

add_dependencies(
    gui
    xxffi
    )
