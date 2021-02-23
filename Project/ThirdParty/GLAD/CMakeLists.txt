cmake_minimum_required(VERSION 3.10)

project(GLAD)
message("** COMPILING ${PROJECT_NAME} ** ")
include_directories(include)

add_library(GLAD STATIC src/glad.c)