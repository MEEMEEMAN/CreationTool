//
// Created by PERHAPS-MACHINE on 2/25/2021.
//

#ifndef CREATIONTOOL_PLUGINLOCATION_H
#define CREATIONTOOL_PLUGINLOCATION_H
#include <string>

namespace CT
{
    enum class PluginLocationEndpoint { STATIC_LINK, FILE };

    struct PluginLocation {
        PluginLocationEndpoint endPointType;
        std::string uri;
    };
}


#endif //CREATIONTOOL_PLUGINLOCATION_H
