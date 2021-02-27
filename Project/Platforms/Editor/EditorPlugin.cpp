//
// Created by PERHAPS-MACHINE on 2/25/2021.
//

#include "EditorPlugin.h"

RTTR_PLUGIN_REGISTRATION
{
    using namespace CT;
    registration::class_<EditorPlugin>("EnterPlugin").constructor<>();
};

namespace CT
{
    void EditorPlugin::OnPluginLoad() {
        //conlog("Loaded Editor Plugin!!!");
    }

    void EditorPlugin::OnPluginUnLoad() {
        //conlog("UnLoaded Editor Plugin.");
    }

    void EntryPlugin::Enter() {
        conlog("HAHAHA");
    }
}