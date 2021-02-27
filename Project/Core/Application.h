//
// Created by PERHAPS-MACHINE on 2/20/2021.
//

#ifndef CREATIONTOOL_APPLICATION_H
#define CREATIONTOOL_APPLICATION_H
#include "Runtime/ScreenWindow.h"
#include "Runtime/Events/Events.h"
#include "Core/Base.h"
#include "Core/Runtime/Serialization.h"
#include "Runtime/Reflection.h"

class Foo
{

public:
    Foo(int x) {conlog(std::to_string(x).c_str());}
};

class Bar : public Foo
{

};
class Jar : public Foo
{

};

namespace CT
{

    class Application{
    public:
        //Called when the app first boots up.
        //A window with a valid render context should already exist.
        //The app will listen to all standard events in Runtime/Events/StandardEvents.h
        void Initialize(EventBus::Listener& nativeEvents, int argc, char* argv[]);

        //Signal the app to shutdown, save any state and free resources.
        void Shutdown();

        void SetMainWindow(ScreenWindow* window);
        ScreenWindow* GetAppWindow();

        //Is the app an editor?
        static constexpr bool IsEditor();

        //Is the app ran in a mobile environment? including on WebGL
        static bool IsMobile();

        static Application* GetActiveApp();
        bool shouldQuit = false;
    private:
        static Application* applicationInstance;
        ScreenWindow* mainWindow = nullptr;
    };

}

#endif //CREATIONTOOL_APPLICATION_H
