//
// Created by PERHAPS-MACHINE on 2/25/2021.
//

#ifndef CREATIONTOOL_EDITORPLUGIN_H
#define CREATIONTOOL_EDITORPLUGIN_H
#include "Core/Application.h"
#include "Core/Runtime/Plugins/PluginInstance.h"
#include "Core/Runtime/Serialization.h"

namespace CT
{
    class EntryPlugin
    {
    public:
        EntryPlugin()
        {
            conlog("Plugin Created!");
        }
        void Enter();
    };

    class EditorPlugin : public CT::PluginInstance {

    public:
        void OnPluginLoad() override;
        void OnPluginUnLoad() override;
    };
}

#endif //CREATIONTOOL_EDITORPLUGIN_H
