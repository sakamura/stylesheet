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
        
        bool operator== (const CssElement& r) const
        {
            return getSelector() == r.getSelector();
        }
    private:
        CssSelector selector;
        CssPropertySet properties;
    };
}

namespace std
{
    template<>
    struct hash<StyleSheet::CssElement>
    {
        std::size_t operator()(const StyleSheet::CssElement& k) const
        {
            return std::hash<StyleSheet::CssSelector>()(k.getSelector());
        }
    };
}

#endif /* Element_h */
