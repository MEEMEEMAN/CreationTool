cmake_minimum_required(VERSION 3.10)
project(CreationTool)
message("** COMPILING ${PROJECT_NAME} ** ")

# -- SETUP -- #

set(CMAKE_CXX_STANDARD 17) #set cpp 17
set(EDITOR_TOOLS 1) #enable ImGUI Tools

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# -- CORE -- #
#The core CreationTool Library
#Core libraries are: rttr, EventBus

include_directories(Project/)

add_subdirectory(Project/ThirdParty/EventBus)

include_directories(Project/ThirdParty)
add_subdirectory(Project/ThirdParty/rttr)

add_subdirectory(Project/Core)
find_library(CreationToolCore Project/Core)

include_directories(Project/)


#file(GLOB_RECURSE CoreFiles Project/Core/*.cpp)

# -- TARGET SPECIFIC -- #

if (WIN32)
    add_subdirectory(Project/ThirdParty/SDL2)
    find_library(SDL2 Project/ThirdParty/SDL2)

    add_subdirectory(Project/ThirdParty/GLAD)
    include_directories(Project/ThirdParty/GLAD)
    find_library(GLAD Project/ThirdParty/GLAD)

    add_subdirectory(Project/Platforms/Shared/SDLGameLoop)

    file(GLOB_RECURSE WindowsFiles Project/Platforms/Windows/*.cpp)
    add_executable(${PROJECT_NAME}
            ${WindowsFiles} Project/Platforms/Editor/EditorMain.cpp Project/Platforms/Editor/EditorMain.h)

    include_directories(Project/ThirdParty/GLAD/include)

    find_library(SDL2main Project/ThirdParty/SDL2)
    target_link_libraries(${PROJECT_NAME}
            CreationToolCore
            SDL2
            SDL2main
            CreationToolCore
            SDL_LOOPER
            GLAD)

    if (EDITOR_TOOLS)
        add_subdirectory(Project/Platforms/Editor)
        target_link_libraries(${PROJECT_NAME} EDITOR_TOOLS)
    endif ()

elseif (ANDROID)
    add_subdirectory(Project/ThirdParty/SDL2)
    find_library(SDL2 Project/ThirdParty/SDL2)

    add_library(main SHARED)
    target_sources(main PRIVATE
            ${CoreFiles}
            Project/Platforms/Android/main_android.cpp)

    target_link_libraries(main SDL2 GLESv3)
elseif (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX .js)
    message("We are using emscripten!")
endif ()