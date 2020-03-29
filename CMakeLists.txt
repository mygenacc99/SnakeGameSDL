cmake_minimum_required(VERSION 3.15)
project(SnakeGameSDL)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# Find SDL2, SDL2_image and SDL2_gfx libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)


add_executable(SnakeGameSDL main.cpp header/LTexture.h src/LTexture.cpp src/Game.cpp header/Game.h header/Header.h)

# Link SDL2::Main, SDL2::Image to our project
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image )
