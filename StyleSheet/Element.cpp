//
//  Element.cpp
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#include "Element.h"
#include <stdexcept>

StyleSheet::CssElement StyleSheet::CssElement::parse(const string& str)
{
    string selector, properties;
    if (parametrizer(str, '{', '}', selector, properties))
    {
        return CssElement(CssSelector::parse(selector), CssPropertySet::parse(properties));
    }
    else
    {
        throw std::invalid_argument("No {}");
    }
}

StyleSheet::string StyleSheet::CssElement::toString() const
{
    return selector.toString() + " {" + properties.toString() + "}";
}
