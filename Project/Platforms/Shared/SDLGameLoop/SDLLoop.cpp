//
// Created by PERHAPS-MACHINE on 2/23/2021.
//
#include <SDL.h>

#include "SDLLoop.h"
#include "Core/Base.h"
#include "Core/Application.h"
#include "SDLWindow.h"
#include "Core/Runtime/Events/StandardEvents.h"
#include "Core/Runtime/Utility/Timer.h"

#if WIN32
#include "glad/glad.h"
#endif

void LogMsg(const std::string& msg)
{
    SDL_Log("%s", msg.c_str());
}

namespace CT {

    void CreateSDLWindow(Application &app) {

        SDLWindow* sdlWnd = SDLWindow::Create();
        app.SetMainWindow(sdlWnd);

    }

    void SDLLoop(EventBus::Listener& nativeEvents, Application &app) {

        SDL_Event sdlEvent;
        auto bus = nativeEvents.getBus();

        Timer appTimer;
        while(!app.shouldQuit)
        {
            double dt = appTimer.Now();
            appTimer.Start();

            while(SDL_PollEvent(&sdlEvent) != 0)
            {
                switch (sdlEvent.type) {
                    case SDL_QUIT: //user requested to quit
                        conlog("Quit Requested!");
                        app.Shutdown();
                        break;
                }
            }

            AppStep stepEvent {};
            stepEvent.deltaTimeSeconds = dt;
            bus->postpone(stepEvent);
            bus->process();
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