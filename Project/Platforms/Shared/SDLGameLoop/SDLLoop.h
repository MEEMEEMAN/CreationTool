//
// Created by PERHAPS-MACHINE on 2/23/2021.
//

#ifndef CREATIONTOOL_SDLLOOP_H
#define CREATIONTOOL_SDLLOOP_H
#include "Core/Runtime/Events/Events.h"
#include "Core/Base.h"
#include "Core/Application.h"

namespace CT
{
    class Application;

    CT_EXPORT void CreateSDLWindow(Application& app);
    CT_EXPORT void SDLLoop(EventBus::Listener& nativeEvent, Application& app);
    CT_EXPORT void SDLShutdown();
}

#endif //CREATIONTOOL_SDLLOOP_H
