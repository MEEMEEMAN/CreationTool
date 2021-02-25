//
// Created by PERHAPS-MACHINE on 2/20/2021.
//
#include "Application.h"
#include "Base.h"
#include "Runtime/ScreenWindow.h"
#include  "Runtime/Events.h"


#include "Runtime/Reflection.h"
#include "Runtime/Plugins/PluginInstance.h"

#include "Platforms/Editor/EditorMain.h"

class Foo
{
    RTTR_ENABLE()
};

class Bar : public Foo
{
    RTTR_ENABLE(Foo)
};

RTTR_REGISTRATION
{
    registration::class_<Foo>("Foo");
    registration::class_<Bar>("Bar");
};

namespace CT {
    Application *Application::applicationInstance = nullptr;

    constexpr bool Application::IsMobile() {
#ifdef WIN32
        return false;
#else
        return true;
#endif
    }

    constexpr bool Application::IsEditor() {
#ifdef EDITOR_TOOLS
        return true;
#endif
        return false;
    }

    Application *Application::GetActiveApp() {
        return Application::applicationInstance;
    }


    void Application::Initialize(int argc, char **argv) {

    }

    void Application::Shutdown() {
        shouldQuit = true;
    }

    ScreenWindow *Application::GetAppWindow() {
        return mainWindow;
    }

    void Application::SetMainWindow(ScreenWindow *window) {
        mainWindow = window;
    }
}