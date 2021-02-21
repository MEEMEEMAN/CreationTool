//
// Created by PERHAPS-MACHINE on 2/20/2021.
//

#ifndef CREATIONTOOL_CREATIONCORE_H
#define CREATIONTOOL_CREATIONCORE_H

#include <memory>

void LogFunction(const char* msg);
#define conlog(x) LogFunction(x);


template<typename T>
using Scope = std::unique_ptr<T>;
template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

enum ExitCodes
{
        SDL_CONTEXT_FAIL_INIT = -10,
        SDL_WINDOW_FAIL_CREATE = -11,
        GL_GRAPHICS_FAIL_INIT =  -12
};

#endif //CREATIONTOOL_CREATIONCORE_H
