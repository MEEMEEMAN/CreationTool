//
// Created by PERHAPS-MACHINE on 2/23/2021.
//
#include <SDL.h>

#include "SDLLoop.h"
#include "Core/Base.h"
#include "Core/Application.h"
#include "SDLWindow.h"

#if WIN32
#include "glad/glad.h"
#endif

void LogMsg(const char* msg)
{
    SDL_Log("%s", msg);
}

namespace CT {

    void CreateSDLWindow(Application &app) {

        SDLWindow* sdlWnd = SDLWindow::Create();
        app.SetMainWindow(sdlWnd);

    }

    void SDLLoop(Application &app) {

        SDL_Event sdlEvent;
        while(!app.shouldQuit)
        {
            while(SDL_PollEvent(&sdlEvent) != 0)
            {
                switch (sdlEvent.type) {
                    case SDL_QUIT: //user requested to quit
                        app.Shutdown();
                        break;
                }
            }
        }
    }


    void SDLShutdown()
    {
        SDL_GLContext glCtx = SDL_GL_GetCurrentContext();
        if(glCtx != nullptr)
            SDL_GL_DeleteContext(glCtx);

        SDL_Quit();
    }
}