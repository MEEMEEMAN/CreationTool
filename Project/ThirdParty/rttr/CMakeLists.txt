cmake_minimum_required(VERSION 3.10)

project(rttr)
set(CMAKE_CXX_STANDARD 17) #set cpp 17

file(GLOB_RECURSE RTTR_SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")
add_library(rttr STATIC ${RTTR_SOURCES})