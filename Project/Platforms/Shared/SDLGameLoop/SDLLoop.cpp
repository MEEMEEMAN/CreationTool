//
// Created by PERHAPS-MACHINE on 2/23/2021.
//
#include <SDL.h>

#include "SDLLoop.h"
#include "Core/Base.h"
#include "Core/Application.h"

#if WIN32
#include "glad/glad.h"
#endif

void LogMsg(const char* msg)
{
    SDL_Log("%s", msg);
}

namespace CT {

    void CreateSDLWindow(Application &app) {

        if(SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            conlog("Failed to init SDL!");
        }


    }

    void SDLLoop(Application &app) {

    }

}