cmake_minimum_required(VERSION 3.10)
project(CreationTool)

# -- SETUP -- #

set(CMAKE_CXX_STANDARD 17)
set(EDITOR_TOOLS 1) #enable ImGUI Tools

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


# -- CORE -- #
#The core CreationTool Library
#Core libraries are: SDL2, rttr

include_directories(Project/)

add_subdirectory(Project/ThirdParty/SDL2)
find_library(SDL2 Project/ThirdParty/SDL2)

file(GLOB_RECURSE CoreFiles Project/Core/*.cpp)

# -- TARGET SPECIFIC -- #

if(WIN32)
    file(GLOB_RECURSE WindowsFiles Project/Platforms/Windows/*.cpp)
    add_executable(${PROJECT_NAME}
            ${WindowsFiles}
            Project/ThirdParty/GLAD/src/glad.c
            Project/Core/CreationCore.cpp
            ${CoreFiles})

    include_directories(Project/ThirdParty/GLAD/include)

    find_library(SDL2main Project/ThirdParty/SDL2)
    target_link_libraries(${PROJECT_NAME} SDL2 SDL2main)

    if(EDITOR_TOOLS)
        target_compile_definitions(${PROJECT_NAME} PRIVATE EDITOR_TOOLS=1)

        include_directories(Project/ThirdParty/ImGUI)
        add_subdirectory(Project/ThirdParty/ImGUI)
        find_library(ImGUI Project/ThirdParty/ImGUI)

        target_link_libraries(${PROJECT_NAME} ImGUI)
    endif()

elseif(ANDROID)
    add_library(main SHARED)
    target_sources(main PRIVATE
            ${CoreFiles}
            Project/Platforms/Android/main_android.cpp)

    target_link_libraries(main SDL2 GLESv3)
    elseif(EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX .js)
    message("We are using emscripten!")
endif()