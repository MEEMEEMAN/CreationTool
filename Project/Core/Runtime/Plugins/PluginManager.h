//
// Created by PERHAPS-MACHINE on 2/25/2021.
//

#ifndef CREATIONTOOL_PLUGINMANAGER_H
#define CREATIONTOOL_PLUGINMANAGER_H
#include <vector>
#include <string>
#include "Core/Base.h"

#include "../Reflection.h"
#include "PluginInstance.h"
#include "PluginLocation.h"

//Plugins are Code.
//They can come in the form of a .dll or a .so
//They can be loaded at runtime.
//They can be statically linked.

namespace CT
{

    class PluginManager {
    public:
        //Searches for plugins EVERYWHERE
        //Checks for any statically linked plugins.
        //Checks for any plugins that reside in the executable's directory.
        static const std::vector<PluginLocation> SeekPlugins();

        //Load a plugin obtained via SeekPlugins
        static Ref<PluginInstance> LoadPlugin(PluginLocation location);

        //Unload a plugin, request the plugin to free all memory.
        static void UnloadPlugin(Ref<PluginInstance> plugin);
    };
}

#endif //CREATIONTOOL_PLUGINMANAGER_H
