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
        
        CssProperty(const string& name, const string& value);
        
        bool operator<(const CssProperty& p) const;
        const string& getName() const;
        const string& getValue() const;
        
        bool isValid() const;
        
        string toString() const;
    };
}

#endif /* Property_h */
