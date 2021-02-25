//
// Created by PERHAPS-MACHINE on 2/25/2021.
//

#include "PluginInstance.h"
#include "PluginManager.h"

RTTR_REGISTRATION
{
    registration::class_<CT::PluginInstance>("PluginInstance")
            .method("OnPluginLoad", &CT::PluginInstance::OnPluginLoad)
            .method("OnPluginUnLoad", &CT::PluginInstance::OnPluginUnLoad);
};

void CT::PluginInstance::OnPluginLoad() {

}

void CT::PluginInstance::OnPluginUnLoad() {

}

const CT::PluginLocation &CT::PluginInstance::GetLoadLocation() {
    return _location;
}
