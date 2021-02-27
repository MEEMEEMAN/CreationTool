//
// Created by PERHAPS-MACHINE on 2/23/2021.
//

#include "SDLWindow.h"
#include "SDL.h"
#include "Core/Base.h"
#include <sstream>

#if WIN32
#include <glad/glad.h>
#elif ANDROID
#include <GLES3/gl3.h>
#endif

void CT::SDLWindow::SwapBuffers() {
    SDL_GL_SwapWindow(sdlWindow);
}

CT::ScreenWindowInfo CT::SDLWindow::GetInfo() {
    int width, height;
    SDL_GetWindowSize(sdlWindow, &width, &height);

    ScreenWindowInfo info;
    info.width = width;
    info.height = height;

    return info;
}

void InitSDL() {
    ctassert(SDL_Init(SDL_INIT_VIDEO) >= 0, "SDL has failed to init");

    int major, minor, profile;

#if WIN32 //OpenGL 4.3 Core
    major = 4;
    minor = 3;
    profile = SDL_GL_CONTEXT_PROFILE_CORE;

#elif ANDROID //OpenGL ES 3.1
    major = 3;
    minor = 1;
    profile = SDL_GL_CONTEXT_PROFILE_ES;
#endif

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, profile);
}

bool sdlInit = false;
bool glInit = false;

CT::SDLWindow *CT::SDLWindow::Create() {

    if (!sdlInit) {
        InitSDL();
        sdlInit = true;
    }

    SDLWindow *wnd = new SDLWindow();
    wnd->sdlWindow = SDL_CreateWindow("CreationTool",
                                      SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOWPOS_CENTERED,
                                      1280,
                                      720,
                                      SDL_RENDERER_ACCELERATED);

    SDL_GL_CreateContext(wnd->sdlWindow);

    if (!glInit) //load OpenGL functions if needed
    {
#if WIN32
        ctassert(gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress), "Glad has failed to init.");
#elif ANDROID
        //functions are statically linked.
#endif

        glInit = true;
    }

    std::stringstream ss;
    ss << glGetString(GL_VERSION) << ", Device: " << glGetString(GL_RENDERER);
    conlog(ss.str().c_str());

    return wnd;
}

void CT::SDLWindow::Destroy(CT::SDLWindow *window) {
    SDL_DestroyWindow(window->sdlWindow);
    delete (window);
}
