//
// Created by PERHAPS-MACHINE on 2/20/2021.
//
#include <Core/Base.h>
#include <Core/Application.h>
#include <Platforms/Shared/SDLGameLoop/SDLLoop.h>
#include <SDL.h>

int main(int argc, char* argv[])
{
    CT::Application app;
    CreateSDLWindow(app);

    Ref<EventBus> eb = CreateRef<EventBus>();
    EventBus::Listener listener {eb};

    app.Initialize(listener, argc, argv);

    //enter game loop
    SDLLoop(listener, app);
    CT::SDLShutdown();

    return 0;
}