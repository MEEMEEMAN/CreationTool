cmake_minimum_required(VERSION 3.10)
project(SDL_LOOPER)
message("** COMPILING ${PROJECT_NAME} ** ")

add_library(SDL_LOOPER STATIC SDLLoop.cpp SDLWindow.cpp)
target_link_libraries(SDL_LOOPER SDL2 CreationToolCore)

if (WIN32)
    include_directories(../../../ThirdParty/GLAD/include)
    target_link_libraries(SDL_LOOPER GLAD)
elseif (ANDROID)
    target_link_libraries(SDL_LOOPER GLESv3)
endif ()