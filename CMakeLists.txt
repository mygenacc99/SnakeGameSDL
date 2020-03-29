cmake_minimum_required(VERSION 3.15)
project(SnakeGameSDL)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# Find SDL2, SDL2_image and SDL2_gfx libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(
        ${PROJECT_SOURCE_DIR}/header
        ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/header/*.h"
        "${PROJECT_SOURCE_DIR}/header/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        "${PROJECT_SOURCE_DIR}/main.cpp"
        )

add_executable(SnakeGameSDL ${all_SRCS} )

# Link SDL2::Main, SDL2::Image to our project
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image )
