cmake_minimum_required(VERSION 3.17)

project(rttr)

file(GLOB_RECURSE RTTR_SRC "${PROJECT_SOURCE_DIR}/*.cpp")
add_library(rttr STATIC ${RTTR_SRC})