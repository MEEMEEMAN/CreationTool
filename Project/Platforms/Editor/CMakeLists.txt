cmake_minimum_required(VERSION 3.10)

project(EDITOR_TOOLS)

file(GLOB_RECURSE Editor_Src "./*.cpp")
add_library(EDITOR_TOOLS ${Editor_Src})
target_link_libraries(EDITOR_TOOLS CreationToolCore)