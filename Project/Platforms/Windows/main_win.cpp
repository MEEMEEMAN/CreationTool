//
// Created by PERHAPS-MACHINE on 2/20/2021.
//

#include <Core/Base.h>
#include <Core/Application.h>
#include <Platforms/Shared/SDLGameLoop/SDLLoop.h>

int main(int argc, char* argv[])
{
    CT::Application app;
    CreateSDLWindow(app);
    app.Initialize(argc, argv);

    //enter game loop
    SDLLoop(app);

    return 0;
}