cmake_minimum_required(VERSION 3.10)

project(ImGUI)

file(GLOB_RECURSE ImGUI_SRC ${PROJECT_SOURCE_DIR}/*.cpp)
include_directories(../SDL2/include)

add_library(${PROJECT_NAME} STATIC ${ImGUI_SRC})