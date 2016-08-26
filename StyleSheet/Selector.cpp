//
//  Selector.cpp
//  StyleSheet
//
//  MIT License
//
//  Copyright (c) 2016 Michel Donais
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//

#include "Selector.h"
#include <stdexcept>

StyleSheet::CssSelector StyleSheet::CssSelector::parse(string str)
{
    trim(str);
    if (!str.empty())
    {
        if (str[0] == '.')
        {
            return CssSelector(kClass, str.substr(1));
        }
        else if (str[0] == '#')
        {
            return CssSelector(kId, str.substr(1));
        }
    }
    return CssSelector(kType, str);
}

StyleSheet::string StyleSheet::CssSelector::toString() const
{
    if (isType())
    {
        return name;
    }
    else if (isClass())
    {
        return string(".") + name;
    }
    else // if (isId())
    {
        return string("#") + name;
    }
}

StyleSheet::CssSelector::CssSelector(Type type_, const string& name_) :
    type(type_),
    name(name_)
{
    if (name.empty())
    {
        throw std::invalid_argument("Empty selector name");
    }
}
