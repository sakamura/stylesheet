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

namespace StyleSheet
{
    class CssElement
    {
        static CssElement parse(const string& str);
        
        CssElement(const CssSelector& selector, const CssPropertySet& properties);
        
        bool operator<(const CssElement& e) const;
        
        const CssSelector& getSelector() const;
        size_t getPropertyCount() const;
        const CssPropertySet& getProperties() const;
        
        void addProperty(const CssProperty& prop);
        
        string toString() const;
    };
}

#endif /* Element_h */
