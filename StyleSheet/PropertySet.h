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
#include <map>

namespace StyleSheet
{
    class CssPropertySet : protected std::map<string, CssProperty>
    {
        typedef typename std::map<string, CssProperty> Super;
        
    public:
        static CssPropertySet parse(const string& str);
        
        void add(const CssProperty& prop)
        {
            if (prop.isValid())
            {
                insert(std::make_pair(prop.getName(), prop));
            }
        }
        void add(const CssPropertySet& propSet)
        {
            insert(propSet.begin(), propSet.end());
        }
        
        void remove(const string& propName)
        {
            erase(propName);
        }
        void remove(const CssProperty& prop)
        {
            remove(prop.getName());
        }

        size_t size() const
        {
            return Super::size();
        }
        bool empty() const
        {
            return Super::empty();
        }
        
        const CssProperty& getProperty(const string& name) const
        {
            const_iterator iter = find(name);
            if (iter == end())
            {
                return CssProperty::Empty();
            }
            else
            {
                return iter->second;
            }
        }
        
        string toString() const;
    };
}

#endif /* PropertySet_h */
