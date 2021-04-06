/*
metaprogramming_utils:
    This file is part of the MiLi Minimalistic Library.

    Copyright (C) Hugo Arregui, FuDePAN 2011
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt in the root directory or
    copy at http://www.boost.org/LICENSE_1_0.txt)

    MiLi IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
    SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
    FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

#ifndef METAPROGRAMMING_UTILS_H
#define METAPROGRAMMING_UTILS_H

#include "template_info.h"

NAMESPACE_BEGIN

template <bool COND, class T, class F>
struct Select
{
    typedef F result;
};

template <class T, class F>
struct Select<true, T, F>
{
    typedef T result;
};

template <class T>
struct ParameterType
{
    typedef template_info<T> info;
    typedef typename Select < info::is_pointer || info::is_native || info::is_reference, T, const T& >::result type;
};

NAMESPACE_END

#endif
