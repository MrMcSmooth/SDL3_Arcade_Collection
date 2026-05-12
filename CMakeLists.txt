cmake_minimum_required(VERSION 3.16)

get_filename_component(PROJECT_FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_FOLDER_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED sdl3)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL3_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${SDL3_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL3_LIBRARIES})
target_compile_options(${PROJECT_NAME} PRIVATE ${SDL3_CFLAGS_OTHER})
