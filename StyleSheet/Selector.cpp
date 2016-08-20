//
//  Selector.cpp
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
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
