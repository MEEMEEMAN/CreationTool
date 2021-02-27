//
// Created by PERHAPS-MACHINE on 2/25/2021.
//

#ifndef CREATIONTOOL_PLUGININSTANCE_H
#define CREATIONTOOL_PLUGININSTANCE_H
#include "PluginLocation.h"
#include "../Reflection.h"
#include "Core/Base.h"

namespace CT
{
    class PluginInstance {

    public:
        PluginInstance() { };//conlog("Da!"); };

        virtual void OnPluginLoad();
        virtual void OnPluginUnLoad();
        const PluginLocation& GetLoadLocation();

        PluginLocation _location;
    };
}

#endif //CREATIONTOOL_PLUGININSTANCE_H
