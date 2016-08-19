//
//  PropertySet.h
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#ifndef PropertySet_h
#define PropertySet_h

#include "Property.h"
#include <set>

namespace StyleSheet
{
    class CssPropertySet
    {
        static CssPropertySet parse(const std::string& str);
        
        void add(const CssProperty& prop);
        void add(const CssPropertySet& propSet);
        void remove(const std::string&);

        std::size_t size() const;
        bool empty() const;
        
        const CssProperty& getProperty(const std::string& name) const;
        
        std::string toString() const;
    };
}

#endif /* PropertySet_h */
