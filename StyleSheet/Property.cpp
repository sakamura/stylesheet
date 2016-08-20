//
//  Property.cpp
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#include "Property.h"

const StyleSheet::CssProperty& StyleSheet::CssProperty::Empty()
{
    static const CssProperty empty("", "");
    return empty;
}

StyleSheet::CssProperty StyleSheet::CssProperty::parse(const string& str)
{
    string name, value;
    if (parametrizer(str, ':', ';', name, value))
    {
        return CssProperty(name, value);
    }
    else
    {
        return Empty();
    }
}

StyleSheet::string StyleSheet::CssProperty::toString() const
{
    return name + ": " + value + ";";
}
