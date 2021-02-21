cmake_minimum_required(VERSION 3.10)

project(GAME)

# armeabi-v7a requires cpufeatures library
# include(AndroidNdkModules)
# android_ndk_import_module_cpufeatures()

#cpp 17
set(CMAKE_CXX_STANDARD 17)

# SDL sources are in a subfolder named "SDL"
#add_subdirectory(CreationTool/Project/ThirdParty/SDL2)

# Compilation of companion libraries
#add_subdirectory(SDL_image)
#add_subdirectory(SDL_mixer)
#add_subdirectory(SDL_ttf)

# Your game and its CMakeLists.txt are in a subfolder named "src"
add_subdirectory(CreationTool)

