cmake_minimum_required(VERSION 3.10)
project(SDL_LOOPER)
message("** COMPILING ${PROJECT_NAME} ** ")

add_library(SDL_LOOPER STATIC SDLLoop.cpp SDLWindow.cpp SDLWindow.h)
include_directories(../../../ThirdParty/GLAD/include)

target_link_libraries(SDL_LOOPER GLAD SDL2 CreationToolCore)