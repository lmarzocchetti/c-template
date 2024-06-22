cmake_minimum_required(VERSION 3.28)

# set(CMAKE_C_COMPILER "/opt/homebrew/bin/gcc-14")
# set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")

project(c-template C)

file(
        DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.40.0/CPM.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
        EXPECTED_HASH SHA256=7b354f3a5976c4626c876850c93944e52c83ec59a159ae5de5be7983f0e17a2a
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.c)

# CPMAddPackage() -> example CPMAddPackage("gh:nlohmann/json@3.10.5")
CPMAddPackage("gh:stclib/STC#master")
CPMAddPackage("gh:microsoft/mimalloc@2.1.7")
CPMAddPackage("gh:antirez/sds#master")

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W3)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wpedantic)
endif ()

# SDS library
target_include_directories(${PROJECT_NAME} PRIVATE ${sds_SOURCE_DIR})
set(SDS_FILES ${sds_SOURCE_DIR}/sds.c ${sds_SOURCE_DIR}/sds.h)
add_library(sds ${SDS_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE stc mimalloc-static sds)
