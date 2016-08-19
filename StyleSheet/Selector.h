//
//  Selector.h
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#ifndef Selector_h
#define Selector_h

#include <string>

namespace StyleSheet
{
    class CssSelector
    {
    public:
        static CssSelector CssTypeSelector(const std::string& name);
        static CssSelector CssClassSelector(const std::string& name);
        static CssSelector CssIdSelector(const std::string& name);
        static CssSelector parse(const std::string& str);
        
        bool operator==(const CssSelector& other) const;
        bool operator!=(const CssSelector& other) const { return !(*this == other); }
        bool operator<(const CssSelector& other) const;
        
        const std::string& getName() const;
        bool isType() const;
        bool isClass() const;
        bool isId() const;
        
        std::string toString() const;
        
    private:
        CssSelector();
    };
    
}

#endif /* Selector_h */
