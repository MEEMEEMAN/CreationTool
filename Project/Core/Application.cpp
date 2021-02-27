//
// Created by PERHAPS-MACHINE on 2/20/2021.
//
#include "Application.h"
#include "Core/Base.h"
#include "Runtime/Events/StandardEvents.h"
#include "Runtime/Plugins/PluginManager.h"

class Tee
{
public:
    Tee()
    {
        conlog("Tee: Created!");
    }

};

RTTR_REGISTRATION
{
    registration::class_<Foo>("Foo");
};

namespace CT {
    Application *Application::applicationInstance = nullptr;

    bool Application::IsMobile() {
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

    void OnAppUpdate(const AppStep &step) {

    }

    void Application::Initialize(EventBus::Listener &nativeEvents, int argc, char **argv) {
        nativeEvents.listen(&OnAppUpdate);

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