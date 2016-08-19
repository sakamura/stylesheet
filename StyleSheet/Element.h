//
//  Element.h
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#ifndef Element_h
#define Element_h

#include "Selector.h"
#include "PropertySet.h"
#include <set>

namespace StyleSheet
{
    class CssElement
    {
        static CssElement parse(const std::string& str);
        
        CssElement(const CssSelector& selector, const CssPropertySet& properties);
        
        bool operator<(const CssElement& e) const;
        
        const CssSelector& getSelector() const;
        std::size_t getPropertyCount() const;
        const CssPropertySet& getProperties() const;
        
        void addProperty(const CssProperty& prop);
        
        std::string toString() const;
    };
}

#endif /* Element_h */
