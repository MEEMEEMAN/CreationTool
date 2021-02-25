//
// Created by PERHAPS-MACHINE on 2/25/2021.
//

#include "EditorMain.h"
#include "Core/Base.h"
#include "Core/Runtime/Plugins/PluginManager.h"

RTTR_REGISTRATION
{
    registration::class_<CT::EditorMain>("EditorMain");
};

namespace CT
{
    void EditorMain::OnPluginLoad() {
        conlog("Loaded Editor Plugin!!!");
    }

    void EditorMain::OnPluginUnLoad() {
        conlog("UnLoaded Editor Plugin.");
    }
}


