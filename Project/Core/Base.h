//
// Created by PERHAPS-MACHINE on 2/20/2021.
//

#ifndef CREATIONTOOL_BASE_H
#define CREATIONTOOL_BASE_H

#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#if WIN32
#define CT_EXPORT extern "C" __declspec(dllexport)
#define CT_CALL
#elif ANDROID
#include <jni.h>
#define CT_EXPORT JNIEXPORT
#define CT_CALL JNICALL
#endif

//The runtime loop should implement this function.
CT_EXPORT void LogMsg(const std::string& msg);

//Cross platform console logging.
#define conlog(x) LogMsg(x);


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

void __M_Assert(const char* expr_str, bool expr, const char* file, int line, const char* msg);
#ifndef NDEBUG
#   define ctassert(Expr, Msg) \
    __M_Assert(#Expr, Expr, __FILE__, __LINE__, Msg)
#else
#   define ctassert(Expr, Msg) Expr;
#endif

#endif //CREATIONTOOL_BASE_H
