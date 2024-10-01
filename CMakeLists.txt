cmake_minimum_required(VERSION 3.28)

# set(CMAKE_C_COMPILER "/opt/homebrew/bin/gcc-14")
# set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")

project(c-template C)

file(
        DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.40.2/CPM.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
        EXPECTED_HASH SHA256=c8cdc32c03816538ce22781ed72964dc864b2a34a310d3b7104812a5ca2d835d
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.c)

# Packages to add with CPM 
CPMAddPackage("gh:stclib/STC#master")
CPMAddPackage("gh:antirez/sds#master")
#CPMAddPackage("gh:ThrowTheSwitch/CException@1.3.4")
#CPMAddPackage("gh:raysan5/raylib#master")
#CPMAddPackage("gh:GNOME/glib#main")
#CPMAddPackage("gh:microsoft/mimalloc@2.1.7")
#CPMAddPackage("gh:Hirrolot/Datatype99@1.6.4")
#CPMAddPackage("gh:Hirrolot/interface99@1.0.1")

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W3)  
    # Missing macro limit 1 for MSVC
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wpedantic)
    
    if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE -fmacro-backtrace-limit=1)
    elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU")
        target_compile_options(${PROJECT_NAME} PRIVATE -ftrack-macro-expansion=0)
    endif()
endif ()

# SDS library
target_include_directories(${PROJECT_NAME} PRIVATE ${sds_SOURCE_DIR})
set(SDS_FILES ${sds_SOURCE_DIR}/sds.c ${sds_SOURCE_DIR}/sds.h)
add_library(sds ${SDS_FILES})

# CException library
# target_include_directories(${PROJECT_NAME} PRIVATE ${cexception_SOURCE_DIR})
# set(CEXCEPTION_FILES ${CException_SOURCE_DIR}/lib/CException.c ${CException_SOURCE_DIR}/lib/CException.h)
# add_library(cexception ${CEXCEPTION_FILES})

# Glib
# find_package(PkgConfig REQUIRED)
# pkg_search_module(GLIB REQUIRED glib-2.0)
# include_directories(${GLIB_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE stc sds cexception) # cexception raylib ${GLIB_LDFLAGS} mimalloc-static datatype99 interface99)
