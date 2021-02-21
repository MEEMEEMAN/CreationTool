//
// Created by PERHAPS-MACHINE on 2/20/2021.
//

#ifndef CREATIONTOOL_APPLICATION_H
#define CREATIONTOOL_APPLICATION_H

class SDL_Window;

namespace CT
{
    class Application{
    public:
        void Initialize(int argc, char* argv[]);
        void Stop();

        static constexpr bool IsEditor();
        static constexpr bool IsMobile();

    private:
        SDL_Window* mainWindow = nullptr;
        bool shouldQuit = false;
    };
}

#endif //CREATIONTOOL_APPLICATION_H
