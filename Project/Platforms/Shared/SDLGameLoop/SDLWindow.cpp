//
// Created by PERHAPS-MACHINE on 2/23/2021.
//

#include "SDLWindow.h"
#include "SDL.h"

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
