set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(
    ALL_FILES
    main.cpp
    )

add_executable(
    editor
    ${ALL_FILES}
    )

set(
    ${ALL_LIBS}
    Qt5::Widgets
    )

target_link_libraries(
    editor
    ${ALL_LIBS}
    )

#add_dependencies(gui client)
