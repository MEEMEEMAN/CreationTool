cmake_minimum_required(VERSION 3.10)
project(EDITOR_TOOLING)
message("** COMPILING ${PROJECT_NAME} ** ")

file(GLOB_RECURSE Editor_Src "${PROJECT_SOURCE_DIR}/*.cpp" "${PROJECT_SOURCE_DIR}/*.h")

add_library(EDITOR_TOOLING SHARED ${Editor_Src})
target_link_libraries(EDITOR_TOOLING CreationToolCore SDL_LOOPER)