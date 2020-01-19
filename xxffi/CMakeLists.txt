if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CARGO_CMD cargo build)
    set(BUILD_TYPE "debug")
else ()
    set(CARGO_CMD cargo build --release)
    set(BUILD_TYPE "release")
endif ()

set(LIB_NAME libxxffi.so)
set(LIB_ABS_PATH ${CMAKE_CURRENT_BINARY_DIR}/${BUILD_TYPE}/${LIB_NAME})

add_custom_command(
    OUTPUT install-cbindgen
    COMMENT "Attempting to install cbindgen..."
    COMMAND cargo install cbindgen || true
    )

add_custom_command(
    OUTPUT ${LIB_ABS_PATH}
    COMMENT "Compiling xxffi dependency..."
    DEPENDS install-cbindgen
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND CARGO_TARGET_DIR=${CMAKE_CURRENT_BINARY_DIR} ${CARGO_CMD};
    )

add_custom_command(
    OUTPUT generate-ffi-headers
    COMMENT "Generating header files for xxffi..."
    DEPENDS ${LIB_ABS_PATH}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND cbindgen ${CMAKE_CURRENT_SOURCE_DIR} -o xxffi.h
    )

add_custom_target(
    xxffi ALL
    DEPENDS generate-ffi-headers
    )

set_target_properties(xxffi PROPERTIES LIB_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/${BUILD_TYPE})
set_target_properties(xxffi PROPERTIES LIB_NAME ${LIB_NAME})
