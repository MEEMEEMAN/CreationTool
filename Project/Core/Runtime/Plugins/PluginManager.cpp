//
// Created by PERHAPS-MACHINE on 2/25/2021.
//

#include "PluginManager.h"
#include "PluginLocation.h"

namespace CT
{
    const std::vector<PluginLocation> CT::PluginManager::SeekPlugins() {
        return std::vector<PluginLocation>();
    }

    Ref<CT::PluginInstance> CT::PluginManager::LoadPlugin(PluginLocation location) {
        return nullptr;
    }

    void CT::PluginManager::UnloadPlugin(Ref<CT::PluginInstance> plugin) {

    }
}