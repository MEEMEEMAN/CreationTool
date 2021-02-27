cmake_minimum_required(VERSION 3.10)
project(CreationTool)
message("** COMPILING ${PROJECT_NAME} ** ")

# -- SETUP -- #

set(CMAKE_CXX_STANDARD 17) #set cpp 17
set(EDITOR_TOOLS 1) #enable ImGUI Tools

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(Project/)
include_directories(Project/ThirdParty)

# -- CORE -- #
#The core CreationTool Library
#Core libraries are: rttr, EventBus

#cereal
include_directories(Project/ThirdParty/cereal/include)

#EventBus
add_subdirectory(Project/ThirdParty/EventBus)

#rttr
#find_package(RTTR CONFIG REQUIRED Core_Lib)

include_directories(Project/ThirdParty/rttr/src)
add_subdirectory(Project/ThirdParty/rttr)

#core library
add_subdirectory(Project/Core)

# -- TARGET SPECIFIC -- #

if (ANDROID)
    message("BUILDING FOR ANDROID")

    add_subdirectory(Project/ThirdParty/SDL2)
    add_subdirectory(Project/Platforms/Shared/SDLGameLoop)

    add_library(main SHARED)
    target_sources(main PRIVATE
            ${CoreFiles}
            Project/Platforms/Android/main_android.cpp)

    target_link_libraries(main SDL2 SDL2main GLESv3 SDL_LOOPER)
elseif (WIN32)
    message("BUILDING FOR WIN32")
    add_subdirectory(Project/ThirdParty/SDL2)

    add_subdirectory(Project/ThirdParty/GLAD)
    include_directories(Project/ThirdParty/GLAD)

    add_subdirectory(Project/Platforms/Shared/SDLGameLoop)

    file(GLOB_RECURSE WindowsFiles Project/Platforms/Windows/*.cpp)
    add_executable(${PROJECT_NAME}
            ${WindowsFiles})

    include_directories(Project/ThirdParty/GLAD/include)

    target_link_libraries(${PROJECT_NAME}
            CreationToolCore
            SDL2
            SDL2main
            CreationToolCore
            SDL_LOOPER
            GLAD)

   if (EDITOR_TOOLS)
       message("WITH TOOLS")
       add_subdirectory(Project/Platforms/Editor)
       #target_link_libraries(${PROJECT_NAME} EDITOR_TOOLING)
   endif ()

elseif (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX .js)
    message("BUILDING FOR EMSCRIPTEN")
endif ()