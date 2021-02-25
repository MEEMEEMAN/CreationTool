//
// Created by PERHAPS-MACHINE on 2/25/2021.
//

#ifndef CREATIONTOOL_PLUGININSTANCE_H
#define CREATIONTOOL_PLUGININSTANCE_H
#include "PluginLocation.h"
#include "../Reflection.h"

namespace CT
{
    class PluginInstance {
    RTTR_ENABLE()

    public:

        PluginInstance(PluginLocation location)
        {
            _location = location;
        }

        virtual void OnPluginLoad();
        virtual void OnPluginUnLoad();
        const PluginLocation& GetLoadLocation();

    private:
        PluginLocation _location;
    };
}

#endif //CREATIONTOOL_PLUGININSTANCE_H
