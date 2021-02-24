//
// Created by PERHAPS-MACHINE on 2/20/2021.
//
#include "Application.h"
#include "Base.h"
#include "Runtime/ScreenWindow.h"
#include  "Runtime/Events.h"

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

    struct FooEvent {
        int x, y, z;
    };

    void Application::Initialize(int argc, char **argv) {
        auto bus = std::make_shared<EventBus>();

        EventBus::Listener listener {bus};
        listener.listen([](const std::string &event) {
            conlog(event.c_str());
        });

        FooEvent f{};
        bus->postpone(f);
        bus->postpone(std::string("heya"));
        bus->postpone(f);

        bus->process();
        //app wide init code
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