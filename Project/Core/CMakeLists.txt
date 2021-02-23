cmake_minimum_required(VERSION 3.10)

Project(CreationToolCore)
message("** COMPILING ${PROJECT_NAME} ** ")

file(GLOB_RECURSE CoreSources "${PROJECT_SOURCE_DIR}/*.cpp")

add_library(CreationToolCore STATIC ${CoreSources})