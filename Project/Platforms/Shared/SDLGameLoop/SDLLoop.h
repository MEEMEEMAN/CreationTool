//
// Created by PERHAPS-MACHINE on 2/23/2021.
//

#ifndef CREATIONTOOL_SDLLOOP_H
#define CREATIONTOOL_SDLLOOP_H

namespace CT
{
    class Application;

    void CreateSDLWindow(Application& app);
    void SDLLoop(Application& app);
    void SDLShutdown();
}

#endif //CREATIONTOOL_SDLLOOP_H
