//
// Created by PERHAPS-MACHINE on 2/20/2021.
//
#include "Application.h"
#include "Base.h"

namespace CT {
    Application* Application::applicationInstance = nullptr;

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

    void Application::Step()
    {

    }

    void Application::Initialize(int argc, char **argv)
    {

    }

    void Application::Shutdown() {
        shouldQuit = true;
    }

    void Application::SetMainWindow(AppWindow *window) {
        mainWindow = window;
    }

    AppWindow *Application::GetAppWindow() {
        return mainWindow;
    }
}