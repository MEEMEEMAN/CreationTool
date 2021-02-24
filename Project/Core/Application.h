//
// Created by PERHAPS-MACHINE on 2/20/2021.
//

#ifndef CREATIONTOOL_APPLICATION_H
#define CREATIONTOOL_APPLICATION_H
#include "Runtime/ScreenWindow.h"

namespace CT
{

    class Application{
    public:
        //Called when the app first boots up.
        //A window with a valid render context should already exist.
        void Initialize(int argc, char* argv[]);
        //Signal the app to shutdown, save any state and free resources.
        void Shutdown();

        void SetMainWindow(ScreenWindow* window);
        ScreenWindow* GetAppWindow();

        //Is the app an editor?
        static constexpr bool IsEditor();

        //Is the app ran in a mobile environment? including on WebGL
        static constexpr bool IsMobile();

        static Application* GetActiveApp();
        bool shouldQuit = false;
    private:
        static Application* applicationInstance;
        ScreenWindow* mainWindow = nullptr;
    };

}

#endif //CREATIONTOOL_APPLICATION_H
