if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CARGO_CMD cargo build)
    set(TARGET_DIR "debug")
else ()
    set(CARGO_CMD cargo build --release)
    set(TARGET_DIR "release")
endif ()

set(LIB_NAME libxxffi.so)
set(SRC_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET_DIR})
set(SRC_LIB_PATH "${SRC_LIB_DIR}/${LIB_NAME}")
set(DST_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_DIR})
set(DST_LIB_PATH "${DST_LIB_DIR}/${LIB_NAME}")

add_custom_command(
    OUTPUT install-cbindgen
    PRE_BUILD
    COMMENT "Attempting to install cbindgen..."
    COMMAND cargo install cbindgen || true
    )

add_custom_command(
    OUTPUT compile-ffi
    COMMENT "Compiling xxffi dependency..."
    DEPENDS install-cbindgen
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND CARGO_TARGET_DIR=${DST_LIB_DIR} ${CARGO_CMD}
    )

add_custom_command(
    OUTPUT generate-ffi-headers
    COMMENT "Generating header files for xxffi..."
    DEPENDS compile-ffi
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND cbindgen ${CMAKE_CURRENT_SOURCE_DIR} -o xxffi.h
    )

add_custom_target(
    xxffi ALL
    DEPENDS generate-ffi-headers
    )

set_target_properties(xxffi PROPERTIES LOCATION ${CMAKE_CURRENT_BINARY_DIR})
