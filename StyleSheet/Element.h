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
    public:
        static CssElement parse(const string& str);
        
        CssElement(const CssSelector& selector_, const CssPropertySet& properties_) :
            selector(selector_),
            properties(properties_)
        {
        }
        
        bool operator<(const CssElement& e) const
        {
            return selector < e.selector;
        }
        
        const CssSelector& getSelector() const
        {
            return selector;
        }
        size_t getPropertyCount() const
        {
            return properties.size();
        }
        const CssPropertySet& getProperties() const
        {
            return properties;
        }
        
        void addProperty(const CssProperty& prop)
        {
            properties.add(prop);
        }
        
        string toString() const;
        
    private:
        CssSelector selector;
        CssPropertySet properties;
    };
}

#endif /* Element_h */
