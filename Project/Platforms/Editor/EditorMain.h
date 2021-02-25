//
// Created by PERHAPS-MACHINE on 2/25/2021.
//

#ifndef CREATIONTOOL_EDITORMAIN_H
#define CREATIONTOOL_EDITORMAIN_H
#include "Core/Runtime/Plugins/PluginInstance.h"

namespace CT
{
    class EditorMain : public PluginInstance {
        RTTR_ENABLE(PluginInstance)

    public:
        void OnPluginLoad() override;
        void OnPluginUnLoad() override;
    };
}

#endif //CREATIONTOOL_EDITORMAIN_H
