//
//  PropertySet.cpp
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#include "PropertySet.h"

StyleSheet::CssPropertySet StyleSheet::CssPropertySet::parse(const string& str)
{
    CssPropertySet set;
    
    tokenizer(str, ';', [&set](const string& str)
              {
                  set.add(CssProperty::parse(str));
              });
    
    return set;
}

StyleSheet::string StyleSheet::CssPropertySet::toString() const
{
    std::string str;
    for (auto it = begin(); it != end(); ++it)
    {
        if (!str.empty())
        {
            str += " ";
        }
        str += it->second.toString();
    }
    return str;
}
