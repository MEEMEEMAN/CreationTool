//
// Created by PERHAPS-MACHINE on 2/20/2021.
//

#ifndef CREATIONTOOL_BASE_H
#define CREATIONTOOL_BASE_H

#include <memory>

extern void LogMsg(const char* msg);
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

#include <iostream>

void __M_Assert(const char* expr_str, bool expr, const char* file, int line, const char* msg);
#ifndef NDEBUG
#   define ctassert(Expr, Msg) \
    __M_Assert(#Expr, Expr, __FILE__, __LINE__, Msg)
#else
#   define M_Assert(Expr, Msg) ;
#endif

#endif //CREATIONTOOL_BASE_H
