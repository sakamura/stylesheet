//
//  Selector.h
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#ifndef Selector_h
#define Selector_h

#include "StyleSheetGlobals.h"

namespace StyleSheet
{
    class CssSelector
    {
    public:
        enum Type
        {
            kType,
            kClass,
            kId
        };
        
        static CssSelector CssTypeSelector(const string& name)
        {
            return CssSelector(kType, name);
        }
        static CssSelector CssClassSelector(const string& name)
        {
            return CssSelector(kClass, name);
        }
        static CssSelector CssIdSelector(const string& name)
        {
            return CssSelector(kId, name);
        }
        static CssSelector parse(string str);
        
        bool operator==(const CssSelector& other) const
        {
            return type == other.type && name == other.name;
        }
        bool operator!=(const CssSelector& other) const
        {
            return !(operator==(other));
        }
        bool operator<(const CssSelector& other) const
        {
            return type < other.type || (type == other.type && name < other.name);
        }
        
        const Type& getType() const
        {
            return type;
        }
        const string& getName() const
        {
            return name;
        }
        bool isType() const
        {
            return type == kType;
        }
        bool isClass() const
        {
            return type == kClass;
        }
        bool isId() const
        {
            return type == kId;
        }
        
        string toString() const;
                
    private:
        CssSelector(Type type, const string& name);
        
        Type type;
        string name;
    };
}


namespace std
{
    template<>
    struct hash<StyleSheet::CssSelector>
    {
        std::size_t operator()(const StyleSheet::CssSelector& k) const
        {
            return
                StyleSheet::rotl(std::hash<int>()((int)k.getType()),1) ^
                std::hash<std::string>()(k.getName());
        }
    };
}

#endif /* Selector_h */
