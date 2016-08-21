//
//  Property.h
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#ifndef Property_h
#define Property_h

#include "StyleSheetGlobals.h"

namespace StyleSheet
{
    class CssProperty
    {
    public:
        static const CssProperty& Empty();
        static CssProperty parse(const string& str);
        
        CssProperty(const string& _name, const string& _value) :
            name(_name),
            value(_value)
        {
        }
        
        bool operator<(const CssProperty& p) const
        {
            return name < p.name;
        }
        
        const string& getName() const
        {
            return name;
        }
        const string& getValue() const
        {
            return value;
        }
        
        bool isValid() const
        {
            return !name.empty();
        }
        
        string toString() const;
        
    private:
        string name;
        string value;
    };
}

#endif /* Property_h */
