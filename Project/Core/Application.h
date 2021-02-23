//
// Created by PERHAPS-MACHINE on 2/20/2021.
//

#ifndef CREATIONTOOL_APPLICATION_H
#define CREATIONTOOL_APPLICATION_H

namespace CT
{
    class AppWindow;

    class Application{
    public:
        //Called when the app first boots up.
        //A window with a valid render context should already exist.
        void Initialize(int argc, char* argv[]);
        //Called on every frame in the update loop.
        void Step();
        //Signal the app to shutdown, save any state and free resources.
        void Shutdown();

        void SetMainWindow(AppWindow* window);
        AppWindow* GetAppWindow();

        //Is the app an editor?
        static constexpr bool IsEditor();

        //Is the app ran in a mobile environment? including on WebGL
        static constexpr bool IsMobile();

        static Application* GetActiveApp();
        bool shouldQuit = false;
    private:
        static Application* applicationInstance;
        AppWindow* mainWindow = nullptr;
    };

}

#endif //CREATIONTOOL_APPLICATION_H
