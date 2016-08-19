//
//  Property.h
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#ifndef Property_h
#define Property_h

#include <string>

namespace StyleSheet
{
    class CssProperty
    {
    public:
        static const CssProperty& Empty();
        static CssProperty parse(const std::string& str);
        
        CssProperty(const std::string& name, const std::string& value);
        
        bool operator<(const CssProperty& p) const;
        const std::string& getName() const;
        const std::string& getValue() const;
        
        bool isValid() const;
        
        std::string toString() const;
    };
}

#endif /* Property_h */
