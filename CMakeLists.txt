cmake_minimum_required(VERSION 3.20)
project(ArcadeCollection
    VERSION 0.1.0
    DESCRIPTION "A 2D game engine with an arcade collection of games"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Predictable output locations #
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Warnings #
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# --- Dependencies --- #
include(FetchContent)
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.8
)
FetchContent_MakeAvailable(SDL3)

# --- Engine library --- #


# --- Games --- #
add_executable(pong games/pong/main.cpp)
target_link_libraries(pong PRIVATE SDL3::SDL3)
target_include_directories(pong PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})